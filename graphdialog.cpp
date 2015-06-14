#include "graphdialog.h"
#include "ui_graphdialog.h"
#include <QDebug>

GraphDialog::GraphDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GraphDialog)
{
    ui->setupUi(this);
    connect(this, SIGNAL(accepted()), this, SLOT(deleteLater()));
}

GraphDialog::~GraphDialog()
{
    delete ui;
}

void GraphDialog::on_GraphDialog_finished(int result)
{
    Q_UNUSED(result);
    deleteLater();
}
