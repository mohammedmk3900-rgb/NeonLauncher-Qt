import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root
    color: "#11151b"
    implicitWidth: 600
    implicitHeight: 450

    // Properties for Language Support (پشتیبانی از دو زبان فارسی و انگلیسی)
    property bool isEnglish: true 

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20

        // Header & Language Switcher
        RowLayout {
            Layout.fillWidth: function() { return true; }
            
            Text {
                text: root.isEnglish ? "💾 Save Backup & Auto-Save" : "💾 پشتیبان‌گیری و ذخیره خودکار سیو"
                color: "#00ffee"
                font.pixelSize: 18
                font.bold: true
                renderType: Text.NativeRendering
            }

            Item { Layout.fillWidth: true }

            // Language Toggle Button
            Button {
                text: root.isEnglish ? "FA / فارسی" : "EN / English"
                background: Rectangle {
                    color: "#00ffee20"
                    border.color: "#00ffee"
                    border.width: 1
                    radius: 8
                }
                contentItem: Text {
                    text: parent.text
                    color: "#00ffee"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
                onClicked: root.isEnglish = !root.isEnglish
            }
        }

        // Divider
        Rectangle {
            Layout.fillWidth: true
            height: 1
            color: "#00ffee20"
        }

        // Settings Form Layout
        GridLayout {
            columns: 2
            Layout.fillWidth: true
            rowSpacing: 15
            columnSpacing: 15

            // Auto Save Switch Label
            Text {
                text: root.isEnglish ? "Enable Real-Time Auto-Save:" : "فعال‌سازی ذخیره خودکار لحظه‌ای:"
                color: "#00ffee80"
                font.pixelSize: 14
            }

            // Custom Switch (تغییر وضعیت خودکار)
            Switch {
                id: autoSaveSwitch
                checked: false
                onCheckedChanged: {
                    // اتصال به C++ backend در صورت نیاز
                    // saveBackupManager.autoSaveEnabled = checked
                }
                indicator: Rectangle {
                    implicitWidth: 48
                    implicitHeight: 24
                    x: autoSaveSwitch.leftPadding
                    y: parent.height / 2 - height / 2
                    radius: 12
                    color: autoSaveSwitch.checked ? "#00ffee" : "#1a222d"
                    border.color: "#00ffee"
                    border.width: 1

                    Rectangle {
                        x: autoSaveSwitch.checked ? parent.width - width - 2 : 2
                        y: 2
                        width: 20
                        height: 20
                        radius: 10
                        color: autoSaveSwitch.checked ? "#11151b" : "#00ffee80"
                    }
                }
            }

            // Interval Label
            Text {
                text: root.isEnglish ? "Interval (Seconds):" : "بازه زمانی (ثانیه):"
                color: "#00ffee80"
                font.pixelSize: 14
            }

            // Interval SpinBox or TextField for seconds
            SpinBox {
                id: intervalSpinBox
                from: 5
                to: 3600
                value: 30
                editable: true
                Layout.preferredWidth: 120
                onValueChanged: {
                    // saveBackupManager.autoSaveIntervalSeconds = value
                }
            }
        }

        Item { Layout.fillHeight: true }

        // Action Status / Message Box
        Rectangle {
            Layout.fillWidth: true
            height: 40
            color: "#0a0d12"
            border.color: "#00ffee30"
            radius: 8

            Text {
                anchors.centerIn: parent
                text: root.isEnglish ? "Status: Ready for backup monitoring..." : "وضعیت: آماده برای پایش و پشتیبان‌گیری..."
                color: "#00ffee"
                font.pixelSize: 12
            }
        }

        // Manual Backup Action Buttons
        RowLayout {
            Layout.fillWidth: true
            spacing: 15

            Button {
                Layout.fillWidth: true
                height: 40
                background: Rectangle {
                    color: "#00ffee20"
                    border.color: "#00ffee"
                    radius: 8
                }
                contentItem: Text {
                    text: root.isEnglish ? "Create Backup Now" : "ایجاد بکاپ الان"
                    color: "#00ffee"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
                onClicked: {
                    // فراخوانی تابع C++ برای بکاپ دستی
                    // saveBackupManager.createBackup(path, dest)
                }
            }

            Button {
                Layout.fillWidth: true
                height: 40
                background: Rectangle {
                    color: "transparent"
                    border.color: "#00ffee50"
                    radius: 8
                }
                contentItem: Text {
                    text: root.isEnglish ? "Restore Backup" : "بازگردانی بکاپ"
                    color: "#00ffee80"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                onClicked: {
                    // فراخوانی تابع بازگردانی
                }
            }
        }
    }
}
