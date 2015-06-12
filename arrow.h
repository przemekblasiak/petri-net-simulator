#ifndef ARROW_H
#define ARROW_H

#include "pnsglobal.h"
#include "place.h"
#include "transition.h"

class Arrow : public QWidget
{
    Q_OBJECT
public:
    explicit Arrow(Element *place, Element *transition, bool fromPlaceToTransition, QWidget *parent);
    Arrow(const Arrow &arrow);
    void clear();
    Element *place;
    Element *transition;
    bool fromPlaceToTransition;
    void draw(QPainter &painter) const;

    int weight() const;

signals:

public slots:
    void setWeight(int weight);

private:
    QImage arrowheadImage;
    int _weight;
    DescriptionLabel *_weightLabel;
};

#endif // ARROW_H
