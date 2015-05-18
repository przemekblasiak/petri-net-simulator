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
    static Engine& getInstance();

    QList<QObject *> places;
    QList<QObject *> transitions;
    QList<QObject *> arrows;


private:
    Engine();
};

#endif // ENGINE_H
