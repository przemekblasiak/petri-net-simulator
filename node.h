#ifndef NODE_H
#define NODE_H

#include <QObject>

class Node : public QObject
{
    Q_OBJECT

public:
    Node();
    Node(int x, int y);
    Node(int id, int x, int y);
    virtual ~Node();

    int id;
    int x;
    int y;
};

#endif // NODE_H
