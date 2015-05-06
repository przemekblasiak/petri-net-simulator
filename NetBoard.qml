import QtQuick 2.3

Flickable {
    contentWidth: 1920
    contentHeight: 1920

    Rectangle{
        id: board
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
                }
            }
        }
    }
}
