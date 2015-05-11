#include "place.h"

Place::Place()
{

}

Place::Place(int id, int loc_x, int loc_y, int liveness) : Node(id, loc_x, loc_y)
{
    _liveness = liveness;
}

int Place::liveness() const
{
    return _liveness;
}

void Place::setLiveness(int liveness)
{
    _liveness = liveness;
}


