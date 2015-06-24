#include "reportdialog.h"
#include "ui_reportdialog.h"
#include "simulationengine.h"
#include <QInputDialog>

ReportDialog::ReportDialog(QWidget *parent, ReportDialog::ViewType viewType):
    QDialog(parent),
    ui(new Ui::ReportDialog)
{
    ui->setupUi(this);
    this->setView(viewType);
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
        ui->reportTextEdit->append(string);
    }
}

void ReportDialog::netConservation() {
    SimulationEngine &simulationEngine = SimulationEngine::getInstance();
    QString conservationReport = simulationEngine.generateConservationReport();
    ui->reportTextEdit->append(conservationReport);
}

void ReportDialog::reportBoundedness() {
    SimulationEngine &simulationEngine = SimulationEngine::getInstance();
    QString report = simulationEngine.generateBoundednessReport();
    ui->reportTextEdit->append(report);
}

void ReportDialog::reportReversability() {
    SimulationEngine &simulationEngine = SimulationEngine::getInstance();
    QString report = simulationEngine.generateReversabilityReport();
    ui->reportTextEdit->append(report);
}

void ReportDialog::setView(ReportDialog::ViewType viewType)
{
    if (viewType == ViewType::ConservationView){
        ui->vectorButton->setVisible(true);
    }
    else{
        ui->vectorButton->setVisible(false);
    }
}

void ReportDialog::on_acceptButton_clicked()
{
    accept();
}

void ReportDialog::on_vectorButton_clicked()
{
    bool ok;
    QString vectorSize("(" + QString::number(SimulationEngine::getInstance().places->count()) + "):");
    QString vectorString = QInputDialog::getText(this, "Conservation respect to the vector",
                                                 "Vector"+vectorSize, QLineEdit::Normal,
                                                 "eg. 3,5,6,8", &ok);

    QStringList vectorElementsString = vectorString.split(",");
    QVector<int> weights;
    for (QString string : vectorElementsString){
        int value = string.toInt(&ok);
        if (ok) {
            weights.append(value);
        }
    }

    SimulationEngine &simulationEngine = SimulationEngine::getInstance();

    if (weights.count() != simulationEngine.places->count()){
        ui->reportTextEdit->append("<b>Invalid vector size</b>");
    }
    else {
        QString conservation = simulationEngine.generateConservationReportRespectToVector(weights);
        QString conservationReport = "<b>Net conservation for a given vector: " + vectorElementsString.join('\n') + "</b>";
        ui->reportTextEdit->append(conservationReport);
        ui->reportTextEdit->append(conservation);
    }
}
