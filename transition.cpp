#include "transition.h"

#include <QtGui>

Transition::Transition(int x, int y):
    Node(x, y)
{
    this->width = 25;
    this->height = 50;
}

void Transition::draw(QPainter &painter)
{
    painter.drawRect(QRect(this->x, this->y, width, height));
}
