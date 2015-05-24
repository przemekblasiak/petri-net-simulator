#include "transition.h"
#include "ui_transition.h"

int Transition::defaultWidth = 30;
int Transition::defaultHeight = 60;

Transition::Transition(int x, int y, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Transition)
{
    ui->setupUi(this);
    this->setGeometry(x - defaultWidth/2, y - defaultHeight/2, defaultWidth, defaultHeight);
    show();
}

Transition::~Transition()
{
    delete ui;
}
