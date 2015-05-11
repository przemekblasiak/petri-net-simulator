import QtQuick 2.3
import com.net.petri 1.0

Rectangle {
    color: "red"
    radius: 25
    width: 50
    height: 50
    objectName: "Place"

    property alias place:place

    Place{
        id: place;
    }

}

