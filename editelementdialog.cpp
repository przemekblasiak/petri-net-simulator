#include "editelementdialog.h"
#include "ui_editelementdialog.h"
#include <QDebug>

EditElementDialog::EditElementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditElementDialog)
{
    ui->setupUi(this);
    ui->tokenLineEdit->setValidator(new QIntValidator(0, 100, this));
}

EditElementDialog::~EditElementDialog()
{
    delete ui;
}

void EditElementDialog::setEditView(EditElementDialog::EditMode mode)
{
    if (mode == EditMode::EditPlace){
        ui->tokenLabel->setVisible(true);
        ui->tokenLineEdit->setVisible(true);
    }
    else if (mode == EditMode::EditTransition) {
        ui->tokenLabel->setVisible(false);
        ui->tokenLineEdit->setVisible(false);
    }
}

void EditElementDialog::setDescription(const QString &description)
{
    ui->descriptionLineEdit->setText(description);
    this->description = description;
}

void EditElementDialog::setTokenCount(int tokenCount)
{
    this->token = tokenCount;
    ui->tokenLineEdit->setText(QString::number(token));
}

void EditElementDialog::on_tokenLineEdit_textEdited(const QString &token)
{
    this->token = token.toInt();
}

void EditElementDialog::on_descriptionLineEdit_textEdited(const QString &description)
{
    this->description = description;
}

void EditElementDialog::on_buttonBox_accepted()
{
    emit tokenChanged(this->token);
    emit descriptionChanged(this->description);
}
