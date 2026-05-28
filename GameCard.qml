import QtQuick
import QtQuick.Controls

Rectangle {

    width: 280
    height: 180

    radius: 20

    color: "#111827"

    border.color: "#00ffee"
    border.width: 2

    layer.enabled: true

    MouseArea {

        anchors.fill: parent

        hoverEnabled: true

        onEntered: {
            parent.scale = 1.03
        }

        onExited: {
            parent.scale = 1.0
        }
    }

    Behavior on scale {

        NumberAnimation {
            duration: 120
        }
    }

    Column {

        anchors.centerIn: parent

        spacing: 14

        Text {
            text: "Cyberpunk 2077"
            color: "#00ffee"
            font.pixelSize: 22
        }

        Button {
            text: "PLAY"
        }
    }
}