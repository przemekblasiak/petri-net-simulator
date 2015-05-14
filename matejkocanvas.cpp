#include "matejkocanvas.h"

#include <QtGui>
#include <QApplication>

MatejkoCanvas::MatejkoCanvas(QWidget *parent) : QWidget(parent)
{
    this->setupPalette();
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
    painter.drawEllipse(QPoint(200, 200), 50, 50);
}
