#ifndef PLACE_H
#define PLACE_H

#include "element.h"
#include <QDebug>

const QString PlaceStyleSheet = "border-style: outset;"\
                                "border-width: 1 5 1 5;"\
                                "border-radius: 20;"\
                                "padding: 0;";

namespace Ui {
class Place;
}

class Place : public Element
{
    Q_OBJECT

public:
    explicit Place(QPoint &origin, int liveness, QWidget *parent = 0);
    ~Place();

    void makeChildrenNotClickable();
    bool isClicked() const;
    void setClicked(bool clicked);
    int number() const;
    void setNumber(int number);

    int liveness;
    static int defaultWidth;
    static int defaultHeight;
    static int count;

public slots:
    void showContextMenu(const QPoint &pos);
    void contextActionTriggered(QAction *action);

private:
    Ui::Place *ui;
    bool clicked;
    int _number;

    enum ContextActionType {
        Edit,
        Remove
    };

signals:
    void removePlaceRequested();
    void modifyPlaceRequested();
};

#endif // PLACE_H
