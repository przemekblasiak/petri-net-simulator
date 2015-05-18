#ifndef ARROW_H
#define ARROW_H

#include <QObject>

class Arrow : public QObject
{
    Q_OBJECT

public:
    explicit Arrow(QObject *parent = 0);
    Arrow(int x1, int x2, int y1, int y2);

    int x1;
    int x2;
    int y1;
    int y2;
};

#endif // ARROW_H
