#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <json/include/json/reader.h>
#include <json/include/json/writer.h>
#include <json/include/json/value.h>

#include <json/include/json/json.h>

#include "place.h"
#include "transition.h"
#include <iostream>
#include <fstream>

class DataHandler
{
public:
    DataHandler();

    void saveData();
    void loadData();

private:
    Json::Reader reader;
    Json::StyledWriter writer;
    std::string saveFilePath;
};

#endif // DATAHANDLER_H
