#include "node.h"
#include <cstdlib>
#include <cassert>

Node::Node()
{
    _uuid = rand()*(RAND_MAX+1) + rand();
}

Node::Node(int loc_x, int loc_y) : Node()
{
    _location_x = loc_x;
    _location_y = loc_y;
}

Node::Node(int uuid, int loc_x, int loc_y) : Node(loc_x, loc_y)
{
    _uuid = uuid;
}

Node::~Node()
{

}

//GETTERS
int Node::uuid() const
{
    return _uuid;
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
void Node::setUuid(int value)
{
    _uuid = value;
}

void Node::setLocation_x(int value)
{
    _location_x = value;
}

void Node::setLocation_y(int value)
{
    _location_y = value;
}
