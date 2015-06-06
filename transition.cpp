#include "transition.h"
#include "ui_transition.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"

int Transition::count = 0;

Transition::Transition(QPoint &origin, QWidget *parent) :
    Element(parent),
    ui(new Ui::Transition)
{
    ui->setupUi(this);
    this->setGeometry(origin.x() - this->width()/2, origin.y() - this->height()/2, this->width(), this->height());
    this->setChildrenClickable(false);

    this->letter = "T";
    this->basicStyleSheet = this->styleSheet();
    this->setDescription("");

    ++Transition::count;
    this->setNumber(Transition::count);

    this->show();
}

Transition::~Transition() {
    delete ui;
    --Transition::count;
}

void Transition::updateNumber() {
    ui->nameLabel->setText(this->letter + QString::number(this->number()));
}

void Transition::setDescription(const QString &description) {
    ui->descriptionLabel->setText(description);
    this->adjustSize();
}

QString Transition::description() const {
    return ui->descriptionLabel->text();
}

QRect Transition::innerFrame() const {
    QPoint topLeft = mapToParent(QPoint(ui->innerFrame->x(), ui->innerFrame->y()));
    QPoint bottomRight = mapToParent(QPoint(ui->innerFrame->x() + ui->innerFrame->width(), ui->innerFrame->y() + ui->innerFrame->height()));
    QRect innerFrame = QRect(topLeft, bottomRight);
    return innerFrame;
}
