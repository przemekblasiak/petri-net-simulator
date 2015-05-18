#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <json/include/json/reader.h>
#include <json/include/json/writer.h>
#include <json/include/json/value.h>

#include <json/include/json/json.h>

#include <iostream>
#include <fstream>

#include <QList>

#include "place.h"
#include "transition.h"
#include "arrow.h"

class DataHandler
{
public:
    DataHandler();

    void save(std::string fileName, QList<Place *> places, QList<Transition *> transitions, QList<Arrow *> arrows);
    void load(std::string fileName, QList<Place *> places, QList<Transition *> transitions, QList<Arrow *> arrows);

private:
    Json::Reader reader;
    Json::StyledWriter writer;
};

#endif // DATAHANDLER_H
