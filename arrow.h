#ifndef ARROW_H
#define ARROW_H

#include <QObject>

class Arrow : public QObject
{
    Q_OBJECT
public:
    explicit Arrow(QObject *parent = 0);
    int x1, x2;
    int y1, y2;

    int getX1() const;
    void setX1(int value);

signals:

public slots:
};

#endif // ARROW_H
