#include "node.h"
#include <cstdlib>
#include <cassert>

Node::Node()
{
    id = rand()*(RAND_MAX+1) + rand();
}

Node::Node(int x, int y) :
    x(x), y(y)
{
    id = rand()*(RAND_MAX+1) + rand();
}

Node::Node(int id, int x, int y) :
    id(id), x(x), y(y)
{
}
