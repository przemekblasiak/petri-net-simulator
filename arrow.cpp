#include "arrow.h"
#include <QDebug>

Arrow::Arrow(Place *place, Transition *transition, bool fromPlaceToTransition, QObject *parent):
    QObject(parent), place(place), transition(transition), fromPlaceToTransition(fromPlaceToTransition)
{

}

Arrow::Arrow(QObject *parent): QObject(parent), fromPlaceToTransition(true)
{

}

Arrow::Arrow(const Arrow &arrow)
{
    this->setParent(arrow.parent());
    this->place = arrow.place;
    this->transition = arrow.transition;
    this->fromPlaceToTransition = arrow.fromPlaceToTransition;
}

void Arrow::clear()
{
    place = NULL;
    transition = NULL;
    fromPlaceToTransition = true;
}

void Arrow::draw(QPainter &painter) const {
    QPoint point1, point2;
    int w1, h1, w2, h2, dh, dw;
    if (this->fromPlaceToTransition) {
        point1 = QPoint(this->place->x(), this->place->y());
        w1 = this->place->width();
        h1 = this->place->height();
        point2 = QPoint(this->transition->x(), this->transition->y());
        w2 = this->transition->width();
        h2 = this->transition->height();
    }
    else {
        point1 = QPoint(this->transition->x(), this->transition->y());
        w1 = this->transition->width();
        h1 = this->transition->height();
        point2 = QPoint(this->place->x(), this->place->y());
        w2 = this->place->width();
        h2 = this->place->height();
    }
    dh = (point1.y() - point2.y()) - h2/2 + h1/2;
    dw = point2.x() - point1.x() - w1;

    // Prawo-Lewo
    // TODO naprawde pomoglyby QPointy w transition i place
    QVector<QPoint> checkPoints;
    bool toRight = point2.x() > point1.x();
    if (toRight) {
        checkPoints.append(QPoint(point1.x() + w1, point1.y() + h1/2));
        int d1 = dw/2;
        checkPoints.append(QPoint(checkPoints.last().x() + d1, checkPoints.last().y()));

        checkPoints.append(checkPoints.last());
        checkPoints.append(QPoint(checkPoints.last().x(), checkPoints.last().y() - dh)); // TODO moze byc problem z wysokoscia

        checkPoints.append(checkPoints.last());
        int d2 = dw - d1;
        checkPoints.append(QPoint(checkPoints.last().x() + d2, checkPoints.last().y()));
    }

    // TODO Góra-Dół

    painter.drawLines(checkPoints);
    qDebug() << checkPoints;
}

