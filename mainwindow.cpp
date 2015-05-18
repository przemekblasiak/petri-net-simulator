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
    currentProjectFilePath = QFileDialog::getSaveFileName(this, "Open Image", ".", "Image Files (*.png *.jpg *.bmp)");
}

void MainWindow::on_actionOpen_project_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open Image", ".", "Image Files (*.png *.jpg *.bmp)");
    //    davidLoadOperation(filename);
    currentProjectFilePath=filename;
}

void MainWindow::on_actionSave_project_triggered()
{
    //    davidSaveOperation(currentProjectFilePath);
}
