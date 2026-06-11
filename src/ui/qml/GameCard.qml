import QtQuick
import QtQuick.Controls

Rectangle {

    required property string gameName
    required property string gameIcon

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

        onClicked: {
            console.log("Playing game:", gameName)
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
            text: gameName
            color: "#00ffee"
            font.pixelSize: 22
            font.bold: true
        }

        Button {
            text: "PLAY"
            onClicked: {
                console.log("Launching:", gameName)
            }
        }
    }
}
