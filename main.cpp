#include <QApplication>
#include "mainwindow.h"
#include "datahandler.h"
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication app(argc, argv);

    DataHandler dataHandler;
    dataHandler.saveData();

    MainWindow window;
    window.show();

    return app.exec();
}
