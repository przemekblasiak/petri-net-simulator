#include "matejkocanvas.h"

#include <QtGui>
#include <QApplication>
#include <QList>
#include <QDebug>
#include <QMenu>

MatejkoCanvas::MatejkoCanvas(QWidget *parent) : QWidget(parent)
{
    // Context menu
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));

    this->setupPalette();

    // Example list of Places
    this->places.append(new Place(200, 200, 5));
    this->places.append(new Place(140, 300, 0));

    // Example list of Transitions
    this->transitions.append(new Transition(120, 80));
    this->transitions.append(new Transition(175, 120));
}

void MatejkoCanvas::showContextMenu(const QPoint &position) {
    QMenu contextMenu("Context menu", this);

    QAction addPlaceAction("Add place", this);
    QAction addTransitionAction("Add transition", this);
    addPlaceAction.setData(position);
    addTransitionAction.setData(position);
    contextMenu.addAction(&addPlaceAction);
    contextMenu.addAction(&addTransitionAction);
    connect(&contextMenu, SIGNAL(triggered(QAction *)),
            this, SLOT(contextActionTriggered(QAction *)));

    contextMenu.exec(this->mapToGlobal(position));
}

void MatejkoCanvas::contextActionTriggered(QAction *action) {
    QPoint position = action->data().toPoint();

    // TODO: Boże, wybacz!
    if (action->text() == "Add place") {
        Place *place = new Place(position.x(), position.y(), 0);
        this->places.append(place);
    } else if (action->text() == "Add transition") {
        Transition *transition = new Transition(position.x(), position.y());
        this->transitions.append(transition);
    }

    this->update();
}

void MatejkoCanvas::setupPalette() {
    QPalette palette(QApplication::palette());
    palette.setColor(backgroundRole(), Qt::gray);
    this->setPalette(palette);
}

void MatejkoCanvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    QFont font = painter.font();
    font.setPointSize(16);
    painter.setFont(font);

    // Draw places
    // TODO: zmienic length na count
    for (int i = 0; i < this->places.length(); ++i) {
        this->places[i]->draw(painter);
        //qDebug() << this->places.length();
    }

    // Draw transitions
    for (int i = 0; i < this->transitions.length(); ++i) {
        this->transitions[i]->draw(painter);
    }
}

void MatejkoCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPoint mouse = event->pos();
        qDebug() << "Clicked: x=" << mouse.x() << ", y=" << mouse.y();

        // TODO: Move this logic to context menu
        this->places.append(new Place(mouse.x(), mouse.y(), 0));
        qDebug() << places.last() << ", " << places.size();
        this->update();
    } else if (event->button() == Qt::RightButton){
    }
}
