#include <QApplication>
#include "mainwindow.h"
#include "datahandler.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

//    DataHandler dh;
//    dh.saveData();

    MainWindow window;
    window.show();

    return app.exec();
}
