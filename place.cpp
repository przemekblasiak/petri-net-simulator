#include "place.h"
#include "ui_place.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"

int Place::count = 0;

Place::Place(const QPoint &origin, int tokenCount, QWidget *parent) :
    Element(parent),
    ui(new Ui::Place),
    _tokenCount(tokenCount)
{
    ui->setupUi(this);
    this->setChildrenClickable(false);
    this->move(origin);

    this->letter = "P";
    this->setTokenCount(_tokenCount);

    ++Place::count;
    this->setNumber(Place::count);

    this->show();
}

Place::~Place() {
    delete ui;
    --Place::count;
}

int Place::tokenCount()
{
    return _tokenCount;
}

void Place::setTokenCount(int tokenCount) {
    _tokenCount = tokenCount;
    ui->tokenCountLabel->setText(QString::number(_tokenCount));
}

void Place::updateNumber() {
    ui->nameLabel->setText(this->letter + QString::number(this->number()));
}
