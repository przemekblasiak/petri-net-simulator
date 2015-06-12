#include "editelementdialog.h"
#include "ui_editelementdialog.h"
#include <QDebug>

EditElementDialog::EditElementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditElementDialog)
{
    ui->setupUi(this);
    ui->tokenCountLineEdit->setValidator(new QIntValidator(0, 100, this));
}

EditElementDialog::~EditElementDialog()
{
    delete ui;
}

void EditElementDialog::setEditView(EditElementDialog::EditMode mode)
{
    if (mode == EditMode::EditPlace){
        ui->tokenCountLabel->setVisible(true);
        ui->tokenCountLineEdit->setVisible(true);
    }
    else if (mode == EditMode::EditTransition) {
        ui->tokenCountLabel->setVisible(false);
        ui->tokenCountLineEdit->setVisible(false);
    }
}

void EditElementDialog::setDescription(const QString &description)
{
    ui->descriptionLineEdit->setText(description);
    this->description = description;
}

void EditElementDialog::setTokenCount(int tokenCount) {
    _tokenCount = tokenCount;
    ui->tokenCountLineEdit->setText(QString::number(_tokenCount));
}

int EditElementDialog::tokenCount() {
    return _tokenCount;
}

void EditElementDialog::on_descriptionLineEdit_textEdited(const QString &description)
{
    this->description = description;
}

void EditElementDialog::on_buttonBox_accepted()
{
    emit tokenCountChanged(_tokenCount);
    emit descriptionChanged(this->description);
}

void EditElementDialog::on_tokenCountLineEdit_textEdited(const QString &tokenCount) {
    _tokenCount = tokenCount.toInt();
}
