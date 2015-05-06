#include "node.h"

Node::Node()
{
    id = 0;
}

//GETTERS
int Node::id() const
{
    return id;
}

int Node::location_x() const
{
    return location_x;
}

int Node::location_y() const
{
    return location_y;
}

//SETTERS
void Node::setLocation_x(int value)
{
    location_x = value;
}

void Node::setLocation_y(int value)
{
    location_y = value;
}
