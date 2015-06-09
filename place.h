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
    int token;
    static int count;
    explicit Place(const QPoint &origin, int token, QWidget *parent = 0);
    virtual ~Place();
public slots:
    virtual void settoken(int token);
private:
    Ui::Place *ui;
    virtual void updateNumber();
};

#endif // PLACE_H
