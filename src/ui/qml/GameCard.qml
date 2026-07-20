import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects

Rectangle {

    required property string gameName
    required property string gameIcon

    width: 280
    height: 180

    radius: 20

    color: "#111827"

    border.color: "#00ffee"
    border.width: 2

    // Optimize shadow rendering
    layer.enabled: hoverArea.containsMouse
    layer.effect: MultiEffect {
        shadowEnabled: true
        shadowBlur: 10
        shadowScale: 1.02
    }

    MouseArea {

        id: hoverArea

        anchors.fill: parent

        hoverEnabled: true
        cursorShape: Qt.PointingHandCursor

        onEntered: {
            scaleAnimation.to = 1.03
            scaleAnimation.start()
        }

        onExited: {
            scaleAnimation.to = 1.0
            scaleAnimation.start()
        }

        onClicked: {
            console.log("Playing game:", gameName)
        }
    }

    // Use ScaleAnimator for better performance
    ScaleAnimator {
        id: scaleAnimation
        target: parent
        duration: 120
        easing.type: Easing.OutQuad
    }

    Column {

        anchors.centerIn: parent

        spacing: 14

        // Cache text rendering
        Text {
            id: gameTitle
            text: gameName
            color: "#00ffee"
            font.pixelSize: 22
            font.bold: true
            renderType: Text.NativeRendering
            elide: Text.ElideRight
            width: parent.width - 20
        }

        Button {
            text: "PLAY"
            
            background: Rectangle {
                color: "#00ffee"
                radius: 8
                opacity: parent.pressed ? 0.8 : 0.6
                
                Behavior on opacity {
                    NumberAnimation { duration: 100 }
                }
            }
            
            contentItem: Text {
                text: parent.text
                color: "#111827"
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            
            onClicked: {
                console.log("Launching:", gameName)
            }
        }
    }
}
