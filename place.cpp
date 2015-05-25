#include "place.h"
#include "ui_place.h"

Place::Place(int x, int y, int liveness, QWidget *parent) :
    QFrame(parent), liveness(liveness),
    ui(new Ui::Place)
{
    ui->setupUi(this);
    this->setGeometry(x - this->width()/2, y - this->height()/2, this->width(), this->height());
    ui->livenessLabel->setText(QString::number(liveness));
    this->show();
}

Place::~Place()
{
    delete ui;
}
