#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QList>

#include "node.h"
#include "place.h"
#include "transition.h"
#include "arrow.h"

class Engine : public QObject
{
    Q_OBJECT

public:
    explicit Engine(QObject *parent = 0);

    QList<QObject *> places;
    QList<QObject *> transitions;
    QList<QObject *> arrows;
};

#endif // ENGINE_H
