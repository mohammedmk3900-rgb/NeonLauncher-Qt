import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects

Rectangle {

    color: "#11151b"
    width: 250
    clip: true

    signal pageChanged(string page)

    Column {

        anchors.fill: parent
        spacing: 0

        // Header
        Rectangle {
            width: parent.width
            height: 100
            color: "#0a0d12"
            border.bottom.color: "#00ffee20"
            border.bottom.width: 1

            Column {
                anchors.fill: parent
                anchors.margins: 15
                spacing: 8
                justifyContent: Column.AlignVCenter

                Text {
                    text: "🚀 NeonLauncher"
                    color: "#00ffee"
                    font.pixelSize: 20
                    font.bold: true
                    renderType: Text.NativeRendering
                }

                Text {
                    text: "Ultimate Game Launcher"
                    color: "#00ffee80"
                    font.pixelSize: 11
                    renderType: Text.NativeRendering
                }
            }
        }

        // Scrollable Navigation
        ScrollView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true

            Column {
                width: parent.width
                spacing: 8
                padding: 15

                // Navigation Items
                SidebarButton {
                    width: parent.width - 30
                    icon: "🏠"
                    label: "Library"
                    selected: true
                    onClicked: pageChanged("library")
                }

                SidebarButton {
                    width: parent.width - 30
                    icon: "🔥"
                    label: "Trending"
                    onClicked: pageChanged("trending")
                }

                SidebarButton {
                    width: parent.width - 30
                    icon: "❤️"
                    label: "Favorites"
                    onClicked: pageChanged("favorites")
                }

                SidebarButton {
                    width: parent.width - 30
                    icon: "🕐"
                    label: "Recently Played"
                    onClicked: pageChanged("recent")
                }

                // Divider
                Rectangle {
                    width: parent.width - 30
                    height: 1
                    color: "#00ffee20"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.topMargin: 8
                    anchors.bottomMargin: 8
                }

                SidebarButton {
                    width: parent.width - 30
                    icon: "🛒"
                    label: "Marketplace"
                    onClicked: pageChanged("marketplace")
                }

                SidebarButton {
                    width: parent.width - 30
                    icon: "🎨"
                    label: "Skins & Themes"
                    onClicked: pageChanged("skins")
                }

                SidebarButton {
                    width: parent.width - 30
                    icon: "🔧"
                    label: "Mods"
                    onClicked: pageChanged("mods")
                }

                // Divider
                Rectangle {
                    width: parent.width - 30
                    height: 1
                    color: "#00ffee20"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.topMargin: 8
                    anchors.bottomMargin: 8
                }

                SidebarButton {
                    width: parent.width - 30
                    icon: "👥"
                    label: "Friends"
                    badge: "3"
                    onClicked: pageChanged("friends")
                }

                SidebarButton {
                    width: parent.width - 30
                    icon: "💬"
                    label: "Community"
                    onClicked: pageChanged("community")
                }

                SidebarButton {
                    width: parent.width - 30
                    icon: "📊"
                    label: "Stats"
                    onClicked: pageChanged("stats")
                }

                Item {
                    Layout.fillHeight: true
                }
            }
        }

        // Footer
        Rectangle {
            width: parent.width
            height: 80
            color: "#0a0d12"
            border.top.color: "#00ffee20"
            border.top.width: 1

            ColumnLayout {
                anchors.fill: parent
                anchors.margins: 12
                spacing: 8

                SidebarButton {
                    Layout.fillWidth: true
                    height: 36
                    icon: "⚙️"
                    label: "Settings"
                    compact: true
                    onClicked: pageChanged("settings")
                }

                SidebarButton {
                    Layout.fillWidth: true
                    height: 36
                    icon: "ℹ️"
                    label: "About"
                    compact: true
                    onClicked: pageChanged("about")
                }
            }
        }
    }
}
