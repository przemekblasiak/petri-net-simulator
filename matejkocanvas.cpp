#include "matejkocanvas.h"

#include <QtGui>
#include <QApplication>
#include <QList>
#include <QDebug>
#include <QMenu>
#include <QIcon>

MatejkoCanvas::MatejkoCanvas(QWidget *parent) : QWidget(parent), selectedElement(0) {
    this->setupPalette();

    // Context menu
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
}

void MatejkoCanvas::showContextMenu(const QPoint &position) {
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
        this->places->append(newPlace);
    }
    else if (actionType == AddTransition) {
        Element *newTransition = new Transition(position, this);
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

    elementToRemove->deleteLater();
}

void MatejkoCanvas::onModifyElementRequested() {
    Element *elementToModify = qobject_cast<Element *>(QObject::sender());
    // TODO: Edytowanie elementu
}

void MatejkoCanvas::mousePressEvent(QMouseEvent *event) {
    event->accept();
}

void MatejkoCanvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QObject *object = childAt(event->pos());
        Element *element= qobject_cast<Element *>(object);
        if (element){
            this->selectElement(element);
        }
    }
    else if (event->button() == Qt::RightButton){
    }

    event->accept();
}

void MatejkoCanvas::selectElement(Element *) {

}

void MatejkoCanvas::setupPalette() {
    QPalette palette(QApplication::palette());
    palette.setColor(backgroundRole(), Qt::gray);
    this->setPalette(palette);
}

bool MatejkoCanvas::arrowConnectionExists(Arrow *arrow) const {

    for (int i = 0; i < this->arrows->size(); ++i){
        Arrow *existingArrow = this->arrows->at(i);
        if (existingArrow->place == arrow->place && existingArrow->transition == arrow->transition){
            return true;
        }
    }
    return false;
}

bool MatejkoCanvas::buildArrow(Arrow *arrow)
{
    if (arrowConnectionExists(arrow)){
        return false;
    }

    Arrow *newArror = new Arrow(arrow);
    arrows->append(newArror);
    return true;
}

void MatejkoCanvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::black);

    for (Arrow *arrow: *(this->arrows)) {
        arrow->draw(painter);
    }
}

bool canPrzemekIntoProgramming(){
    return false;
}

void MatejkoCanvas::constructArrow(Element *element) {
    Arrow *newArrow = NULL;

    if (qobject_cast<Place*>(element)){
        if (this->tmpArrow.transition){
            this->tmpArrow.place = element;
            this->tmpArrow.fromPlaceToTransition = false;
            this->buildArrow(&this->tmpArrow);
            this->tmpArrow.clear();
        }
        else {
            if (!this->tmpArrow.place){

            }
        }
    }
    else if (qobject_cast<Transition*>(element)){
        if (this->tmpArrow.place){
            this->tmpArrow.transition = element;
            this->tmpArrow.fromPlaceToTransition = true;
            this->buildArrow(&this->tmpArrow);
            this->tmpArrow.clear();
        }
        else {
            this->tmpArrow.clear();
        }
    }
}
