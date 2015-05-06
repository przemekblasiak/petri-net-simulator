#include <QApplication>
#include <QQmlApplicationEngine>

//#include "node.h"
#include "place.h"
#include "transition.h"
#include "QDebug"
#include <ctime>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    srand(time(NULL));

    Node *place = new Place();
    qDebug() << place->id();

    Node *trans = new Transition();
    qDebug() << trans->id();

    delete(place);
    delete(trans);

    return app.exec();
}
