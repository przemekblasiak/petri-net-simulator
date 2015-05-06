#include "node.h"

Node::Node()
{
    id = 0;
}

//GETTERS
int Node::id() const
{
    return _id;
}

int Node::location_x() const
{
    return _location_x;
}

int Node::location_y() const
{
    return _location_y;
}

//SETTERS
void Node::setLocation_x(int value)
{
    _location_x = value;
}

void Node::setLocation_y(int value)
{
    _location_y = value;
}
