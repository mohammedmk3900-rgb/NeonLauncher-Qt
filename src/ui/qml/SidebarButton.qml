import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Button {

    id: button

    property string icon: ""
    property string label: ""
    property bool selected: false
    property string badge: ""
    property bool compact: false

    implicitHeight: compact ? 36 : 48
    implicitWidth: parent ? parent.width : 200

    background: Rectangle {

        color: selected ? "#00ffee20" : "#11151b"
        radius: 12
        border.color: selected ? "#00ffee" : "transparent"
        border.width: selected ? 2 : 0

        Behavior on color {
            ColorAnimation { duration: 150 }
        }

        Behavior on border.color {
            ColorAnimation { duration: 150 }
        }

        // Hover effect
        Rectangle {
            anchors.fill: parent
            radius: parent.radius
            color: button.hovered ? "#00ffee10" : "transparent"
            opacity: button.pressed ? 0.5 : 1.0

            Behavior on color {
                ColorAnimation { duration: 150 }
            }
        }
    }

    contentItem: RowLayout {

        anchors.fill: parent
        anchors.margins: 12
        spacing: 12

        Text {
            text: icon
            font.pixelSize: compact ? 16 : 20
            color: selected ? "#00ffee" : "#00ffee80"
            renderType: Text.NativeRendering

            Behavior on color {
                ColorAnimation { duration: 150 }
            }
        }

        Text {
            Layout.fillWidth: true
            text: label
            color: selected ? "#00ffee" : "#00ffee80"
            font.pixelSize: compact ? 12 : 14
            font.bold: selected
            elide: Text.ElideRight
            renderType: Text.NativeRendering

            Behavior on color {
                ColorAnimation { duration: 150 }
            }
        }

        // Badge
        Rectangle {

            visible: badge !== ""
            width: 24
            height: 24
            radius: 12
            color: "#00ffee"

            Text {
                anchors.centerIn: parent
                text: badge
                color: "#111827"
                font.pixelSize: 10
                font.bold: true
                renderType: Text.NativeRendering
            }
        }
    }

    ToolTip.text: label
    ToolTip.visible: hovered && !compact
}
