#include "editelementdialog.h"
#include "ui_editelementdialog.h"
#include <QDebug>

EditElementDialog::EditElementDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditElementDialog)
{
    ui->setupUi(this);
    ui->tokenCountLineEdit->setValidator(new QIntValidator(0, 100, this));
    ui->weightLineEdit->setValidator(new QIntValidator(0, 100, this));
    ui->delayLineEdit->setValidator(new QIntValidator(0, 100, this));
}

EditElementDialog::~EditElementDialog()
{
    delete ui;
}

void EditElementDialog::setEditView(EditElementDialog::EditMode mode)
{
    ui->tokenCountLabel->setVisible(false);
    ui->tokenCountLineEdit->setVisible(false);
    ui->descriptionLabel->setVisible(false);
    ui->descriptionLineEdit->setVisible(false);
    ui->weightLabel->setVisible(false);
    ui->weightLineEdit->setVisible(false);
    ui->delayLabel->setVisible(false);
    ui->delayLineEdit->setVisible(false);

    if (mode == EditMode::EditPlace){
        ui->tokenCountLabel->setVisible(true);
        ui->tokenCountLineEdit->setVisible(true);
        ui->descriptionLabel->setVisible(true);
        ui->descriptionLineEdit->setVisible(true);
    }
    else if (mode == EditMode::EditTransition) {
        ui->tokenCountLabel->setVisible(false);
        ui->tokenCountLineEdit->setVisible(false);
        ui->delayLabel->setVisible(true);
        ui->delayLineEdit->setVisible(true);
        ui->descriptionLabel->setVisible(true);
        ui->descriptionLineEdit->setVisible(true);
    }
    else if (mode == EditMode::EditArrow){
        ui->weightLabel->setVisible(true);
        ui->weightLineEdit->setVisible(true);
    }
}

void EditElementDialog::setDescription(const QString &description)
{
    ui->descriptionLineEdit->setText(description);
    _description = description;
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
    _description = description;
}

void EditElementDialog::on_buttonBox_accepted()
{
    emit tokenCountChanged(_tokenCount);
    emit descriptionChanged(_description);
    emit weightChanged(_weight);
    emit delayChanged(_delay);
}

void EditElementDialog::on_tokenCountLineEdit_textEdited(const QString &tokenCount) {
    _tokenCount = tokenCount.toInt();
}

void EditElementDialog::on_weightLineEdit_textEdited(const QString &weight)
{
    _weight = weight.toInt();
}
void EditElementDialog::setWeight(int weight)
{
    _weight = weight;
    ui->weightLineEdit->setText(QString::number(weight));
}

void EditElementDialog::setDelay(int delay)
{
    _delay = delay;
    ui->delayLineEdit->setText(QString::number(delay));
}


void EditElementDialog::on_delayLineEdit_textEdited(const QString &delay)
{
    _delay = delay.toInt();
}
