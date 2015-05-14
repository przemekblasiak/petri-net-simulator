#ifndef ARROW_H
#define ARROW_H

#include <QObject>

class Arrow : public QObject
{
    Q_OBJECT

public:
    explicit Arrow(QObject *parent = 0);
    Arrow* pullAnArrow();

    int getX1() const;
    void setX1(int value);

    int getX2() const;
    void setX2(int value);

    int getY1() const;
    void setY1(int value);

    int getY2() const;
    void setY2(int value);

public slots:
private:
    int x1;
    int x2;
    int y1;
    int y2;
};

#endif // ARROW_H
