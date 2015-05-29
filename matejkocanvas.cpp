#include "matejkocanvas.h"

#include <QtGui>
#include <QApplication>
#include <QList>
#include <QDebug>
#include <QMenu>
#include <QIcon>

MatejkoCanvas::MatejkoCanvas(QWidget *parent) : QWidget(parent)
{
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
        Place *newPlace = new Place(position.x(), position.y(), 0, this);
        this->places->append(newPlace);
    }
    else if (actionType == AddTransition) {
        Transition *newTransition = new Transition(position.x(), position.y(), this);
        this->transitions->append(newTransition);
    }
}

void MatejkoCanvas::onRemovePlaceRequested(Place &place)
{
    qDebug() << "onRemovePlaceRequested";
}

void MatejkoCanvas::onModifyPlaceRequested(Place &place)
{
    qDebug() << "onModifyPlaceRequested";
}

void MatejkoCanvas::onRemoveTransitionRequested(Transition &transition)
{
    qDebug() << "onRemoveTransitionRequested";
}

void MatejkoCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QObject *object = childAt(event->pos());
        Place *place = qobject_cast<Place *>(object);
        Transition *transition = qobject_cast<Transition *>(object);
        this->constructArrow(place, transition);
    }
    else if (event->button() == Qt::RightButton){
    }
}

void MatejkoCanvas::setupPalette() {
    QPalette palette(QApplication::palette());
    palette.setColor(backgroundRole(), Qt::gray);
    this->setPalette(palette);
}

void MatejkoCanvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::black);

    for (Arrow *arrow: *(this->arrows)) {
        arrow->draw(painter);
    }
}

void MatejkoCanvas::constructArrow(Place *place, Transition *transition, bool fromPlaceToTransition) {
    Arrow *newArrow = NULL;
    qDebug() << this->tmpArrow.place << this->tmpArrow.transition;
    if (place && transition) {
        this->tmpArrow.place = place;
        this->tmpArrow.transition = transition;
        this->tmpArrow.fromPlaceToTransition = fromPlaceToTransition;
        newArrow = new Arrow(this->tmpArrow);
        this->tmpArrow.clear();
    }
    else if (place){
        if (this->tmpArrow.place){
            this->tmpArrow.clear();
        }
        else if (this->tmpArrow.transition){
            this->tmpArrow.place = place;
            newArrow = new Arrow(this->tmpArrow);
            this->tmpArrow.clear();
        }
        else {
            this->tmpArrow.place = place;
            this->tmpArrow.place->setClicked(true);
            this->tmpArrow.fromPlaceToTransition = true;
        }
    }
    else if (transition){
        if (this->tmpArrow.transition){
            this->tmpArrow.clear();
        }
        else if (this->tmpArrow.place){
            this->tmpArrow.transition = transition;
            newArrow = new Arrow(this->tmpArrow);
            this->tmpArrow.clear();
        }
        else {
            this->tmpArrow.transition = transition;
            this->tmpArrow.transition->setClicked(true);
            this->tmpArrow.fromPlaceToTransition = false;
        }
    }

    if (newArrow) {
        this->arrows->append(newArrow);
        this->update();
    }
}
