import QtQuick 2.3

Item {
    Rectangle{
        anchors.fill: parent

        BoardContextMenu{id: contextMenu}

        MouseArea{
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                if (mouse.button===Qt.RightButton)
                    contextMenu.popup()
            }
        }
        Canvas{
            id: arrowCanvas
            anchors.fill: parent

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
                context.lineTo(x2, y2);
                context.stroke();
            }
        }
    }
}

