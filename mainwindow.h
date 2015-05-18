#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
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

private:
    Ui::MainWindow *ui;
    QString currentProjectFilePath;
};

#endif // MAINWINDOW_H
