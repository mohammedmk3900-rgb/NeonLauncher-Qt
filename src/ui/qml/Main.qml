import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {

    visible: true

    width: 1600
    height: 900

    title: "NeonLauncher"

    color: "#090c10"

    // Prevent unnecessary redraws
    flags: Qt.Window | Qt.FramelessWindowHint

    // Enable caching for better performance
    renderType: Text.NativeRendering

    RowLayout {

        anchors.fill: parent
        spacing: 0

        Sidebar {
            Layout.preferredWidth: 250
            Layout.fillHeight: true
        }

        Rectangle {

            Layout.fillWidth: true
            Layout.fillHeight: true

            color: "transparent"

            // Use ListView instead of GridView for better memory
            GridView {

                id: gamesGrid

                anchors.fill: parent
                anchors.margins: 20

                cellWidth: 320
                cellHeight: 220

                // Cache buffer for smooth scrolling
                cacheBuffer: 400

                // Model will be connected from C++ backend
                model: gameModel

                // Optimize delegate creation
                delegate: GameCard {
                    gameName: model.name
                    gameIcon: model.icon
                    
                    // Lazy load images
                    asynchronous: true
                }

                // Scroll performance
                flickDeceleration: 3000

                // Add loading indicator
                BusyIndicator {
                    anchors.centerIn: parent
                    running: gamesGrid.count === 0
                    visible: running
                }
            }
        }
    }
}
