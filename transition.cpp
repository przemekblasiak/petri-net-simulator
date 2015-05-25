#include "transition.h"
#include "ui_transition.h"

Transition::Transition(int x, int y, QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Transition)
{
    ui->setupUi(this);
    this->setGeometry(x - this->width()/2, y - this->height()/2, this->width(), this->height());
    show();
    this->makeChildrenNotClickable();
}

Transition::~Transition()
{
    delete ui;
}

// TODO use inheritance
void Transition::makeChildrenNotClickable()
{
    foreach (QObject* child, this->children()) {
        QWidget *widget = qobject_cast<QWidget *>(child);
        if (widget){
            widget->setAttribute(Qt::WA_TransparentForMouseEvents);
        }
    }
}
