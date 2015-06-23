#include "reportdialog.h"
#include "ui_reportdialog.h"
#include "simulationengine.h"

ReportDialog::ReportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReportDialog)
{
    ui->setupUi(this);
}

ReportDialog::~ReportDialog()
{
    delete ui;
}

void ReportDialog::transitionLivenesses()
{
    SimulationEngine &simulationEngine = SimulationEngine::getInstance();
    QStringList reportList = simulationEngine.generateLivenessReport();
    for (QString string : reportList){
        ((QVBoxLayout*) ui->scrollAreaWidgetContents->layout())->addWidget(new QLabel(string));
    }

    ((QVBoxLayout*) ui->scrollAreaWidgetContents->layout())->addStretch(1);
}

void ReportDialog::netConservation()
{
    SimulationEngine &simulationEngine = SimulationEngine::getInstance();
    QString conservationReport = simulationEngine.generateConservationReport();
    ((QVBoxLayout*) ui->scrollAreaWidgetContents->layout())->addWidget(new QLabel(conservationReport));
    ((QVBoxLayout*) ui->scrollAreaWidgetContents->layout())->addStretch(1);
}
