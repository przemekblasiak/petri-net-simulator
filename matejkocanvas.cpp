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
    contextMenu.addAction(&addPlaceAction);
    contextMenu.addAction(&addTransitionAction);

    contextMenu.exec(this->mapToGlobal(position));
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

    // Draw places
    for (int i = 0; i < this->places.count(); ++i) {
        this->places[i]->draw(painter);
    }

    // Draw transitions
    for (int i = 0; i < this->places.count(); ++i) {
        this->transitions[i]->draw(painter);
    }
}

void MatejkoCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPoint mouse = event->pos();
        qDebug() << "Clicked: x=" << mouse.x() << ", y=" << mouse.y();
    } else if (event->button() == Qt::RightButton){
    }
}
