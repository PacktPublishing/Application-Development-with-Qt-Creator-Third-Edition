import QtQuick 2.12
import QtQuick.Window 2.12

Window
{
    visible: true
    height: 360
    width: 360

    Text {
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        text: object.text
    }
}
