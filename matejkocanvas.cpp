#include "matejkocanvas.h"

#include <QtGui>
#include <QApplication>
#include <QList>

MatejkoCanvas::MatejkoCanvas(QWidget *parent) : QWidget(parent)
{
    this->setupPalette();

    // Example list of Places
    this->places.append(new Place(200, 200, 5));
    this->places.append(new Place(140, 300, 0));
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
        places[i]->draw(&painter);
    }
}
