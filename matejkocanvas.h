#ifndef MATEJKOCANVAS_H
#define MATEJKOCANVAS_H

#include <QWidget>
#include "place.h"
#include "transition.h"

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
    // Painting
    void paintEvent(QPaintEvent *);
    void setupPalette();

    // Mouse
    void mousePressEvent(QMouseEvent *event);

    // TODO: Take places and transitions form MainWindow, BITCH!!!!!
    QList<Place *> places;
    QList<Transition *> transitions;
};

#endif // MATEJKOCANVAS_H
