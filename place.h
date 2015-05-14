#ifndef PLACE_H
#define PLACE_H

#include "node.h"

class Place : public Node
{
    Q_OBJECT

public:
    Place();
    Place(int id, int x, int y, int liveness=0);
    virtual ~Place();

    int getLiveness() const;
    void setLiveness(int value);

private:
    int liveness;
};

#endif // PLACE_H
