#include "matejkocanvas.h"

#include <QtGui>
#include <QApplication>
#include <QList>
#include <QDebug>

MatejkoCanvas::MatejkoCanvas(QWidget *parent) : QWidget(parent)
{
    this->setupPalette();

    // Example list of Places
    this->places.append(new Place(200, 200, 5));
    this->places.append(new Place(140, 300, 0));

    // Example list of Transitions
    this->transitions.append(new Transition(120, 80));
    this->transitions.append(new Transition(175, 120));
}

void MatejkoCanvas::setupPalette() {
    QPalette palette(QApplication::palette());
    palette.setColor(backgroundRole(), Qt::gray);
    this->setPalette(palette);
}

void MatejkoCanvas::paintEvent(QPaintEvent *)
{
    // Painting test
    QPainter painter(this);
    painter.setPen(Qt::darkGreen);

    // Draw places
    for (int i = 0; i < this->places.count(); ++i) {
        this->places[i]->draw(&painter);
    }

    // Draw transitions
    for (int i = 0; i < this->places.count(); ++i) {
        this->transitions[i]->draw(&painter);
    }
}

void MatejkoCanvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        QPoint mouse = event->pos();
        qDebug() << "Clicked: x=" << mouse.x() << ", y=" << mouse.y();
    }
}
