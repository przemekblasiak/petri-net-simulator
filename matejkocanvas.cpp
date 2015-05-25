#include "matejkocanvas.h"

#include <QtGui>
#include <QApplication>
#include <QList>
#include <QDebug>
#include <QMenu>
#include <QIcon>

MatejkoCanvas::MatejkoCanvas(QWidget *parent) : QWidget(parent)
{
    // Context menu
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
}

void MatejkoCanvas::showContextMenu(const QPoint &position) {
    QMenu contextMenu("Context menu", this);

    QAction addPlaceAction(this);
    QAction addTransitionAction(this);
    addPlaceAction.setText("Add place");
    addTransitionAction.setText("Add transition");
    contextMenu.addAction(&addPlaceAction);
    contextMenu.addAction(&addTransitionAction);

    QMap<QString, QVariant> placeInfo;
    placeInfo["ActionType"] = QVariant(AddPlace);
    placeInfo["Position"] = QVariant(position);
    addPlaceAction.setData(placeInfo);

    QMap<QString, QVariant> transitionInfo;
    transitionInfo["ActionType"] = QVariant(AddTransition);
    transitionInfo["Position"] = QVariant(position);
    addTransitionAction.setData(transitionInfo);

    connect(&contextMenu, SIGNAL(triggered(QAction *)),
            this, SLOT(contextActionTriggered(QAction *)));

    contextMenu.exec(this->mapToGlobal(position));
}

void MatejkoCanvas::contextActionTriggered(QAction *action) {
    QMap<QString, QVariant> actionInfo = action->data().toMap();
    QPoint position = actionInfo["Position"].toPoint();
    ContextActionType actionType = (ContextActionType)actionInfo["ActionType"].toInt();

    if (actionType == AddPlace) {
        Place *newPlace = new Place(position.x(), position.y(), 0, this);
        this->places->append(newPlace);
    } else if (actionType == AddTransition) {
        Transition *newTransition = new Transition(position.x(), position.y(), this);
        this->transitions->append(newTransition);
    }
}

void MatejkoCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // Rozpoznawanie jaki obiekt leży poniżej
        QObject *object = childAt(event->pos());
        Place *place = qobject_cast<Place *>(object);
        Transition *transition = qobject_cast<Transition *>(object);

        if (place){
            qDebug() << "is Place";
            if (this->tmpArrow.place){
                this->tmpArrow.clear();
            }
            else if (this->tmpArrow.transition){
                this->tmpArrow.place=place;
                // TODO use copy constructor instead
                Arrow *newArrow = new Arrow(this->tmpArrow.place, this->tmpArrow.transition, this->tmpArrow.fromPlaceToTransition, this);
                this->tmpArrow.clear();
            }
            else {
                this->tmpArrow.place = place;
                this->tmpArrow.fromPlaceToTransition = true;
            }
        }
        // TODO transitions
        else if (transition){
            qDebug() << "is Transition";
        }

    } else if (event->button() == Qt::RightButton){
    }
}
