#include "place.h"

Place::Place(int x, int y, int liveness) :
    Node(x, y),
    liveness(liveness)
{
    this->radius = 10;
}

Place::Place(int id, int x, int y, int liveness) :
    Node(id, x, y),
    liveness(liveness)
{
    this->radius = 10;
}

void Place::draw(QPainter &painter)
{
    painter.drawEllipse(QPoint(this->x - this->radius, this->y - this->radius), this->radius * 2, this->radius * 2);
    painter.drawText(QPoint(this->x - this->radius, this->y - this->radius), QString::number(this->liveness));
}
