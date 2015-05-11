#ifndef ARROW_H
#define ARROW_H

#include <QObject>

class Arrow : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int x1 READ x1 WRITE setX1 NOTIFY x1Changed)
    Q_PROPERTY(int x2 READ x2 WRITE setX2 NOTIFY x2Changed)
    Q_PROPERTY(int y1 READ y1 WRITE setY1 NOTIFY y1Changed)
    Q_PROPERTY(int y2 READ y2 WRITE setY2 NOTIFY y2Changed)

public:
    explicit Arrow(QObject *parent = 0);
    Q_INVOKABLE Arrow* pullAnArrow();

    int x1() const;
    int x2() const;
    int y1() const;
    int y2() const;

signals:
    void x1Changed(int x);
    void x2Changed(int x);
    void y1Changed(int y);
    void y2Changed(int y);

public slots:
    void setX1(int value);
    void setX2(int value);
    void setY1(int value);
    void setY2(int value);

private:
    int mx1, mx2;
    int my1, my2;
};

#endif // ARROW_H
