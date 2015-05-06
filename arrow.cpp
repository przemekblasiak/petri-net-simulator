#include "arrow.h"

Arrow::Arrow(QObject *parent) : QObject(parent)
{
    this->x1 = 0;
    this->x2 = 0;
    this->y1 = 0;
    this->y2 = 0;
}
int Arrow::getX1() const
{
    return x1;
}

void Arrow::setX1(int value)
{
    x1 = value;
}


