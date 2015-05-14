#ifndef MATEJKOCANVAS_H
#define MATEJKOCANVAS_H

#include <QWidget>

class MatejkoCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit MatejkoCanvas(QWidget *parent = 0);
    void setupPalette();

signals:

public slots:
private:
    void paintEvent(QPaintEvent *);
};

#endif // MATEJKOCANVAS_H
