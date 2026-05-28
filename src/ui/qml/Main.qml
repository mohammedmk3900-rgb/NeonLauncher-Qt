import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {

    visible: true

    width: 1600
    height: 900

    title: "NeonLauncher"

    color: "#090c10"

    RowLayout {

        anchors.fill: parent

        Sidebar {
            Layout.preferredWidth: 250
        }

        Rectangle {

            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "transparent"

            GridView {

                anchors.fill: parent

                cellWidth: 320
                cellHeight: 220

                model: 12

                delegate: GameCard {}
            }
        }
    }
}
