#include "place.h"

Place::Place()
{

}

Place::Place(int x, int y, int liveness):
    liveness(liveness)
{
    // TODO: wyliczanie id + przeniesc do node
    this->x = x;
    this->y = y;
    this->id = id;
}

Place::Place(int id, int x, int y, int liveness) :
    Node(id, x, y), liveness(liveness)
{
}

void Place::draw(QPainter *painter)
{
    painter->drawEllipse(QPoint(this->x, this->y), 50, 50);
}

