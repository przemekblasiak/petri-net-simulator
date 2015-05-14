#include "arrow.h"

Arrow::Arrow(QObject *parent) : QObject(parent)
{
    this->x1 = 0;
    this->x2 = 0;
    this->y1 = 0;
    this->y2 = 0;
}

Arrow *Arrow::pullAnArrow()
{
    return new Arrow();
}
int Arrow::getX1() const
{
    return x1;
}

void Arrow::setX1(int value)
{
    x1 = value;
}
int Arrow::getX2() const
{
    return x2;
}

void Arrow::setX2(int value)
{
    x2 = value;
}
int Arrow::getY1() const
{
    return y1;
}

void Arrow::setY1(int value)
{
    y1 = value;
}
int Arrow::getY2() const
{
    return y2;
}

void Arrow::setY2(int value)
{
    y2 = value;
}




