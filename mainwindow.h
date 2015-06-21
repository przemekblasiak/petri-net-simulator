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
    void clearLists();

    QList<Element *> places;
    QList<Element *> transitions;
    QList<Arrow *> arrows;

    static const QString DefaultWindowTitle;


private slots:
    void on_actionNew_Project_triggered();
    void on_actionOpen_project_triggered();
    void on_actionSave_project_triggered();

    void on_actionNextTransition_triggered();

    void on_actionPreviousTransition_triggered();

    void on_actionExecuteTransition_triggered();

    void on_actionToggleSimulationMode_toggled(bool simulationModeOn);

    void on_actionCoverabilityGraph_triggered();

    void on_actionReachabilityGraph_triggered();

    void on_actionSave_as_triggered();

    void on_actionLiveness_triggered();

private:
    Ui::MainWindow *ui;
    QString currentProjectFilePath;
    DataHandler dataHandler;
    MatejkoCanvas *matejkoCanvas;
    QLabel *statusBarLabel;

    inline void setWindowTitleForProject(const QString &projectPath);
    inline bool resolveIfOverwrite(const QString &projectPath);
};

#endif // MAINWINDOW_H
