import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

ApplicationWindow {
    visible: true
    width: 200
    height: 200
    title: qsTr("Hello World")

    Material.theme: Material.Dark
    Material.accent: Material.Green

    /*Button {
        text: "Push Me"
        anchors.centerIn: parent
    }*/

    Button {
        text: "Push Me"
        highlighted: true
        anchors.centerIn: parent
        Material.accent: Material.Blue
        Material.background: Material.Orange
        Material.foreground: Material.Pink
    }
}
