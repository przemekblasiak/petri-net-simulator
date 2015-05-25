#ifndef ARROW_H
#define ARROW_H

#include <QFrame>

namespace Ui {
class Arrow;
}

class Arrow : public QFrame
{
    Q_OBJECT

public:
    explicit Arrow(int x, int y, int x2, int y2, QWidget *parent = 0);
    // TODO przerobic klasy zeby uzywaly QPoint
    ~Arrow();

private:
    Ui::Arrow *ui;
};

#endif // ARROW_H
