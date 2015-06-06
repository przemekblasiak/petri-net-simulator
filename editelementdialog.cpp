#include "editelementdialog.h"
#include "ui_editelementdialog.h"
#include <QDebug>

EditElementDialog::EditElementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditElementDialog)
{
    ui->setupUi(this);
    ui->livenessLineEdit->setValidator(new QIntValidator(0, 100, this));

    connect(ui->livenessLineEdit, SIGNAL(textEdited(QString)), this, SIGNAL(livenessChanged(QString)));
    connect(ui->descriptionLineEdit, SIGNAL(textEdited(QString)), this, SIGNAL(descriptionChanged(QString)));
}

EditElementDialog::~EditElementDialog()
{
    delete ui;
}

void EditElementDialog::setEditView(EditElementDialog::EditMode mode)
{
    if (mode == EditMode::EditPlace){
        ui->livenessLabel->setVisible(true);
        ui->livenessLineEdit->setVisible(true);
    }
    else if (mode == EditMode::EditTransition) {
        ui->livenessLabel->setVisible(false);
        ui->livenessLineEdit->setVisible(false);
    }
}

void EditElementDialog::on_livenessLineEdit_textEdited(const QString &liveness)
{
    this->liveness = liveness.toInt();
}

void EditElementDialog::on_descriptionLineEdit_textEdited(const QString &description)
{
    this->description = description;
}

void EditElementDialog::on_buttonBox_accepted()
{
    emit livenessChanged(this->liveness);
    emit descriptionChanged(this->description);
}
