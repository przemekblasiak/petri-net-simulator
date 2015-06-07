#ifndef PLACE_H
#define PLACE_H

#include "element.h"

namespace Ui {
class Place;
}

class Place : public Element
{
    Q_OBJECT

public:
    explicit Place(QPoint &origin, int liveness, QWidget *parent = 0);
    virtual ~Place();

    int liveness;
    static int count;

    virtual QString description() const;
    virtual QRect innerFrame() const;
public slots:
    virtual void setDescription(const QString &description);
    virtual void setLiveness(int liveness);

private:
    virtual void updateNumber();
    Ui::Place *ui;
};

#endif // PLACE_H
