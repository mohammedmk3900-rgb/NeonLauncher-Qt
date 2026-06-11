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
                anchors.margins: 20

                cellWidth: 320
                cellHeight: 220

                // Model will be connected from C++ backend
                model: gameModel

                delegate: GameCard {
                    gameName: model.name
                    gameIcon: model.icon
                }
            }
        }
    }
}
