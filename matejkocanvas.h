#ifndef MATEJKOCANVAS_H
#define MATEJKOCANVAS_H

#include <QWidget>
#include "place.h"
#include "transition.h"

class MatejkoCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit MatejkoCanvas(QWidget *parent = 0);
    void setupPalette();

signals:

public slots:
private:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *event);

    // TODO: Brac z engine
    QList<Place *> places;
    QList<Transition *> transitions;
};

#endif // MATEJKOCANVAS_H
