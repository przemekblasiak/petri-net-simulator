#ifndef ARROW_H
#define ARROW_H

#include "pnsglobal.h"
#include "place.h"
#include "transition.h"
#include <QApplication>
#include <QScreen>

class ClickableArea;

class Arrow : public QWidget
{
    Q_OBJECT
public:
    explicit Arrow(Element *place, Element *transition, bool fromPlaceToTransition, QWidget *parent);
    Arrow(const Arrow &arrow);
    virtual ~Arrow();
    void clear();
    Element *place;
    Element *transition;
    bool fromPlaceToTransition;
    void draw(QPainter &painter);
    int weight() const;
signals:
    void removeArrowRequested();
    void modifyArrowRequested();
public slots:
    void setWeight(int weight);
    void onContextMenuRequested(const QPoint &);
private slots:
    void onContextActionTriggered(QAction *action);
private:
    QImage arrowheadImage;
    int _weight;
    DescriptionLabel *_weightLabel;
    QVector<ClickableArea *> _clickableAreas;
    QVector<QRect> segmentsForArrowPoints(QVector<QPoint> points);
    QVector<QPoint> bezierPoints(QVector<QPoint> &points);
};

class ClickableArea: public QWidget {
    Q_OBJECT
public:
    explicit ClickableArea(QWidget *owner, QWidget *parent = nullptr);

signals:
    void contextMenuRequested(const QPoint &position);

private slots:
    void onContextMenuRequested(const QPoint &position);
};

#endif // ARROW_H
