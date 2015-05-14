#include "place.h"

Place::Place()
{

}

Place::Place(int id, int x, int y, int liveness) :
    Node(id, x, y), liveness(liveness)
{
}


