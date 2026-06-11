import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {

    color: "#11151b"
    width: 250

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
        }

        Repeater {

            model: [
                { icon: "🏠", label: "Library" },
                { icon: "🛒", label: "Marketplace" },
                { icon: "🔧", label: "Mods" },
                { icon: "📥", label: "Downloads" },
                { icon: "👥", label: "Friends" },
                { icon: "🤖", label: "AI" },
                { icon: "⚙️", label: "Settings" }
            ]

            delegate: Button {

                text: modelData.label
                anchors.left: parent.left
                anchors.right: parent.right

                width: parent.width
                height: 52

                background: Rectangle {
                    color: "#00ffee"
                    opacity: parent.hovered ? 0.2 : 0.1
                    radius: 12
                }

                contentItem: Text {
                    text: parent.text
                    color: "#00ffee"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 14
                }

                Behavior on background.opacity {
                    NumberAnimation { duration: 150 }
                }
            }
        }
    }
}
