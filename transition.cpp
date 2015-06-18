#include "transition.h"
#include "ui_transition.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"
#include "simulationengine.h"

int Transition::count = 0;

Transition::Transition(const QPoint &origin, QWidget *parent) :
    Element(parent),
    ui(new Ui::Transition),
    _delayLabel(new DescriptionLabel(parent)),
    _delay(0),
    _elapsedTime(0)
{
    ui->setupUi(this);
    this->setChildrenClickable(false);
    this->move(origin);

    this->letter = "T";
    this->setNumber(Transition::count);
    ++Transition::count;

    _delayLabel->setText(QString::number(_delay));
    this->adjustDelayLabelPosition();
    this->show();
}

Transition::~Transition() {
    delete _delayLabel;
    delete ui;
    --Transition::count;
}

void Transition::setActive(bool active)
{
    Element::setActive(active);
    SimulationEngine &engine = SimulationEngine::getInstance();
    // if active and delay > 0
    if (active && _delay) {
        connect(&engine.timer, SIGNAL(ticked()), this, SLOT(onTicked()), Qt::UniqueConnection);
    }
    else {
        disconnect(&engine.timer, SIGNAL(ticked()), this, SLOT(onTicked()));
        _elapsedTime = 0;
    }
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
unsigned Transition::elapsedTime() const
{
    return _elapsedTime;
}

unsigned Transition::delay() const
{
    return _delay;
}


void Transition::onTicked()
{
    ++_elapsedTime;
    _delayLabel->setText(QString::number(_delay - _elapsedTime));
    if (_elapsedTime == _delay){
        SimulationEngine::getInstance().executeTransition(this);
        _elapsedTime = 0;
    }
}

void Transition::setDelay(int delay)
{
    _delay = delay;
    _elapsedTime = 0;
    _delayLabel->setText(QString::number(delay));
}

void Transition::updateNumber() {
    ui->nameLabel->setText(this->letter + QString::number(this->number()));
}
