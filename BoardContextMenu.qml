import QtQuick.Controls 1.2

Menu{
    id: contextMenu
    property alias addPlace: addPlace
    property alias addTransition: addTransition

    MenuItem{
        id: addPlace
        text: "Add Place"
    }
    MenuItem{
        id: addTransition
        text: "Add Transition"
    }
}

