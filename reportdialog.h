#ifndef REPORTDIALOG_H
#define REPORTDIALOG_H

#include <QDialog>
#include <QSpacerItem>

namespace Ui {
class ReportDialog;
}

class ReportDialog : public QDialog
{
    Q_OBJECT

public:

    enum ViewType{
        NormalView,
        ConservationView
    };

    explicit ReportDialog(QWidget *parent = 0, ViewType viewType = ViewType::NormalView);
    ~ReportDialog();
    void transitionLivenesses();
    void netConservation();
    void setView(ViewType viewType);
    void netIncidence();

    void reportBoundedness();
    void reportReversability();
private slots:
    void on_acceptButton_clicked();

    void on_vectorButton_clicked();

private:
    Ui::ReportDialog *ui;

    void printMatrix(const QVector<QVector<int> > &matrix);
};

#endif // REPORTDIALOG_H
