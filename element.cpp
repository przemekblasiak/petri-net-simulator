#include "element.h"
#include <QMap>
#include <QVariant>
#include <QAction>
#include <QMenu>
#include "matejkocanvas.h"
#include <QMouseEvent>

Element::Element(QWidget *parent):
    QFrame(parent), letter(""), basicStyleSheet(""), offset(0, 0), _selected(false), moving(false)
{
    // Context menu
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
    connect(this, SIGNAL(removeElementRequested()),
            this->parent(), SLOT(onRemoveElementRequested()));
    connect(this, SIGNAL(modifyElementRequested()),
            this->parent(), SLOT(onModifyElementRequested()));
}

Element::~Element() {
}

void Element::setChildrenClickable(bool clickable) {
    foreach (QObject* child, this->children()) {
        QWidget *widget = qobject_cast<QWidget *>(child);
        if (widget) {
            widget->setAttribute(Qt::WA_TransparentForMouseEvents, !clickable);
        }
    }
}

bool Element::selected() const {
    return _selected;
}

void Element::setSelected(bool selected) {
    if (selected) {
        this->setStyleSheet(this->basicStyleSheet + "border-color: orange;");
    }
    else {
        this->setStyleSheet(this->basicStyleSheet);
    }
}

int Element::number() const {
    return _number;
}

void Element::setNumber(int number) {
    _number = number;
    this->updateNumber();
}

void Element::showContextMenu(const QPoint &position) {
    // TODO: Moze wystarczyloby stworzyc jedno statyczne context menu
    QMap<QString, QVariant> actionInfo;

    QAction editAction("Edit", this);
    actionInfo["Type"] = QVariant(Edit);
    editAction.setData(actionInfo);

    QAction removeAction("Remove", this);
    actionInfo["Type"] = QVariant(Remove);
    removeAction.setData(actionInfo);

    QMenu contextMenu("Context menu");
    contextMenu.addAction(&editAction);
    contextMenu.addSeparator();
    contextMenu.addAction(&removeAction);

    connect(&contextMenu, SIGNAL(triggered(QAction *)),
            this, SLOT(contextActionTriggered(QAction *)));

    contextMenu.exec(this->mapToGlobal(position));
}

void Element::contextActionTriggered(QAction *action) {
    QMap<QString, QVariant> actionInfo = action->data().toMap();
    ContextActionType actionType = (ContextActionType)actionInfo["Type"].toInt();

    if (actionType == Remove) {
        emit removeElementRequested();
    }
    else if (actionType == Edit) {
        emit modifyElementRequested();
    }
}

void Element::onDescriptionChanged(QString description) {
    this->setDescription(description);
}

void Element::mousePressEvent(QMouseEvent *event) {
    this->offset = event->pos();
    event->accept();
}

void Element::mouseMoveEvent(QMouseEvent *event) {
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

void Element::mouseReleaseEvent(QMouseEvent *event) {
    if (this->moving){
        event->accept();
        this->moving = false;
    }
    else{
        event->ignore();
    }
}
