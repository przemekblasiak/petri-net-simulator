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
    this->makeChildrenNotClickable();
}

Place::~Place()
{
    delete ui;
}

void Place::makeChildrenNotClickable()
{
    foreach (QObject* child, this->children()) {
        QWidget *widget = qobject_cast<QWidget *>(child);
        if (widget){
            widget->setAttribute(Qt::WA_TransparentForMouseEvents);
        }
    }
}
bool Place::isClicked() const
{
    return this->clicked;
}

void Place::setClicked(bool clicked)
{
    if (clicked){
        this->setStyleSheet(PlaceStyleSheet + "border-color: orange;");
    }
    else
        this->setStyleSheet(PlaceStyleSheet);
}

