#ifndef SIMULATIONENGINE_H
#define SIMULATIONENGINE_H

#include "pnsglobal.h"

#include "element.h"
#include "arrow.h"
#include "state.h"
#include "timer.h"

class SimulationEngine : public QObject
{
    Q_OBJECT

public:

    enum Liveness{
        L0_Live,
        L1_Live,
        L2_Live,
        L3_Live,
        L4_Live
    };

    static SimulationEngine& getInstance();
    void beginSimulation();

    QList<Element *> *places;
    QList<Element *> *transitions;
    QList<Arrow *> *arrows;


    void endSimulation();
    void executeTransition(Element *transition);
    QList<State *> generateReachabilityStates();
    Timer timer;

    QList<State *> getFakeStates();
    int livenessForTransition(Transition *transition);


private:
    SimulationEngine();
    SimulationEngine(const SimulationEngine& engineToCopy);
    ~SimulationEngine();
    void activateTransitions();
    void deactivateAllTransitions();
    QList<Arrow *> arrowsForElement(Element *element);
    State *getInitialState();
    QList<Element *> activeTransitionsForSimulatedState(State *state);
    State *stateAfterTransitionFromState(State *state, Element *transition);
    void attachChildrenStates(State *currentState, QList<State *> *states);

};

#endif // ENGINE_H
