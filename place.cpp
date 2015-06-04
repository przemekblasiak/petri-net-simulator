#include "place.h"
#include "ui_place.h"
#include <QMenu>

// TODO: mozliwe, ze lista places.count bedzie wystarczajace, wtedy to jest zbedne
int Place::count = 0;

Place::Place(QPoint &origin, int liveness, QWidget *parent) :
    QFrame(parent), liveness(liveness),
    ui(new Ui::Place)
{
    ui->setupUi(this);
    ui->livenessLabel->setText(QString::number(liveness));
    this->setGeometry(origin.x() - this->width()/2, origin.y() - this->height()/2, this->width(), this->height());
    this->show();
    this->makeChildrenNotClickable();

    // Context menu
    this->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(showContextMenu(const QPoint &)));
    connect(this, SIGNAL(removePlaceRequested()),
            this->parent(), SLOT(onRemovePlaceRequested()));
    connect(this, SIGNAL(modifyPlaceRequested()),
            this->parent(), SLOT(onModifyPlaceRequested()));

    ++Place::count;
    this->setNumber(Place::count);
    ui->nameLabel->setText("P" + QString::number(this->number()));
}

Place::~Place()
{
    delete ui;
    --Place::count;
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

void Place::showContextMenu(const QPoint &pos)
{
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

    contextMenu.exec(this->mapToGlobal(pos));
}

void Place::contextActionTriggered(QAction *action)
{
    QMap<QString, QVariant> actionInfo = action->data().toMap();
    ContextActionType actionType = (ContextActionType)actionInfo["Type"].toInt();

    if (actionType == Remove) {
        emit removePlaceRequested();
    }
    else if (actionType == Edit) {
        emit modifyPlaceRequested();
    }
}

int Place::number() const {
    return _number;
}

void Place::setNumber(int number) {
    _number = number;
    ui->nameLabel->setText("P" + QString::number(this->number()));
}


