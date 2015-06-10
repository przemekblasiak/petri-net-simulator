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
    static int count;
    explicit Place(const QPoint &origin, int tokenCount, QWidget *parent = 0);
    virtual ~Place();
    int tokenCount();
public slots:
    void setTokenCount(int tokenCount);
private:
    Ui::Place *ui;
    virtual void updateNumber();
    int _tokenCount;
};

#endif // PLACE_H
