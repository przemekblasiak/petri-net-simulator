#include "datahandler.h"
#include <QDebug>

DataHandler::DataHandler()
{

}

void DataHandler::save(std::string fileName, QList<Place *> &places, QList<Transition *> &transitions, QList<Arrow *> &arrows)
{
    Json::Value root;
    Json::Value p(Json::arrayValue);

    Place *p1 = new Place(23, 45, 0);
    Place *p2 = new Place(34, 4545, 0);
    Place *p3 = new Place(345, 33, 0);

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

    p.append(place1);
    p.append(place2);
    p.append(place3);

    root["places"] = p;

    delete p1;
    delete p2;
    delete p3;

    std::ofstream saveFile;
    saveFile.open(fileName.c_str());
    saveFile << writer.write(root);
    saveFile.close();
}

void DataHandler::load(std::string fileName, QList<Place *> &places, QList<Transition *> &transitions, QList<Arrow *> &arrows)
{
        //TODO clearfunction private
    places.clear();
    transitions.clear();
    arrows.clear();

    Json::Value root;
    std::ifstream loadFile(fileName.c_str());
    bool parsed = reader.parse(loadFile, root, false);
    if (!parsed)
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse configuration\n" << reader.getFormatedErrorMessages();
    }

    const int noOfPlaces = (int) root["places"].size();
    const Json::Value json_places = root["places"];
    for (int i = 0; i < noOfPlaces; ++i)
    {
        const Json::Value current = json_places[Json::Value::UInt(i)];
        const int id = current["id"].asInt();
        const int x = current["x"].asInt();
        const int y = current["y"].asInt();
        const int liveness = current["liveness"].asInt();

        Place *tempPlace = new Place(id, x, y, liveness);
        places.append(tempPlace);
    }

    const int noOfTransitions = (int) root["transitions"].size();
    const Json::Value json_transitions = root["transitions"];
    for (int i = 0; i < noOfTransitions; ++i)
    {
        const Json::Value current = json_transitions[Json::Value::UInt(i)];
        const int id = current["id"].asInt();
        const int x = current["x"].asInt();
        const int y = current["y"].asInt();

        Transition *temp = new Transition(id, x, y);
        transitions.append(temp);
    }

    const int noOfArrows = (int) root["arrows"].size();
    const Json::Value json_arrows = root["arrows"];
    for (int i = 0; i < noOfArrows; ++i)
    {
        const Json::Value current = json_arrows[Json::Value::UInt(i)];
        const int x1 = current["x1"].asInt();
        const int x2 = current["x2"].asInt();
        const int y1 = current["y1"].asInt();
        const int y2 = current["y1"].asInt();

        Arrow *temp = new Arrow(x1, x2, y1, y2);
        arrows.append(temp);
    }

    std::cout << "Places:" << std::endl;
    std::cout << noOfPlaces << std::endl;
    for (int i = 0; i < places.size(); ++i)
    {
        std::cout << places.at(i)->id << ", " << places.at(i)->x << ", " << places.at(i)->y << ", " << places.at(i)->liveness << std::endl;
    }

    std::cout << std::endl << "Transitions:" << std::endl;
    std::cout << noOfTransitions << std::endl;
    for (int i = 0; i < transitions.size(); ++i)
    {
        std::cout << transitions.at(i)->id << ", " << transitions.at(i)->x << ", " << transitions.at(i)->y << std::endl;
    }

    std::cout << std::endl << "Arrows:" << std::endl;
    std::cout << noOfArrows << std::endl;
    for (int i = 0; i < arrows.size(); ++i)
    {
        std::cout << arrows.at(i)->x1 << ", " << arrows.at(i)->x2 << ", " << arrows.at(i)->y1 << ", " << arrows.at(i)->y2 << std::endl;
    }
}
