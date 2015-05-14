#include "place.h"

Place::Place()
{

}

Place::Place(int id, int x, int y, int liveness) :
    Node(id, x, y),
    liveness(liveness)
{

}

Place::~Place()
{

}
int Place::getLiveness() const
{
    return liveness;
}

void Place::setLiveness(int value)
{
    liveness = value;
}


