#ifndef PLACE_H
#define PLACE_H

#include <QFrame>

namespace Ui {
class Place;
}

class Place : public QFrame
{
    Q_OBJECT

public:
    explicit Place(int x, int y, int liveness, QWidget *parent = 0);
    ~Place();
    void makeChildrenNotClickable();

    int liveness;
    static int defaultWidth;
    static int defaultHeight;

private:
    Ui::Place *ui;
};

#endif // PLACE_H
