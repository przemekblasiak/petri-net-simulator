#ifndef ENGINE_H
#define ENGINE_H

#include <QObject>
#include <QList>

#include "place.h"
#include "arrow.h"

class Engine : public QObject
{
    Q_OBJECT

public:
    static Engine& getInstance();

    QList<QObject *> places;
    QList<QObject *> arrows;


private:
    Engine();
};

#endif // ENGINE_H
