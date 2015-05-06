#ifndef NODE_H
#define NODE_H

#include "node.h"

class Node
{
public:
    Node();

    int id() const;

    int location_x() const;
    void setLocation_x(int value);

    int location_y() const;
    void setLocation_y(int value);

private:
    int id;
    int location_x;
    int location_y;
};

#endif // NODE_H
