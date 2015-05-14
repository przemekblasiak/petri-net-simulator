#include "node.h"
#include <cstdlib>
#include <cassert>

Node::Node()
{
    id = rand()*(RAND_MAX+1) + rand();
}

Node::Node(int x, int y) :
    x(x),
    y(y)
{
    id = rand()*(RAND_MAX+1) + rand();
}

Node::Node(int id, int x, int y) :
    id(id),
    x(x),
    y(y)
{
}

Node::~Node()
{

}
int Node::getId() const
{
    return id;
}

void Node::setId(int value)
{
    id = value;
}
int Node::getX() const
{
    return x;
}

void Node::setX(int value)
{
    x = value;
}
int Node::getY() const
{
    return y;
}

void Node::setY(int value)
{
    y = value;
}



