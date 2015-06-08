#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pnsglobal.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->matejkoCanvas = ui->matejkoCanvas;
    this->matejkoCanvas->places = &(this->places);
    this->matejkoCanvas->transitions = &(this->transitions);
    this->matejkoCanvas->arrows = &(this->arrows);

    QWidget* leftSpacer = new QWidget(this);
    QWidget* rightSpacer = new QWidget(this);
    leftSpacer->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    rightSpacer->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    ui->simulationToolBar->insertWidget(ui->actionPreviousTransition, leftSpacer);
    ui->simulationToolBar->addWidget(rightSpacer);
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
    currentProjectFilePath = filename;
    dataHandler.load(currentProjectFilePath.toStdString(), this->matejkoCanvas, this->places, this->transitions, this->arrows);
}

void MainWindow::on_actionSave_project_triggered()
{
    dataHandler.save(currentProjectFilePath.toStdString(), this->places, this->transitions, this->arrows);
}

void MainWindow::on_actionNextTransition_triggered()
{
}

void MainWindow::on_actionPreviousTransition_triggered()
{
}

void MainWindow::on_actionExecuteTransition_triggered()
{
}
