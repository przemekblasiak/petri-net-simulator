#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <json/include/json/reader.h>
#include <json/include/json/writer.h>
#include <json/include/json/value.h>

#include <json/include/json/json.h>

#include <iostream>
#include <fstream>

#include <QList>

#include "element.h"
#include "place.h"
#include "arrow.h"
#include "transition.h"
#include "matejkocanvas.h"

class DataHandler
{
public:
    DataHandler();

    void save(std::string fileName, const QList<Element *> &places, const QList<Element *> &transitions, const QList<Arrow *> &arrows);
    void load(std::string fileName, MatejkoCanvas *matejkoCanvas, QList<Element *> &places, QList<Element *> &transitions, QList<Arrow *> &arrows);

private:
    template <typename T> void clearList(QList<T *> &list);


    Json::Reader reader;
    Json::StyledWriter writer;
};

#endif // DATAHANDLER_H
