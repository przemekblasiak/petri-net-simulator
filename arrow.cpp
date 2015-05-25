#include "arrow.h"

Arrow::Arrow(Place *place, Transition *transition, bool fromPlaceToTransition, QObject *parent):
    QObject(parent), place(place), transition(transition), fromPlaceToTransition(fromPlaceToTransition)
{

}

Arrow::Arrow(QObject *parent): QObject(parent), fromPlaceToTransition(true)
{

}

void Arrow::clear()
{
    place = NULL;
    transition = NULL;
    fromPlaceToTransition = true;
}

