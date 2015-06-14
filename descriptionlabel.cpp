#include "descriptionlabel.h"
#include "ui_descriptionlabel.h"

DescriptionLabel::DescriptionLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DescriptionLabel) {
    ui->setupUi(this);
    this->setText("");
    this->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
    this->adjustSize();
    this->show();
    this->setAttribute(Qt::WA_TransparentForMouseEvents, true);
}

DescriptionLabel::~DescriptionLabel() {
    delete ui;
}

void DescriptionLabel::setText(const QString &text) {
    ui->descriptionLabel->setText(text);
    if (text != "") {
        ui->descriptionLabel->setHidden(false);
        this->adjustSize();
    } else {
        ui->descriptionLabel->setHidden(true);
    }
}

QString DescriptionLabel::text() {
    return ui->descriptionLabel->text();
}
