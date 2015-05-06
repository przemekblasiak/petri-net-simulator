#ifndef NODE_H
#define NODE_H

#include <QObject>

class Node: public QObject
{
public:
    Node();

    int id() const;
    void setID(int value);

    int location_x() const;
    void setLocation_x(int value);

    int location_y() const;
    void setLocation_y(int value);



private:
    int _id;
    int _location_x;
    int _location_y;
};

#endif // NODE_H
