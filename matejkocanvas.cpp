#include "matejkocanvas.h"

#include <QtGui>
#include <QApplication>
#include "pnsglobal.h"
#include "editelementdialog.h"

MatejkoCanvas::MatejkoCanvas(QWidget *parent) : QWidget(parent), _selectedElement(0), _simulationModeOn(false), _savedTokens(0) {
    this->setupPalette();

    // Context menu
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
}

void MatejkoCanvas::clear(){
    this->selectElement(0);
}

void MatejkoCanvas::showContextMenu(const QPoint &position) {
    if (_simulationModeOn){
        return;
    }

    QMenu contextMenu("Context menu", this);

    QAction addPlaceAction(this);
    addPlaceAction.setText("Add place");
    contextMenu.addAction(&addPlaceAction);

    QAction addTransitionAction(this);
    addTransitionAction.setText("Add transition");
    contextMenu.addAction(&addTransitionAction);

    QMap<QString, QVariant> placeInfo;
    placeInfo["Type"] = QVariant(AddPlace);
    placeInfo["Position"] = QVariant(position);
    addPlaceAction.setData(placeInfo);

    QMap<QString, QVariant> transitionInfo;
    transitionInfo["Type"] = QVariant(AddTransition);
    transitionInfo["Position"] = QVariant(position);
    addTransitionAction.setData(transitionInfo);

    connect(&contextMenu, SIGNAL(triggered(QAction *)),
            this, SLOT(contextActionTriggered(QAction *)));

    contextMenu.exec(this->mapToGlobal(position));
}

void MatejkoCanvas::contextActionTriggered(QAction *action) {
    QMap<QString, QVariant> actionInfo = action->data().toMap();
    QPoint position = actionInfo["Position"].toPoint();
    ContextActionType actionType = (ContextActionType)actionInfo["Type"].toInt();

    if (actionType == AddPlace) {
        Element *newPlace = new Place(position, 0, this);
        QPoint centeredPosition(position.x() - newPlace->width()/2, position.y() - newPlace->height()/2);
        newPlace->move(centeredPosition);
        this->places->append(newPlace);
    }
    else if (actionType == AddTransition) {
        Element *newTransition = new Transition(position, this);
        QPoint centeredPosition(position.x() - newTransition->width()/2, position.y() - newTransition->height()/2);
        newTransition->move(centeredPosition);
        this->transitions->append(newTransition);
    }
}

void MatejkoCanvas::onRemoveElementRequested() {
    Element *elementToRemove = qobject_cast<Element*>(QObject::sender());
    QList<Element *> *elements;
    if (qobject_cast<Place *>(elementToRemove)) {
        elements = this->places;
    }
    else {
        elements = this->transitions;
    }
    int index = elements->indexOf(elementToRemove);
    elements->removeAt(index);

    // Update numbering
    for (int i = index; i < elements->count(); ++i) {
        Element *elementToUpdate = (*elements)[i];
        elementToUpdate->setNumber(i+1);
    }

    this->removeRelatedArrows(elementToRemove);
    this->update();

    elementToRemove->deleteLater();
}

void MatejkoCanvas::onModifyElementRequested() {
    Element *elementToModify = qobject_cast<Element *>(QObject::sender());
    Place *placeToModify = qobject_cast<Place *>(elementToModify);
    Transition *TransitionToModify = qobject_cast<Transition *>(elementToModify);
    // TODO: Edytowanie elementu

    EditElementDialog *dialog = new EditElementDialog(this);
    connect(dialog, SIGNAL(descriptionChanged(QString)), elementToModify, SLOT(setDescription(QString)));
    dialog->setDescription(elementToModify->description());

    if (placeToModify){
        dialog->setEditView(EditElementDialog::EditPlace);
        dialog->setTokenCount(placeToModify->tokenCount());
        connect(dialog, SIGNAL(tokenChanged(int)), placeToModify, SLOT(setTokenCount(int)));
    }
    else if (TransitionToModify){
        dialog->setEditView(EditElementDialog::EditTransition);
    }

    dialog->show();
}

void MatejkoCanvas::onElementClicked() {
    Element *element = qobject_cast<Element *>(this->sender());
    this->selectElement(element);
}

