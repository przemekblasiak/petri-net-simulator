#include "place.h"
#include "ui_place.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"

int Place::count = 0;

Place::Place(const QPoint &origin, int liveness, QWidget *parent) :
    Element(parent), liveness(liveness),
    ui(new Ui::Place)
{
    ui->setupUi(this);
    this->setChildrenClickable(false);
    this->move(origin);

    this->letter = "P";
    this->basicStyleSheet = this->styleSheet();
    ui->livenessLabel->setText(QString::number(liveness));

    ++Place::count;
    this->setNumber(Place::count);

    this->show();
}

Place::~Place() {
    delete ui;
    --Place::count;
}

void Place::updateNumber() {
    ui->nameLabel->setText(this->letter + QString::number(this->number()));
}

void Place::setLiveness(int liveness)
{
    ui->livenessLabel->setText(QString::number(liveness));
    this->liveness = liveness;
}
