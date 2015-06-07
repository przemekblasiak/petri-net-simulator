#include "place.h"
#include "ui_place.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"

int Place::count = 0;

Place::Place(QPoint &origin, int liveness, QWidget *parent) :
    Element(parent), liveness(liveness),
    ui(new Ui::Place)
{
    ui->setupUi(this);
    this->setGeometry(origin.x() - this->width()/2, origin.y() - this->height()/2, this->width(), this->height());

    // Make only the inner frame clickable
    setChildrenClickable(this, false);
    ui->innerFrame->setAttribute(Qt::WA_TransparentForMouseEvents, false);
    setChildrenClickable(ui->innerFrame, false);

    this->letter = "P";
    this->basicStyleSheet = this->styleSheet();
    ui->livenessLabel->setText(QString::number(liveness));
    this->setDescription("");

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

void Place::setDescription(const QString &description) {
    ui->descriptionLabel->setText(description);
    this->adjustSize();
}

void Place::setLiveness(int liveness)
{
    ui->livenessLabel->setText(QString::number(liveness));
    this->liveness = liveness;
}

QString Place::description() const {
    return ui->descriptionLabel->text();
}

QRect Place::innerFrame() const {
    QPoint topLeft = mapToParent(QPoint(ui->innerFrame->x(), ui->innerFrame->y()));
    QPoint bottomRight = mapToParent(QPoint(ui->innerFrame->x() + ui->innerFrame->width(), ui->innerFrame->y() + ui->innerFrame->height()));
    QRect innerFrame = QRect(topLeft, bottomRight);
    return innerFrame;
}
