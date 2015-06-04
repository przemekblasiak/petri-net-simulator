#include "element.h"
#include <QMap>
#include <QVariant>
#include <QAction>
#include <QMenu>

Element::Element(QPoint &origin, QWidget *parent): QFrame(parent), letter(""), basicStyleSheet("") {
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

bool Element::clicked() const {
    return _clicked;
}

void Element::setClicked(bool clicked) {
    if (clicked) {
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