void MatejkoCanvas::onSelectedElementDestroyed() {
    this->setSelectedElement(0);
}

void MatejkoCanvas::mousePressEvent(QMouseEvent *event)
{
    event->accept();
}

void MatejkoCanvas::mouseMoveEvent(QMouseEvent *event)
{
    event->accept();
}
bool MatejkoCanvas::simulationModeOn() const
{
    return _simulationModeOn;
}

void MatejkoCanvas::setSimulationModeOn(bool simulationModeOn)
{
    if  (_simulationModeOn != simulationModeOn){
        _simulationModeOn = simulationModeOn;
        this->setSelectedElement(0);
        emit simulationModeOnChanged(_simulationModeOn);
    }
}

void MatejkoCanvas::saveBoardState()
{
    if (_savedTokens){
        delete[] _savedTokens;
    }

    int size = this->places->count();
    _savedTokens = new int[size];

    for (int i = 0; i < size; ++i){
        _savedTokens[i] = ((Place *)(*(this->places))[i])->tokenCount();
    }
}

void MatejkoCanvas::restoreBoardState()
{
    for (int i = 0; i < this->places->count(); ++i){
        ((Place *)(*(this->places))[i])->setTokenCount(_savedTokens[i]);
    }

    delete[] _savedTokens;
    _savedTokens = NULL;
}

void MatejkoCanvas::mouseReleaseEvent(QMouseEvent *event) {
    this->selectElement(0);
}

void MatejkoCanvas::selectElement(Element *element) {
    if (!element){
        this->setSelectedElement(0);
        return;
    }

    // If there is no selected element, just select one
    if (!this->selectedElement()) {
        this->setSelectedElement(element);
        return;
    }
    else if (_simulationModeOn){
        this->setSelectedElement(element);
        return;
    }
    // Else try to build an arrow and clear selection
    else {
        if (qobject_cast<Place*>(this->selectedElement())){
            if (qobject_cast<Transition *>(element) && !_simulationModeOn){
                this->buildArrow(this->selectedElement(), element, true);
            }
        }
        else if (qobject_cast<Transition*>(this->selectedElement())){
            if (qobject_cast<Place *>(element) && !_simulationModeOn){
                this->buildArrow(element, this->selectedElement(), false);
            }
        }
        this->setSelectedElement(0);
    }
}

void MatejkoCanvas::setSelectedElement(Element *element) {
    if (_selectedElement) {
        _selectedElement->setSelected(false);
    }
    if (element) {
        element->setSelected(true);
    }
    _selectedElement = element;
}

Element * MatejkoCanvas::selectedElement() {
    return _selectedElement;
}

int MatejkoCanvas::removeRelatedArrows(Element *element)
{
    if (!element){
        return -1;
    }

    QList<int> indicesToRemove;

    for (int i = 0; i < this->arrows->count(); ++i){
        Arrow *arrow = this->arrows->at(i);
        if (arrow->place == element || arrow->transition == element){
            indicesToRemove.append(i);
        }
    }

    for (int i = indicesToRemove.count()-1; i >= 0; --i) {
        Arrow *arrow = this->arrows->takeAt(indicesToRemove[i]);
        delete arrow;
    }

    return indicesToRemove.count();
}

void MatejkoCanvas::setupPalette() {
    QPalette palette(QApplication::palette());
    palette.setColor(backgroundRole(), Qt::gray);
    this->setPalette(palette);
}

bool MatejkoCanvas::arrowConnectionExists(Element *place, Element *transition) const {

    for (int i = 0; i < this->arrows->size(); ++i){
        Arrow *existingArrow = this->arrows->at(i);
        if (existingArrow->place == place && existingArrow->transition == transition){
            return true;
        }
    }
    return false;
}

bool MatejkoCanvas::buildArrow(Element *place, Element *transition, bool fromPlaceToTransition)
{
    if (arrowConnectionExists(place, transition)){
        return false;
    }

    Arrow *newArrow = new Arrow(place, transition, fromPlaceToTransition);
    arrows->append(newArrow);
    this->update();
    return true;
}

void MatejkoCanvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::black);

    for (Arrow *arrow: *(this->arrows)) {
        arrow->draw(painter);
    }
}
