#include "transition.h"
#include "ui_transition.h"
#include <QMenu>
#include "matejkocanvas.h"
#include <QMouseEvent>

int Transition::count = 0;

Transition::Transition(QPoint &origin, QWidget *parent) :
    QFrame(parent), offset(0,0), clicked(false), moving(false),
    ui(new Ui::Transition)
{
    ui->setupUi(this);
    this->setGeometry(origin.x() - this->width()/2, origin.y() - this->height()/2, this->width(), this->height());
    show();
    this->makeChildrenNotClickable();

    // Context menu
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
    connect(this, SIGNAL(removeTransitionRequested()),
            this->parent(), SLOT(onRemoveTransitionRequested()));

    ++Transition::count;
    this->setNumber(Transition::count);
}

Transition::~Transition()
{
    delete ui;
    --Transition::count;
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
bool Transition::isClicked() const
{
    return this->clicked;
}

void Transition::setClicked(bool clicked)
{
    if (clicked){
        this->setStyleSheet(TransitionStyleSheet + "border-color: orange;");
    }
    else
        this->setStyleSheet(TransitionStyleSheet);

}

void Transition::showContextMenu(const QPoint &pos)
{
    QMap<QString, QVariant> actionInfo;

    QAction removeAction("Remove", this);
    actionInfo["Type"] = QVariant(Remove);
    removeAction.setData(actionInfo);

    QMenu contextMenu("Context menu");
    contextMenu.addAction(&removeAction);

    connect(&contextMenu, SIGNAL(triggered(QAction *)),
            this, SLOT(contextActionTriggered(QAction *)));

    contextMenu.exec(this->mapToGlobal(pos));
}

void Transition::contextActionTriggered(QAction *action)
{
    QMap<QString, QVariant> actionInfo = action->data().toMap();
    ContextActionType actionType = (ContextActionType)actionInfo["Type"].toInt();

    if (actionType == Remove) {
        emit removeTransitionRequested();
    }
}

// TODO: Inheritance. M.D.
void Transition::mousePressEvent(QMouseEvent *event)
{
    this->offset = event->pos();
    event->accept();
}

void Transition::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton){
        this->moving = true;
        QPoint mappedToParent = mapToParent(event->pos() - offset);
        if (mappedToParent.x() < 0 || mappedToParent.y() < 0){
        }
        else{
            this->move(mapToParent(event->pos() - offset));
        }
        qobject_cast<MatejkoCanvas*>(this->parent())->update();
    }
    event->accept();
}

void Transition::mouseReleaseEvent(QMouseEvent *event)
{
    if (this->moving){
        event->accept();
        this->moving = false;
    }
    else{
        event->ignore();
    }
}

int Transition::number() const {
    return _number;
}

void Transition::setNumber(int number) {
    _number = number;
    ui->nameLabel->setText("T" + QString::number(this->number()));
}
