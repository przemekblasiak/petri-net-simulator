#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pnsglobal.h"
#include "simulationengine.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->matejkoCanvas = ui->matejkoCanvas;
    this->matejkoCanvas->places = &(this->places);
    this->matejkoCanvas->transitions = &(this->transitions);
    this->matejkoCanvas->arrows = &(this->arrows);

    SimulationEngine &engine = SimulationEngine::getInstance();
    engine.places = &(this->places);
    engine.transitions = &(this->transitions);
    engine.arrows = &(this->arrows);

    QWidget* leftSpacer = new QWidget(this);
    QWidget* rightSpacer = new QWidget(this);
    leftSpacer->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    rightSpacer->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Preferred);
    ui->simulationToolBar->insertWidget(ui->actionPreviousTransition, leftSpacer);
    ui->simulationToolBar->addWidget(rightSpacer);

    statusBarLabel = new QLabel("Design mode", this);
    ui->statusBar->addWidget(statusBarLabel);

    ui->simulationToolBar->setEnabled(false);
    ui->statusBar->setStyleSheet("background-color: rgb(165,226,224);");
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
    this->matejkoCanvas->update();
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

void MainWindow::on_actionExecuteTransition_triggered() {
    Element *selectedElement = this->matejkoCanvas->selectedElement();
    if (qobject_cast<Transition *>(selectedElement) && selectedElement->active()) {
        SimulationEngine::getInstance().executeTransition(this->matejkoCanvas->selectedElement());
    }
}

void MainWindow::on_actionToggleSimulationMode_toggled(bool simulationModeOn) {
    matejkoCanvas->setSimulationModeOn(simulationModeOn);
    ui->simulationToolBar->setEnabled(simulationModeOn);
    ui->actionNew_Project->setEnabled(!simulationModeOn);
    ui->actionOpen_project->setEnabled(!simulationModeOn);
    ui->actionSave_project->setEnabled(!simulationModeOn);

    if (simulationModeOn) {
        this->statusBarLabel->setText("Simulation mode");
        ui->statusBar->setStyleSheet("background-color: rgb(180, 255, 180);");
        this->matejkoCanvas->saveBoardState();
        SimulationEngine::getInstance().beginSimulation();
    }
    else {
        this->statusBarLabel->setText("Design mode");
        ui->statusBar->setStyleSheet("background-color: rgb(165,226,224);");
        this->matejkoCanvas->restoreBoardState();
        SimulationEngine::getInstance().endSimulation();
    }
}
