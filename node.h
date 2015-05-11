#ifndef NODE_H
#define NODE_H

#include <QObject>

class Node : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int uuid READ uuid WRITE setUuid NOTIFY uuidChanged)
    Q_PROPERTY(int location_x READ location_x WRITE setLocation_x NOTIFY location_xChanged)
    Q_PROPERTY(int location_y READ location_y WRITE setLocation_y NOTIFY location_yChanged)

public:
    Node();
    Node(int loc_x, int loc_y);
    Node(int uuid, int loc_x, int loc_y);
    virtual ~Node();

    int uuid() const;
    int location_x() const;
    int location_y() const;

signals:
    void uuidChanged(int uuid);
    void location_xChanged(int x);
    void location_yChanged(int y);

public slots:
    void setUuid(int value);
    void setLocation_x(int value);
    void setLocation_y(int value);

private:
    int _uuid;
    int _location_x;
    int _location_y;
};

#endif // NODE_H
