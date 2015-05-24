#ifndef MATEJKOCANVAS_H
#define MATEJKOCANVAS_H

#include <QWidget>
#include "place.h"

class MatejkoCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit MatejkoCanvas(QWidget *parent = 0);

signals:

public slots:
    void showContextMenu(const QPoint &);
    void contextActionTriggered(QAction *);

private:

    // Mouse
    void mousePressEvent(QMouseEvent *event);

    QList<Place *> places;

    enum ContextActionType {
        AddPlace,
        AddTransition
    };
};

#endif // MATEJKOCANVAS_H
