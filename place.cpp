#include "place.h"

Place::Place()
{

}

Place::Place(int uuid, int loc_x, int loc_y, int liveness) : Node(uuid, loc_x, loc_y)
{
    _liveness = liveness;
}

Place::~Place()
{

}

int Place::liveness() const
{
    return _liveness;
}

void Place::setLiveness(int liveness)
{
    _liveness = liveness;
}


