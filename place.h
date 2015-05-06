#ifndef PLACE_H
#define PLACE_H

#include "node.h"

class Place : public Node
{
public:
    Place();

    int liveness() const;
    void setLiveness(int liveness);

private:
    int _liveness;
};

#endif // PLACE_H
