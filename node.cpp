#include "node.h"
#include <cstdlib>
#include <cassert>

Node::Node()
{
    _id = rand()*(RAND_MAX+1) + rand();
}

Node::Node(int id, int loc_x, int loc_y)
{
    _id = id;
    _location_x = loc_x;
    _location_y = loc_y;
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
void Node::setID(int value)
{
    _id = value;
}

void Node::setLocation_x(int value)
{
    _location_x = value;
}

void Node::setLocation_y(int value)
{
    _location_y = value;
}
