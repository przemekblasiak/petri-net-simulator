#include "transition.h"
#include "ui_transition.h"
#include <QMenu>

Transition::Transition(QPoint &origin, QWidget *parent) :
    QFrame(parent),
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
    connect(this, SIGNAL(removeTransitionRequested(Transition&)),
            this->parent(), SLOT(onRemoveTransitionRequested(Transition&)));
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
        emit removeTransitionRequested(*this);
    }
}

