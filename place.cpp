#include "place.h"

Place::Place(int x, int y, int liveness) :
    Node(x, y),
    liveness(liveness)
{
    this->radius = 25;
}

Place::Place(int id, int x, int y, int liveness) :
    Node(id, x, y),
    liveness(liveness)
{
    this->radius = 25;
}

void Place::draw(QPainter &painter)
{
    painter.drawEllipse(QPoint(this->x, this->y), this->radius, this->radius);
}
