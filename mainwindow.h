#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datahandler.h"
#include "place.h"
#include "transition.h"
#include "matejkocanvas.h"
#include "arrow.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QList<Element *> places;
    QList<Element *> transitions;
    QList<Arrow *> arrows;


private slots:
    void on_actionNew_Project_triggered();
    void on_actionOpen_project_triggered();
    void on_actionSave_project_triggered();

    void on_actionNextTransition_triggered();

    void on_actionPreviousTransition_triggered();

    void on_actionExecuteTransition_triggered();

    void on_actionToggleSimulationMode_toggled(bool arg1);

    void on_actionCoverabilityGraph_triggered();

    void on_actionReachabilityGraph_triggered();

private:
    Ui::MainWindow *ui;
    QString currentProjectFilePath;
    DataHandler dataHandler;
    MatejkoCanvas *matejkoCanvas;
    QLabel *statusBarLabel;
};

#endif // MAINWINDOW_H
