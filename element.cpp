#include "element.h"
#include "matejkocanvas.h"
#include "pnsglobal.h"

QString Element::selectedAttribute = "border-color: orange;";
QString Element::activeAttribute = "background-color: rgb(180, 255, 180);";

Element::Element(QWidget *parent):
    QFrame(parent),
    letter(""),
    moving(false),
    pressed(false),
    offset(0, 0),
    _selected(false),
    _description(""),
    _number(0),
    _active(false),
    _descriptionLabel(new DescriptionLabel(parent)),
    _simulationModeOn(false)
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
    connect(this->parent(), SIGNAL(simulationModeOnChanged(bool)),
            this, SLOT(setSimulationModeOn(bool)));
}

Element::~Element() {
    delete _descriptionLabel;
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
        this->setStyleSheet(this->styleSheet().append(Element::selectedAttribute));
    }
    else {
        this->setStyleSheet(this->styleSheet().remove(Element::selectedAttribute));
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
    if (_simulationModeOn){
        return;
    }
    // TODO: Moze wystarczyloby stworzyc jedno statyczne context menu
    QMap<QString, QVariant> actionInfo;

    QAction editAction("Edit", this);
    actionInfo["Type"] = QVariant(ContextActionType::Edit);
    editAction.setData(actionInfo);

    QAction removeAction("Remove", this);
    actionInfo["Type"] = QVariant(ContextActionType::Remove);
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

    if (actionType == ContextActionType::Remove) {
        emit removeElementRequested();
    }
    else if (actionType == ContextActionType::Edit) {
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
    if (_simulationModeOn){
        return;
    }
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

void Element::paintEvent(QPaintEvent *) {
    this->adjustDescriptionLabelPosition();
}
bool Element::simulationModeOn() const
{
    return _simulationModeOn;
}


void Element::adjustDescriptionLabelPosition() {
    QPoint elementCenterRight(this->x() + this->width(), this->y() + this->height()/2);
    int leftMargin = 2, topMargin = 4;
    QPoint insertionPoint(elementCenterRight.x() + leftMargin, elementCenterRight.y() + topMargin);
    _descriptionLabel->move(insertionPoint);
}

void Element::setDescription(const QString &description) {
    _description = description;
    if (_description == "") {
        _descriptionLabel->setHidden(true);
    }
    else {
        _descriptionLabel->setHidden(false);
    }
    _descriptionLabel->setText(description);
    this->adjustDescriptionLabelPosition();
}

void Element::setSimulationModeOn(bool on)
{
    _simulationModeOn = on;
}

QString Element::description() {
    return _description;
}

void Element::setActive(bool active) {
    _active = active;
    if (_active) {
        this->setStyleSheet(this->styleSheet().append(Element::activeAttribute));
    }
    else {
        this->setStyleSheet(this->styleSheet().remove(Element::activeAttribute));
    }
    this->update();
}

bool Element::active() {
    return _active;
}
