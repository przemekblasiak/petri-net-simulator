#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include "pnsglobal.h"

#include "element.h"
#include "arrow.h"
#include "state.h"

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
    QList<State *> generateReachabilityStates();

private:
    SimulationEngine();
    SimulationEngine(const SimulationEngine& engineToCopy);
    void activateTransitions();
    void deactivateAllTransitions();
    QList<Arrow *> arrowsForElement(Element *element);
    State *getInitialState();
    QList<Element *> activeTransitionsForSimulatedState(State *state);
    State *stateAfterTransitionFromState(State *state, Element *transition);
    void attachChildrenStates(State *currentState, QList<State *> *states);

};

#endif // ENGINE_H
