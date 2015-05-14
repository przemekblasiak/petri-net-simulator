#include "datahandler.h"

DataHandler::DataHandler()
{
    saveFilePath = "C:\save.json";
}

void DataHandler::saveData()
{
    Json::Value root;
    Json::Value places(Json::arrayValue);

    Place p1(1234, 23, 45);
    Place p2(2345, 34, 4545);
    Place p3(3456, 345, 33);

    Json::Value place1;
    place1["id"] = p1.id;
    place1["x"] = p1.x;
    place1["y"] = p1.y;

    Json::Value place2;;
    place2["id"] = p2.id;
    place2["x"] = p2.x;
    place2["y"] = p2.y;

    Json::Value place3;
    place3["id"] = p3.id;
    place3["x"] = p3.x;
    place3["y"] = p3.y;

    places.append(place1);
    places.append(place2);
    places.append(place3);

    root["places"] = places;
    std::ofstream saveFile = std::ofstream(saveFilePath, std::ofstream::out);
    writer.write(saveFile, root);
}

