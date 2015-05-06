#include "arrow.h"

Arrow::Arrow(QObject *parent) : QObject(parent)
{
    this->mx1 = 0;
    this->mx2 = 0;
    this->my1 = 0;
    this->my2 = 0;
}

int Arrow::x1() const
{
    return mx1;
}

void Arrow::setX1(int value)
{
    mx1 = value;
}
int Arrow::x2() const
{
    return mx2;
}

void Arrow::setX2(int value)
{
    mx2 = value;
}
int Arrow::y1() const
{
    return my1;
}

void Arrow::setY1(int value)
{
    my1 = value;
}
int Arrow::y2() const
{
    return my2;
}

void Arrow::setY2(int value)
{
    my2 = value;
}






