#ifndef STATE_H
#define STATE_H

#include "element.h"
#include "place.h"
#include "transition.h"

namespace Ui {
class State;
}

class State : public QWidget
{
    Q_OBJECT

public:
    struct StateConnection {
        StateConnection(State *destination, Element *transition) {
            this->destination = destination;
            this->transition = transition;
        }
        State *destination;
        Element *transition;
    };

    State(QList<Element *> &places);
    State(const State &state);
    virtual ~State();
    QVector<int> tokenCounts;
    void setupUi(QWidget *parent);
    QList<StateConnection> outgoingConnections;
    bool operator==(const State &stateToCompareTo);
    int level;
    QString description();
    State *parentState;
private:
    State();
    Ui::State *ui;
};

#endif // STATE_H
