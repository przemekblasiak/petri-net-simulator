#include "transition.h"

#include <QtGui>

Transition::Transition()
{

}

Transition::Transition(int x, int y):
    Node(x, y)
{

}

void Transition::draw(QPainter *painter)
{
    painter->drawRect(QRect(this->x, this->y, 50, 50));
}
