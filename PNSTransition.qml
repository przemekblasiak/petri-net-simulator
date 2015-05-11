import QtQuick 2.3
import com.net.petri 1.0

Rectangle {
    color: "blue"
    width: 50
    height: 2*width
    objectName: "Transition"

    property alias transition: transition

    Transition{
        id: transition
    }
}

