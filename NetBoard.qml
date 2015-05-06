import QtQuick 2.3

Flickable {
    contentWidth: 1920
    contentHeight: 1920

    Rectangle{
        id: board
        z: 2
        anchors.fill: parent
        clip: true

        function createPlace(x,y){
            var component= Qt.createComponent("Place.qml");
            var place=component.createObject(board, {"x": x-25, "y":y-25})
        }

        function createTransition(x,y){
            var component= Qt.createComponent("Transition.qml");
            var place=component.createObject(board, {"x": x-25, "y":y-25})
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
                    console.log(board.childAt(xmouse, ymouse).objectName)
                    arrowCanvas.requestPaint()
                }
            }
        }
        Canvas{
            id: arrowCanvas
            anchors.fill: parent
            z: 1

            property int x1
            property int x2
            property int y1
            property int y2

            onPaint: {
                var context = getContext("2d");
                context.reset();

                var x1 = 10, y1 = 10;
                var x2 = 100, y2 = 100;

                context.beginPath();
                context.lineWidth = 5;
                context.strokeStyle = "black";
                context.moveTo(x1, y1);
                context.lineTo(mouseArea.mouseX, mouseArea.mouseY);
                context.stroke();
            }
        }
    }
}
