import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects

ApplicationWindow {

    visible: true

    width: 1600
    height: 900

    title: "NeonLauncher"

    color: "#090c10"

    flags: Qt.Window

    property string currentPage: "library"
    property string searchQuery: ""

    RowLayout {

        anchors.fill: parent
        spacing: 0

        // Sidebar Navigation
        Sidebar {
            id: sidebar
            Layout.preferredWidth: 250
            Layout.fillHeight: true
            onPageChanged: currentPage = page
        }

        // Main Content Area
        StackLayout {

            Layout.fillWidth: true
            Layout.fillHeight: true

            currentIndex: {
                switch(currentPage) {
                    case "library": return 0
                    case "marketplace": return 1
                    case "settings": return 2
                    default: return 0
                }
            }

            // Library Page
            Rectangle {
                color: "transparent"

                ColumnLayout {

                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    // Search Bar
                    Rectangle {

                        Layout.fillWidth: true
                        height: 50

                        color: "#111827"
                        radius: 12
                        border.color: "#00ffee"
                        border.width: 1

                        RowLayout {

                            anchors.fill: parent
                            anchors.margins: 15
                            spacing: 10

                            Image {
                                source: "qrc:/icons/search.svg"
                                width: 24
                                height: 24
                                fillMode: Image.PreserveAspectFit
                            }

                            TextField {

                                id: searchField

                                Layout.fillWidth: true
                                Layout.fillHeight: true

                                placeholderText: "Search games..."
                                background: Rectangle {
                                    color: "transparent"
                                    border.width: 0
                                }

                                color: "#00ffee"
                                placeholderTextColor: "#00ffee80"
                                font.pixelSize: 14

                                onTextChanged: searchQuery = text
                            }

                            Button {
                                text: "🔄"
                                width: 40
                                height: 40
                                
                                background: Rectangle {
                                    color: "#00ffee"
                                    opacity: parent.hovered ? 0.2 : 0.1
                                    radius: 8
                                }

                                onClicked: gameModel.refresh()
                            }
                        }
                    }

                    // Filter/Sort Bar
                    RowLayout {

                        Layout.fillWidth: true
                        height: 40
                        spacing: 10

                        ComboBox {
                            model: ["All Games", "Favorites", "Recent", "A-Z"]
                            background: Rectangle {
                                color: "#111827"
                                radius: 8
                                border.color: "#00ffee"
                                border.width: 1
                            }
                        }

                        Item {
                            Layout.fillWidth: true
                        }

                        Text {
                            text: gamesGrid.count + " games"
                            color: "#00ffee"
                            font.pixelSize: 12
                        }
                    }

                    // Games Grid with Caching
                    GridView {

                        id: gamesGrid

                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        cellWidth: 320
                        cellHeight: 240

                        cacheBuffer: 600

                        model: gameModel

                        delegate: GameCard {
                            gameName: model.name
                            gameIcon: model.icon
                            gameId: model.id
                        }

                        // Loading indicator
                        BusyIndicator {
                            anchors.centerIn: parent
                            running: gamesGrid.count === 0
                            visible: running
                        }

                        // Smooth scrolling
                        flickDeceleration: 3000
                        maximumFlickVelocity: 4000

                        // Scroll bar
                        ScrollBar.vertical: ScrollBar {
                            policy: ScrollBar.AsNeeded
                            background: Rectangle {
                                color: "#111827"
                                radius: 4
                            }
                        }
                    }
                }
            }

            // Marketplace Page
            Rectangle {
                color: "transparent"
                Text {
                    anchors.centerIn: parent
                    text: "Coming Soon: Game Marketplace"
                    color: "#00ffee"
                    font.pixelSize: 24
                }
            }

            // Settings Page
            SettingsPage {
                Layout.fillWidth: true
                Layout.fillHeight: true
            }
        }
    }

    // Game Details Modal
    GameDetailsModal {
        id: gameDetailsModal
        visible: false
    }

    // Notification System
    Rectangle {
        id: notificationPanel
        x: parent.width - 320
        y: 20
        width: 300
        height: 80
        color: "#111827"
        radius: 12
        border.color: "#00ffee"
        border.width: 1
        visible: false
        z: 1000

        Text {
            id: notificationText
            anchors.fill: parent
            anchors.margins: 15
            color: "#00ffee"
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignVCenter
        }

        Timer {
            id: notificationTimer
            interval: 3000
            onTriggered: notificationPanel.visible = false
        }
    }

    function showNotification(message) {
        notificationText.text = message
        notificationPanel.visible = true
        notificationTimer.restart()
    }
}
