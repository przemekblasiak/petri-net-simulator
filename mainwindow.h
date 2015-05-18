#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "datahandler.h"

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

private slots:
    void on_actionNew_Project_triggered();
    void on_actionOpen_project_triggered();
    void on_actionSave_project_triggered();

    QList<QObject *> places;
    QList<QObject *> transitions;
    QList<QObject *> arrows;

private:
    Ui::MainWindow *ui;
    QString currentProjectFilePath;
    DataHandler dataHandler;
};

#endif // MAINWINDOW_H
