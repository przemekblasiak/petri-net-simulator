#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->matejkoCanvas = ui->matejkoCanvas;

    // Sample places data
    this->places.append(new Place(50, 50, 1, matejkoCanvas));
    this->places.append(new Place(150, 50, 3, matejkoCanvas));
    this->places.append(new Place(50, 150, 0, matejkoCanvas));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Project_triggered()
{
    currentProjectFilePath = QFileDialog::getSaveFileName(this, "Open JSON", ".", "JSON Files (*.json)");
}

void MainWindow::on_actionOpen_project_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open JSON", ".", "JSON Files (*.json)");
    currentProjectFilePath=filename;
//    dataHandler.load(currentProjectFilePath.toStdString(), this->places, this->transitions, this->arrows);
}

void MainWindow::on_actionSave_project_triggered()
{
//    dataHandler.save(currentProjectFilePath.toStdString(), this->places, this->transitions, this->arrows);
}
