#include "place.h"
#include "ui_place.h"

int Place::defaultWidth = 30;
int Place::defaultHeight = 30;

Place::Place(int x, int y, int liveness, QWidget *parent) :
    QFrame(parent), liveness(liveness),
    ui(new Ui::Place)
{
    ui->setupUi(this);
    this->setGeometry(x - defaultWidth/2, y - defaultHeight/2, defaultWidth, defaultHeight);
    this->show();
}

Place::~Place()
{
    delete ui;
}
