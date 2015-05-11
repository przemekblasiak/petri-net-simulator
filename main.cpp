#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "arrow.h"

//#include "node.h"
#include "place.h"
#include "transition.h"
#include "QDebug"
#include <ctime>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    qmlRegisterType<Arrow>("com.net.petri", 1, 0, "Arrow");
    qmlRegisterType<Place>("com.net.petri", 1, 0, "Place");
    qmlRegisterType<Transition>("com.net.petri", 1, 0, "Transition");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    srand(time(NULL));

    Node *place = new Place();
    qDebug() << place->uuid();

    Node *trans = new Transition();
    qDebug() << trans->uuid();

    delete(place);
    delete(trans);

    return app.exec();
}
