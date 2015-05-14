#ifndef PLACE_H
#define PLACE_H

#include "node.h"
#include <QtGui>

class Place : public Node
{
    Q_OBJECT

public:
    Place(int x, int y);
    Place(int x, int y, int liveness);
    Place(int id, int x, int y, int liveness);

    void draw(QPainter *painter);

    int liveness;
};

#endif // PLACE_H
