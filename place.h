#ifndef PLACE_H
#define PLACE_H

#include <QFrame>

const QString PlaceStyleSheet = "border-style: outset;"\
                                "border-width: 1 5 1 5;"\
                                "border-radius: 20;"\
                                "padding: 0;";

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

    bool isClicked() const;
    void setClicked(bool clicked);

private:
    Ui::Place *ui;
    bool clicked;
};

#endif // PLACE_H
