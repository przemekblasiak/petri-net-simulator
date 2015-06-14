#ifndef ARROW_H
#define ARROW_H

#include "pnsglobal.h"
#include "place.h"
#include "transition.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

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
    class ClickableArea;
    QVector<ClickableArea *> _clickableAreas;
    QVector<QRect> segmentsForArrowPoints(QVector<QPoint> points);
};

class Arrow::ClickableArea: public QWidget {
    Q_OBJECT
public:
    explicit ClickableArea(QWidget *owner, QWidget *parent): QWidget(parent) {
        this->lower();
        this->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
                this, SLOT(onContextMenuRequested(const QPoint &)));
        connect(this, SIGNAL(contextMenuRequested(const QPoint &)),
                owner, SLOT(onContextMenuRequested(const QPoint &)));
        this->show();
    }
signals:
    void contextMenuRequested(const QPoint &position);
private slots:
    void onContextMenuRequested(const QPoint &position) {
        QPoint mappedPosition(mapToGlobal(position));
        emit contextMenuRequested(mappedPosition);
    }
};

#endif // ARROW_H
