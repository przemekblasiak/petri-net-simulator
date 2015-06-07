#include "editelementdialog.h"
#include "ui_editelementdialog.h"
#include <QDebug>

EditElementDialog::EditElementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditElementDialog)
{
    ui->setupUi(this);
    ui->livenessLineEdit->setValidator(new QIntValidator(0, 100, this));
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

void EditElementDialog::setDescription(const QString &description)
{
    ui->descriptionLineEdit->setText(description);
    this->description = description;
}

void EditElementDialog::setLiveness(int liveness)
{
    ui->livenessLineEdit->setText(QString::number(liveness));
    this->liveness = liveness;
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
