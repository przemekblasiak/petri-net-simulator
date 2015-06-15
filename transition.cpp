#include "transition.h"
#include "ui_transition.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"
#include "simulationengine.h"

int Transition::count = 0;

Transition::Transition(const QPoint &origin, QWidget *parent) :
    Element(parent),
    ui(new Ui::Transition),
    _delayLabel(new DescriptionLabel(parent))
{
    ui->setupUi(this);
    this->setChildrenClickable(false);
    this->move(origin);

    this->letter = "T";
    this->delay = 0;

    this->setNumber(Transition::count);
    ++Transition::count;

    connect(&(SimulationEngine::getInstance().timer), SIGNAL(ticked()), this, SLOT(onTicked()));
    _delayLabel->setText(QString::number(this->delay));
    this->show();
}

Transition::~Transition() {
    delete _delayLabel;
    delete ui;
    --Transition::count;
}

void Transition::paintEvent(QPaintEvent *event) {
    Element::paintEvent(event);
    this->adjustDelayLabelPosition();
}

void Transition::adjustDelayLabelPosition() {
    QPoint elementCenterRight(this->x() + this->width(), this->y());
    int leftMargin = 2, topMargin = 2;
    QPoint insertionPoint(elementCenterRight.x() + leftMargin, elementCenterRight.y() + topMargin);
    _delayLabel->move(insertionPoint);
}

void Transition::onTicked()
{

}

void Transition::setDelay(int delay)
{
    this->delay = delay;
    _delayLabel->setText(QString::number(delay));
}

void Transition::updateNumber() {
    ui->nameLabel->setText(this->letter + QString::number(this->number()));
}
