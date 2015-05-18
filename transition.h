#ifndef TRANSITION_H
#define TRANSITION_H

#include <QObject>
#include "node.h"

#include <QtGui>

class Transition : public Node
{
    Q_OBJECT

public:
    Transition(int x, int y);

    void draw(QPainter &painter);
private:
    int width, height;
};

#endif // TRANSITION_H
