#include "place.h"

Place::Place(int x, int y, int liveness) :
    Node(x, y),
    liveness(liveness)
{
}

Place::Place(int id, int x, int y, int liveness) :
    Node(id, x, y),
    liveness(liveness)
{
}

void Place::draw(QPainter *painter)
{
    painter->drawEllipse(QPoint(this->x, this->y), 50, 50);
}
