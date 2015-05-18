#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Project_triggered()
{
    currentProjectFilePath = QFileDialog::getSaveFileName(this, "Open Image", ".", "JSON Files (*.json)");
}

void MainWindow::on_actionOpen_project_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open Image", ".", "JSON Files (*.json)");
    currentProjectFilePath=filename;
    dataHandler.loadData(currentProjectFilePath.toStdString());
}

void MainWindow::on_actionSave_project_triggered()
{
    dataHandler.saveData(currentProjectFilePath.toStdString());
}
