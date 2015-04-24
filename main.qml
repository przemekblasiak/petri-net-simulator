import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    title: qsTr("Petri Net Simulator")
    width: 640
    height: 480
    visible: true

    toolBar: ToolBar {
        RowLayout {
            anchors.fill: parent
            ToolButton {
                iconSource: "qrc:/images/images/add.svg"
            }
            ToolButton {
                iconSource: "qrc:/images/images/save.svg"
            }
            ToolButton {
                iconSource: "qrc:/images/images/open.svg"
            }
            Item { Layout.fillWidth: true }
        }
    }
}
