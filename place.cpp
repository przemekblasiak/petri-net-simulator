#include "place.h"

Place::Place()
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


