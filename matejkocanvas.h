#ifndef MATEJKOCANVAS_H
#define MATEJKOCANVAS_H

#include <QWidget>
#include "place.h"

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

    // TODO: Brac z engine
    QList<Place *> places;
};

#endif // MATEJKOCANVAS_H
