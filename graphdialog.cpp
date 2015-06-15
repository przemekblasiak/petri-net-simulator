#include "graphdialog.h"
#include "ui_graphdialog.h"
#include <QDebug>
#include "simulationengine.h"
#include "state.h"

GraphDialog::GraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphDialog)
{
    ui->setupUi(this);
    connect(this, SIGNAL(accepted()), this, SLOT(deleteLater()));
}

GraphDialog::~GraphDialog()
{
    delete ui;
}

void GraphDialog::prepareReachabilityGraph() { // TODO: Refactor name
    //    _states = SimulationEngine::getInstance().getReachabilityStates();
    SimulationEngine &engine = SimulationEngine::getInstance();
    QList<State *> states = engine.generateReachabilityStates();

    // Display states
    QList<State *> drawnStates;
    this->drawState(states[0], 0, 0, drawnStates);

    // TODO: Deallocate states (recursively)
}

void GraphDialog::drawState(State *state, int level, int column, QList<State *> &drawnStates) { // TODO: Refactor arguments
    static int columnBase = 0;

    // Draw
    state->setupUi(ui->canvas);
    state->move(column * state->width() + 5, level * state->height() + 5);
    drawnStates.append(state);

    bool isLeaf = true;
    for (int i = 0; i < state->outgoingConnections.count(); ++i) {
        State::StateConnection &connection = state->outgoingConnections[i];
        State *nextState = connection.destination;
        // TODO: Draw connection
        bool duplicate = false;
        for (State *drawnState: drawnStates) {
            if (*drawnState == *nextState) {
                duplicate = true;
            }
        }
        if (!duplicate) {
            this->drawState(nextState, level+1, columnBase, drawnStates);
            isLeaf = false;
        }
    }
    if (isLeaf) {
        ++columnBase;
    }
    if (level == 0) {
        columnBase = 0;
    }
}

void GraphDialog::on_GraphDialog_finished(int result)
{
    Q_UNUSED(result);
    deleteLater();
}
