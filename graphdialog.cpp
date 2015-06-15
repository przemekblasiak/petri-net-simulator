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

void GraphDialog::prepareReachabilityGraph() {
//    _states = SimulationEngine::getInstance().getReachabilityStates();
    SimulationEngine &engine = SimulationEngine::getInstance();
    QList<State *> states = engine.generateReachabilityStates();

    // Display states
    for (State *state: states) {
        state->setupUi(ui->canvas);
    }

    // TODO: Deallocate states (recursively)
}

void GraphDialog::on_GraphDialog_finished(int result)
{
    Q_UNUSED(result);
    deleteLater();
}
