#include "arrow.h"
#include "ui_arrow.h"

Arrow::Arrow(int x, int y, int x2, int y2, QWidget *parent):
    QFrame(parent),
    ui(new Ui::Arrow)
{
    ui->setupUi(this);
    setGeometry(x, y, x2-x, this->height());

    this->show();
}

Arrow::~Arrow()
{
    delete ui;
}
