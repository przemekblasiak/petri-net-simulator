#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include "pnsglobal.h"

#include "element.h"
#include "arrow.h"

class SimulationEngine : public QObject
{
    Q_OBJECT

public:
    static SimulationEngine& getInstance();
    void beginSimulation();

    QList<Element *> *places;
    QList<Element *> *transitions;
    QList<Arrow *> *arrows;


    void endSimulation();
    void executeTransition(Element *transition);
private:
    SimulationEngine();
    SimulationEngine(const SimulationEngine& engineToCopy);
    void activateTransitions();
    void deactiveTransitions();
    QList<Arrow *> arrowsForElement(Element *element);
};

#endif // ENGINE_H
