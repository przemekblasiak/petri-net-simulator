#include "datahandler.h"

DataHandler::DataHandler()
{
    saveFilePath = "save.json";
}

void DataHandler::saveData()
{
    Json::Value root;
    Json::Value places(Json::arrayValue);

    Place *p1 = new Place(23, 45);
    Place *p2 = new Place(34, 4545);
    Place *p3 = new Place(345, 33);

    Json::Value place1;
    place1["id"] = p1->id;
    place1["x"] = p1->x;
    place1["y"] = p1->y;
    place1["liveness"] = p1->liveness;

    Json::Value place2;
    place2["id"] = p2->id;
    place2["x"] = p2->x;
    place2["y"] = p2->y;
    place2["liveness"] = p2->liveness;

    Json::Value place3;
    place3["id"] = p3->id;
    place3["x"] = p3->x;
    place3["y"] = p3->y;
    place3["liveness"] = p3->liveness;

    places.append(place1);
    places.append(place2);
    places.append(place3);

    root["places"] = places;

    delete p1;
    delete p2;
    delete p3;

    std::ofstream saveFile;
    saveFile.open(saveFilePath);
    saveFile << writer.write(root);
    saveFile.close();
}

