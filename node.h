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

    int getId() const;
    void setId(int value);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

private:
    int id;
    int x;
    int y;
};

#endif // NODE_H
