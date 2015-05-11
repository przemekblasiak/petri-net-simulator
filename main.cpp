#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "arrow.h"

//#include "node.h"
#include "place.h"
#include "transition.h"
#include "engine.h"
#include <QQmlContext>
#include <ctime>

int main(int argc, char *argv[])
{
    srand(time(NULL));

    QApplication app(argc, argv);

    QQmlApplicationEngine appEngine;
    Engine engine;

    qmlRegisterType<Arrow>("com.net.petri", 1, 0, "Arrow");
    qmlRegisterType<Place>("com.net.petri", 1, 0, "Place");
    qmlRegisterType<Transition>("com.net.petri", 1, 0, "Transition");
    appEngine.rootContext()->setContextProperty("engine", &engine);
    appEngine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
