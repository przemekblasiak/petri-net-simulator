#ifndef MATEJKOCANVAS_H
#define MATEJKOCANVAS_H

#include <QWidget>
#include "place.h"
#include "transition.h"
#include "arrow.h"


class MatejkoCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit MatejkoCanvas(QWidget *parent = 0);
    // TODO copy constructor

    QList<Element *> *places;
    QList<Element *> *transitions;
    QList<Arrow *> *arrows;

signals:

public slots:
    void showContextMenu(const QPoint &);
    void contextActionTriggered(QAction *);
    void onRemoveElementRequested();
    void onModifyElementRequested();

private:
    Arrow tmpArrow;

    // Mouse
    void mousePressEvent(QMouseEvent *event);

    enum ContextActionType {
        AddPlace,
        AddTransition
    };
    void constructArrow(Place *place, Transition *transition, bool fromPlaceToTransition = true);
    void paintEvent(QPaintEvent *event);
    void setupPalette();
};

#endif // MATEJKOCANVAS_H
