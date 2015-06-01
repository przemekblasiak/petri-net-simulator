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
    explicit Place(QPoint &origin, int liveness, QWidget *parent = 0);
    ~Place();
    void makeChildrenNotClickable();

    int liveness;
    static int defaultWidth;
    static int defaultHeight;

    bool isClicked() const;
    void setClicked(bool clicked);

public slots:
    void showContextMenu(const QPoint &pos);
    void contextActionTriggered(QAction *action);

private:
    Ui::Place *ui;
    bool clicked;

    enum ContextActionType {
        Edit,
        Remove
    };

signals:
    void removePlaceRequested(Place &place);
    void modifyPlaceRequested(Place &place);
};

#endif // PLACE_H
