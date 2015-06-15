#include "transition.h"
#include "ui_transition.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"
#include "simulationengine.h"

int Transition::count = 0;

Transition::Transition(const QPoint &origin, QWidget *parent) :
    Element(parent),
    ui(new Ui::Transition)
{
    ui->setupUi(this);
    this->setChildrenClickable(false);
    this->move(origin);

    this->letter = "T";

    this->setNumber(Transition::count);
    ++Transition::count;

    connect(&(SimulationEngine::getInstance().timer), SIGNAL(ticked()), this, SLOT(onTicked));
    this->show();
}

Transition::~Transition() {
    delete ui;
    --Transition::count;
}

void Transition::onTicked()
{

}

void Transition::updateNumber() {
    ui->nameLabel->setText(this->letter + QString::number(this->number()));
}
