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
                iconSource: "qrc:/images/images/new_project.svg"
                tooltip: "Start new project"
            }
            ToolButton {
                iconSource: "qrc:/images/images/save_project.svg"
                tooltip: "Save project"
            }
            ToolButton {
                iconSource: "qrc:/images/images/open_project.svg"
                tooltip: "Open existing project"
            }
            ToolButton {
                iconSource: "qrc:/images/images/run_simulation.svg"
                anchors.horizontalCenter: parent.horizontalCenter
                tooltip: "Start simulation"
            }
            Item { Layout.fillWidth: true; }
        }
    }
}
