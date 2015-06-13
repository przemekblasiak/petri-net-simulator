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
    this->deactiveTransitions();
}

void SimulationEngine::activateTransitions() {
    bool activeTransitionIndices[this->transitions->count()];
    memset(activeTransitionIndices, true, sizeof(activeTransitionIndices));

    // Set indices of inactive transitions
    for (int i = 0; i < this->arrows->count(); ++i) {
        Arrow *arrow = (*this->arrows)[i];
        Place *place = qobject_cast<Place *>(arrow->place);
        bool enoughTokens = place->tokenCount() >= arrow->weight();
        if (arrow->fromPlaceToTransition && !enoughTokens) {
            activeTransitionIndices[this->transitions->indexOf(arrow->transition)] = false;
        }
    }
    for (int i = 0; i < this->transitions->count(); ++i) {
        bool active = activeTransitionIndices[i];
        (*this->transitions)[i]->setActive(active);
    }

    // TODO: Needs refactoring
    // Set dangling transition inactive
    for (Element *transition: *this->transitions) {
        QList<Arrow *> connectedArrows = this->arrowsForElement(transition);
        bool active = true;
        bool dangling = true;

        for (Arrow *arrow: connectedArrows) {
            Place *place = qobject_cast<Place *>(arrow->place);
            bool enoughTokens = place->tokenCount() >= arrow->weight();
            if (arrow->fromPlaceToTransition) {
                dangling = false;
                if (!enoughTokens) {
                    active = false;
                }
            }
        }

        if (dangling) {
            transition->setActive(false);
        } else {
            transition->setActive(active);
        }
    }
}

void SimulationEngine::deactiveTransitions() {
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
