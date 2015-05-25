#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include "place.h"
#include "transition.h"

class Arrow : public QObject
{
    Q_OBJECT
public:
    explicit Arrow(Place *place, Transition *transition, bool fromPlaceToTransition, QObject *parent = 0);
    explicit Arrow(QObject *parent = 0);
    void clear();
    Place *place;
    Transition *transition;

    bool fromPlaceToTransition;

signals:

public slots:

};

#endif // ARROW_H
