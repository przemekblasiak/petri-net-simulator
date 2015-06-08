#include "datahandler.h"
#include <QPoint>

DataHandler::DataHandler()
{

}

void DataHandler::save(std::string fileName, const QList<Element *> &places, const QList<Element *> &transitions, const QList<Arrow *> &arrows)
{
    // converting Place objects to JSON format
    std::cout << "Found places: " << places.size() << std::endl;
    Json::Value json_places(Json::arrayValue);
    for(int i = 0; i < places.size(); ++i)
    {
        Place *place = dynamic_cast<Place *>(places.at(i));
        Json::Value json_place;
        json_place["number"] = place->number();
        json_place["x"] = place->x();
        json_place["y"] = place->y();
        json_place["liveness"] = place->liveness;
        json_places.append(json_place);
    }

    // converting Transition objects to JSON format
    std::cout << "Found transitions: " << transitions.size() << std::endl;
    Json::Value json_transitions(Json::arrayValue);
    for(int i = 0; i < transitions.size(); ++i)
    {
        Transition *transition = dynamic_cast<Transition *>(transitions.at(i));
        Json::Value json_transition;
        json_transition["number"] = transition->number();
        json_transition["x"] = transition->x();
        json_transition["y"] = transition->y();
        json_transitions.append(json_transition);
    }

    // converting Arrow objects to JSON format
    std::cout << "Found arrows: " << arrows.size() << std::endl;
    Json::Value json_arrows(Json::arrayValue);
    for(int i = 0; i < arrows.size(); ++i)
    {
        Arrow *arrow = arrows.at(i);
        Json::Value json_arrow;
        json_arrow["placeNumber"] = arrow->place->number();
        json_arrow["transitionNumber"] = arrow->transition->number();
        json_arrow["fromPlaceToTransition"] = arrow->fromPlaceToTransition;
        json_arrows.append(json_arrow);
    }

    // preparing JSON root with all Places, Transitions and Arrows
    Json::Value root;
    root["places"] = json_places;
    root["transitions"] = json_transitions;
    root["arrows"] = json_arrows;

    // saving data to JSON file
    std::ofstream saveFile;
    saveFile.open(fileName.c_str());
    saveFile << writer.write(root);
    saveFile.close();
}

void DataHandler::load(std::string fileName, MatejkoCanvas* matejkoCanvas, QList<Element *> &places, QList<Element *> &transitions, QList<Arrow *> &arrows)
{
    // clearing current lists of Places, Transitions and Arrows
    clearList(places);
    clearList(transitions);
    clearList(arrows);

    // loading data from JSON file
    Json::Value root;
    std::ifstream loadFile(fileName.c_str());
    bool parsed = reader.parse(loadFile, root, false);
    if (!parsed)
    {
        // report to the user the failure and their locations in the document.
        std::cout  << "Failed to parse configuration\n" << reader.getFormatedErrorMessages();
    }

    // extracting Places from JSON format and creating Place objects
    const int noOfPlaces = (int) root["places"].size();
    const Json::Value json_places = root["places"];
    for (int i = 0; i < noOfPlaces; ++i)
    {
        const Json::Value current = json_places[Json::Value::UInt(i)];
        const int number = current["number"].asInt();
        const int x = current["x"].asInt();
        const int y = current["y"].asInt();
        const int liveness = current["liveness"].asInt();

        // creating Place object
        //TODO Add matejkocanvas parent
        Place *newPlace = new Place(QPoint(x, y), liveness, matejkoCanvas);
        newPlace->setNumber(number);
        // adding Place object to Places list
        places.append(newPlace);
    }

    // extracting Transitions from JSON format and creating Transition objects
    const int noOfTransitions = (int) root["transitions"].size();
    const Json::Value json_transitions = root["transitions"];
    for (int i = 0; i < noOfTransitions; ++i)
    {
        const Json::Value current = json_transitions[Json::Value::UInt(i)];
        const int number = current["id"].asInt();
        const int x = current["x"].asInt();
        const int y = current["y"].asInt();

        // creating Transition object
        //TODO Add matejkocanvas parent
        Transition *newTransition = new Transition(QPoint(x, y), matejkoCanvas);
        // adding Transition object to Transitions list
        transitions.append(newTransition);
    }

    // extracting Arrows from JSON format and creating Arrow objects
    const int noOfArrows = (int) root["arrows"].size();
    const Json::Value json_arrows = root["arrows"];
    for (int i = 0; i < noOfArrows; ++i)
    {
        const Json::Value current = json_arrows[Json::Value::UInt(i)];
        const bool fromPlaceToTransition = current["fromPlaceToTransition"].asBool();
        const int placeNumber = current["placeNumber"].asInt();
        const int transitionNumber = current["transitionNumber"].asInt();

        // looking for Place to which arrow belongs basing on Place number
        Place *arrowPlace;
        for (int j = 0; j < places.size(); ++j)
        {
            Place *p = dynamic_cast<Place *>(places.at(j));
            if (p->number() == placeNumber)
            {
                arrowPlace = p;
            }
        }

        // looking for Transition to which arrow belongs basing on Transition number
        Transition *arrowTransition;
        for (int j = 0; j < transitions.size(); ++j)
        {
            Transition *t = dynamic_cast<Transition *>(transitions.at(j));
            if (t->number() == transitionNumber)
            {
                arrowTransition = t;
            }
        }

        // creating Arrow object
        Arrow *newArrow = new Arrow(arrowPlace, arrowTransition, fromPlaceToTransition);
        // adding Arrow object to Arrows list
        arrows.append(newArrow);
    }

    //DEBUG INFORMATION
    std::cout << "Places:" << std::endl;
    std::cout << noOfPlaces << std::endl;
    for (int i = 0; i < places.size(); ++i)
    {
        Place *p = dynamic_cast<Place *>(places.at(i));
        std::cout << p->number() << ", " << p->x() << ", " << p->y() << ", " << p->liveness << std::endl;
    }

    std::cout << std::endl << "Transitions:" << std::endl;
    std::cout << noOfTransitions << std::endl;
    for (int i = 0; i < transitions.size(); ++i)
    {
        std::cout << transitions.at(i)->number() << ", " << transitions.at(i)->x() << ", " << transitions.at(i)->y() << std::endl;
    }

    std::cout << std::endl << "Arrows:" << std::endl;
    std::cout << noOfArrows << std::endl;
    for (int i = 0; i < arrows.size(); ++i)
    {
        //std::cout << arrows.at(i)->x1 << ", " << arrows.at(i)->x2 << ", " << arrows.at(i)->y1 << ", " << arrows.at(i)->y2 << std::endl;
    }
}

template <typename T>
void DataHandler::clearList(QList<T *> &list)
{
    for(int i = 0; i < list.size(); ++i)
    {
        delete list.at(i);
    }
    list.clear();
}
