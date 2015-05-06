import QtQuick 2.3
import com.net.petri 1.0

Flickable {
    contentWidth: 1920
    contentHeight: 1920

    Rectangle{
        id: board
        z: 2
        anchors.fill: parent
        clip: true

        property Arrow arr;

        function createPlace(x,y){
            var component= Qt.createComponent("Place.qml");
            var place=component.createObject(board)
            place.x=x-place.width/2;
            place.y=y-place.height/2;
        }

        function createTransition(x,y){
            var component= Qt.createComponent("Transition.qml");
            var transition=component.createObject(board)
            transition.x=x-transition.width/2;
            transition.y=y-transition.height/2;
        }


        BoardContextMenu{
            id: contextMenu
            addPlace.onTriggered: board.createPlace(mouseArea.xmouse, mouseArea.ymouse);
            addTransition.onTriggered: board.createTransition(mouseArea.xmouse, mouseArea.ymouse)
        }

        MouseArea{
            id: mouseArea
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton

            property int xmouse;
            property int ymouse;

            onClicked: {
                if (mouse.button===Qt.RightButton){
                    xmouse=mouseX;
                    ymouse=mouseY;
                    contextMenu.popup()
                } else if (mouse.button === Qt.LeftButton) {
                    console.log(board.childAt(mouseX, mouseY).objectName)
                    arrowCanvas.requestPaint()
                }
            }
        }
        Canvas{
            id: arrowCanvas
            anchors.fill: parent
            z: 1

            onPaint: {

                var context = getContext("2d");
                context.reset();

                var beginX, beginY;
                var endX, endY;

                context.beginPath();
                context.lineWidth = 5;
                context.strokeStyle = "black";
                context.moveTo(beginX, beginY);
                context.lineTo(endX, endY);
                context.stroke();
            }
        }
    }
}
