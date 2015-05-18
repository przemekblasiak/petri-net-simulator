#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <json/include/json/reader.h>
#include <json/include/json/writer.h>
#include <json/include/json/value.h>

#include <json/include/json/json.h>

#include <iostream>
#include <fstream>

#include "place.h"
#include "transition.h"

class DataHandler
{
public:
    DataHandler();

    void saveData(std::string fileName);
    void loadData(std::string fileName);

private:
    Json::Reader reader;
    Json::StyledWriter writer;
    std::string fileName;
};

#endif // DATAHANDLER_H
