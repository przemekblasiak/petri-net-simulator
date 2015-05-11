#ifndef PLACE_H
#define PLACE_H

#include "node.h"

class Place : public Node
{
public:
    Place();
    Place(int id, int loc_x, int loc_y, int liveness);

    int liveness() const;
    void setLiveness(int liveness);

private:
    int _liveness;
};

#endif // PLACE_H
