#include "place.h"
#include "ui_place.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"

int Place::count = 0;

Place::Place(const QPoint &origin, int token, QWidget *parent) :
    Element(parent), token(token),
    ui(new Ui::Place)
{
    ui->setupUi(this);
    this->setChildrenClickable(false);
    this->move(origin);

    this->letter = "P";
    this->basicStyleSheet = this->styleSheet();
    ui->tokenLabel->setText(QString::number(token));

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

void Place::settoken(int token)
{
    ui->tokenLabel->setText(QString::number(token));
    this->token = token;
}
