#include "datahandler.h"

//DataHandler::DataHandler()
//{

//}

//void DataHandler::save(std::string fileName, const QList<Place *> &places, const QList<Transition *> &transitions, const QList<Arrow *> &arrows)
//{
//    std::cout << places.size() << std::endl;
//    Json::Value json_places(Json::arrayValue);
//    for(int i = 0; i < places.size(); ++i)
//    {
//        Place *place = places.at(i);
//        Json::Value json_place;
//        json_place["id"] = place->id;
//        json_place["x"] = place->x;
//        json_place["y"] = place->y;
//        json_place["liveness"] = place->liveness;
//        json_places.append(json_place);
//    }

//    Json::Value json_transitions(Json::arrayValue);
//    for(int i = 0; i < transitions.size(); ++i)
//    {
//        Transition *transition = transitions.at(i);
//        Json::Value json_transition;
//        json_transition["id"] = transition->id;
//        json_transition["x"] = transition->x;
//        json_transition["y"] = transition->y;
//        json_transitions.append(json_transition);
//    }

//    Json::Value json_arrows(Json::arrayValue);
//    for(int i = 0; i < arrows.size(); ++i)
//    {
//        Arrow *arrow = arrows.at(i);
//        Json::Value json_arrow;
//        json_arrow["x1"] = arrow->x1;
//        json_arrow["x2"] = arrow->x2;
//        json_arrow["y1"] = arrow->y1;
//        json_arrow["y2"] = arrow->y2;
//        json_arrows.append(json_arrow);
//    }

//    Json::Value root;
//    root["places"] = json_places;
//    root["transitions"] = json_transitions;
//    root["arrows"] = json_arrows;

//    std::ofstream saveFile;
//    saveFile.open(fileName.c_str());
//    saveFile << writer.write(root);
//    saveFile.close();
//}

//void DataHandler::load(std::string fileName, QList<Place *> &places, QList<Transition *> &transitions, QList<Arrow *> &arrows)
//{
//    clearList(places);
//    clearList(transitions);
//    clearList(arrows);

//    Json::Value root;
//    std::ifstream loadFile(fileName.c_str());
//    bool parsed = reader.parse(loadFile, root, false);
//    if (!parsed)
//    {
//        // report to the user the failure and their locations in the document.
//        std::cout  << "Failed to parse configuration\n" << reader.getFormatedErrorMessages();
//    }

//    const int noOfPlaces = (int) root["places"].size();
//    const Json::Value json_places = root["places"];
//    for (int i = 0; i < noOfPlaces; ++i)
//    {
//        const Json::Value current = json_places[Json::Value::UInt(i)];
//        const int id = current["id"].asInt();
//        const int x = current["x"].asInt();
//        const int y = current["y"].asInt();
//        const int liveness = current["liveness"].asInt();

//        Place *tempPlace = new Place(id, x, y, liveness);
//        places.append(tempPlace);
//    }

//    const int noOfTransitions = (int) root["transitions"].size();
//    const Json::Value json_transitions = root["transitions"];
//    for (int i = 0; i < noOfTransitions; ++i)
//    {
//        const Json::Value current = json_transitions[Json::Value::UInt(i)];
//        const int id = current["id"].asInt();
//        const int x = current["x"].asInt();
//        const int y = current["y"].asInt();

//        Transition *temp = new Transition(id, x, y);
//        transitions.append(temp);
//    }

//    const int noOfArrows = (int) root["arrows"].size();
//    const Json::Value json_arrows = root["arrows"];
//    for (int i = 0; i < noOfArrows; ++i)
//    {
//        const Json::Value current = json_arrows[Json::Value::UInt(i)];
//        const int x1 = current["x1"].asInt();
//        const int x2 = current["x2"].asInt();
//        const int y1 = current["y1"].asInt();
//        const int y2 = current["y1"].asInt();

//        Arrow *temp = new Arrow(x1, x2, y1, y2);
//        arrows.append(temp);
//    }

//    //DEBUG INFORMATION
//    std::cout << "Places:" << std::endl;
//    std::cout << noOfPlaces << std::endl;
//    for (int i = 0; i < places.size(); ++i)
//    {
//        std::cout << places.at(i)->id << ", " << places.at(i)->x << ", " << places.at(i)->y << ", " << places.at(i)->liveness << std::endl;
//    }

//    std::cout << std::endl << "Transitions:" << std::endl;
//    std::cout << noOfTransitions << std::endl;
//    for (int i = 0; i < transitions.size(); ++i)
//    {
//        std::cout << transitions.at(i)->id << ", " << transitions.at(i)->x << ", " << transitions.at(i)->y << std::endl;
//    }

//    std::cout << std::endl << "Arrows:" << std::endl;
//    std::cout << noOfArrows << std::endl;
//    for (int i = 0; i < arrows.size(); ++i)
//    {
//        std::cout << arrows.at(i)->x1 << ", " << arrows.at(i)->x2 << ", " << arrows.at(i)->y1 << ", " << arrows.at(i)->y2 << std::endl;
//    }
//}

//template <typename T>
//void DataHandler::clearList(QList<T *> &list)
//{
//    for(int i = 0; i < list.size(); ++i)
//    {
//        delete list.at(i);
//    }
//    list.clear();
//}
