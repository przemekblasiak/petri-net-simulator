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
    }
}

