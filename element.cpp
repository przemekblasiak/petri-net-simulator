#include "element.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"

Element::Element(QWidget *parent):
    QFrame(parent),
    letter(""), basicStyleSheet(""), offset(0, 0), _selected(false), moving(false), pressed(false), descriptionLabel(0)
{
    // Context menu
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
    connect(this, SIGNAL(removeElementRequested()),
            this->parent(), SLOT(onRemoveElementRequested()));
    connect(this, SIGNAL(modifyElementRequested()),
            this->parent(), SLOT(onModifyElementRequested()));
    connect(this, SIGNAL(elementClicked()),
            this->parent(), SLOT(onElementClicked()));
    connect(this, SIGNAL(selectedElementDestroyed()),
            this->parent(), SLOT(onSelectedElementDestroyed()));
}

Element::~Element() {
    if (_selected){
        emit selectedElementDestroyed();
    }
}

bool Element::selected() const {
    return _selected;
}

void Element::setSelected(bool selected) {
    _selected = selected;
    if (_selected) {
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

void Element::setChildrenClickable(bool clickable) {
    foreach (QObject* child, this->children()) {
        QWidget *widget = qobject_cast<QWidget *>(child);
        if (widget) {
            widget->setAttribute(Qt::WA_TransparentForMouseEvents, !clickable);
        }
    }
}

void Element::mousePressEvent(QMouseEvent *event) {
    bool pressedInnerFrame = this->childAt(event->pos()) == this->findChild<QFrame *>("innerFrame");
    if (pressedInnerFrame) {
        this->pressed = true;
        this->offset = event->pos();
        event->accept();
    } else {
        event->ignore();
    }
}

void Element::mouseMoveEvent(QMouseEvent *event) {
    if (this->pressed) {
        this->moving = true;
        if (event->buttons() & Qt::LeftButton){
            QPoint mappedToParent = mapToParent(event->pos() - offset);
            if (mappedToParent.x() < 0 || mappedToParent.y() < 0){
            }
            else{
                this->move(mapToParent(event->pos() - offset));
            }
            qobject_cast<MatejkoCanvas*>(this->parent())->update();
        }
    }
    event->accept();
}

void Element::mouseReleaseEvent(QMouseEvent *event) {
    bool releasedInnerFrame = this->childAt(event->pos()) == this->findChild<QFrame *>("innerFrame");
    if (releasedInnerFrame) {
        if (this->moving) {
            this->moving = false;
        }
        // If the element was actually clicked (press+release)
        else if (this->pressed){
            emit elementClicked();
        }
        this->pressed = false;
        event->accept();
    }
    else {
        event->ignore();
    }
}

void Element::paintEvent(QPaintEvent *event) {
    if (this->descriptionLabel) {
        QPoint elementCenterRight(this->x() + this->width(), this->y() + this->height()/2);
        int leftMargin = 2;
        int topMargin = 4;
        QPoint insertionPoint(elementCenterRight.x() + leftMargin, elementCenterRight.y() + topMargin);
        this->descriptionLabel->move(insertionPoint);
    }
}

void Element::setDescription(const QString &description) {
    if (!this->descriptionLabel) {
        return;
    }
    this->descriptionLabel->setText(description);
}

QString Element::description() {
    if (!this->descriptionLabel) {
        return "";
    }
    return this->descriptionLabel->text();
}
