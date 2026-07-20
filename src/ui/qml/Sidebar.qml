import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {

    color: "#11151b"
    width: 250

    // Optimize scrolling
    clip: true

    Column {

        spacing: 25
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.margins: 20

        Text {
            text: "NeonLauncher"
            color: "#00ffee"
            font.pixelSize: 24
            font.bold: true
            anchors.horizontalCenter: parent.horizontalCenter
            renderType: Text.NativeRendering
        }

        // Use ListView for memory efficiency with many items
        ListView {

            width: parent.width
            height: contentHeight

            interactive: false
            spacing: 10

            model: sidebarModel

            delegate: Button {

                width: parent.width
                height: 52

                text: modelData.label

                background: Rectangle {
                    color: "#00ffee"
                    opacity: parent.hovered ? 0.2 : 0.1
                    radius: 12

                    // Smooth transitions without expensive animations
                    Behavior on opacity {
                        NumberAnimation { duration: 150 }
                    }
                }

                contentItem: Text {
                    text: parent.text
                    color: "#00ffee"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 14
                    renderType: Text.NativeRendering
                }
            }
        }
    }

    // Move model outside to prevent recreation
    Component.onCompleted: {
        sidebarModel = [
            { icon: "🏠", label: "Library" },
            { icon: "🛒", label: "Marketplace" },
            { icon: "🔧", label: "Mods" },
            { icon: "📥", label: "Downloads" },
            { icon: "👥", label: "Friends" },
            { icon: "🤖", label: "AI" },
            { icon: "⚙️", label: "Settings" }
        ]
    }

    property var sidebarModel: []
}
