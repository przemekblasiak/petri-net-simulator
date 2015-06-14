#include "simulationengine.h"

SimulationEngine &SimulationEngine::getInstance()
{
    static SimulationEngine instance;
    return instance;
}

SimulationEngine::SimulationEngine(): QObject(0) {}
SimulationEngine::SimulationEngine(const SimulationEngine &engineToCopy): QObject(0) {Q_UNUSED(engineToCopy)}

void SimulationEngine::beginSimulation() {
    this->activateTransitions();
}

void SimulationEngine::endSimulation() {
    this->deactivateAllTransitions();
}

void SimulationEngine::activateTransitions() {
    for (Element *transition: *this->transitions) {
        bool active = true;
        QList<Arrow *> connectedArrows = this->arrowsForElement(transition);
        for (Arrow *arrow: connectedArrows) {
            if (arrow->fromPlaceToTransition) {
                Place *place = (Place *)(arrow->place);
                bool notEnoughTokens = place->tokenCount() < arrow->weight();
                if (notEnoughTokens) {
                    active = false;
                    goto escape;
                }
            }
        }
        escape:
        transition->setActive(active);
    }
}

void SimulationEngine::deactivateAllTransitions() {
    for (Element *transition: *this->transitions) {
        transition->setActive(false);
    }
}

QList<Arrow *> SimulationEngine::arrowsForElement(Element *element) {
    QList<Arrow *> connectedArrows;
    for (Arrow *arrow: *(this->arrows)) {
        if (arrow->place == element || arrow->transition == element) {
            connectedArrows.append(arrow);
        }
    }
    return connectedArrows;
}

void SimulationEngine::executeTransition(Element *transition) {
    // TODO:
    QList<Arrow *> associatedArrows = SimulationEngine::arrowsForElement(transition);

    for (Arrow *arrow: associatedArrows){
        Place *place = qobject_cast<Place*>(arrow->place);
        if (arrow->fromPlaceToTransition){
            place->setTokenCount(place->tokenCount() - arrow->weight());
        }
        else {
            place->setTokenCount(place->tokenCount() + arrow->weight());
        }
    }
    this->activateTransitions();
}
