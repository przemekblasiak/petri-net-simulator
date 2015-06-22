#include "graphdialog.h"
#include "ui_graphdialog.h"
#include <QDebug>
#include "simulationengine.h"
#include "state.h"
#include "PNSKit/graph.h"

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

void GraphDialog::drawReachabilityGraph() {
    SimulationEngine &engine = SimulationEngine::getInstance();
    QList<State *> states = engine.generateReachabilityStates(); // TODO: Use State objects instead of pointers

    Graph graph("ReachabilityGraph");
    for (State *state: states) {
        graph.addNode(Graph::Node(state->description(), state->level));
    }
    for (State *state: states) {
        for (State::StateConnection connection: state->outgoingConnections) {
            QString transitionName = "T" + QString::number(connection.transition->number());
            Graph::Node *fromNode = graph.nodeNamed(state->description());
            Graph::Node *toNode = graph.nodeNamed(connection.destination->description());
            if (fromNode && toNode) {
                graph.addEdge(Graph::Edge(transitionName, fromNode, toNode));
            }
        }
    }
    graph.draw(ui->pixmapLabel);

    for (int i = states.count()-1; i >= 0; --i) {
        delete states[i];
    }
}

void GraphDialog::on_GraphDialog_finished(int result)
{
    Q_UNUSED(result);
    deleteLater();
}
