#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include "place.h"
#include "transition.h"
#include <QPainter>
#include <QImage>

class Arrow : public QObject
{
    Q_OBJECT
public:
    explicit Arrow(Element *place, Element *transition, bool fromPlaceToTransition, QObject *parent = 0);
    explicit Arrow(QObject *parent = 0);
    Arrow(const Arrow &arrow);
    void clear();
    Element *place;
    Element *transition;

    bool fromPlaceToTransition;

    void draw(QPainter &painter) const;
signals:

public slots:

private:
    QImage arrowheadImage;
};

#endif // ARROW_H
