#ifndef PLACE_H
#define PLACE_H

#include "node.h"

class Place : public Node
{
    Q_OBJECT
    Q_PROPERTY(int liveness READ liveness WRITE setLiveness NOTIFY livenessChanged)

public:
    Place();
    Place(int uuid, int loc_x, int loc_y, int liveness=0);
    virtual ~Place();

    int liveness() const;

signals:
    void livenessChanged(int liveness);

public slots:
    void setLiveness(int liveness);

private:
    int _liveness;
};

#endif // PLACE_H
