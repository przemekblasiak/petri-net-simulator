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
        Component.onCompleted: {
            var list = engine.getPlaces();
            //list.append(place);
            list[0] = place;
            var list2 = engine.getPlaces();
            console.log(list2);
        }
    }

}
