import QtQuick 2.4

Item {
    width: 400
    height: 400
    property alias rectangle: rectangle
    property alias mouseArea: mouseArea

    Rectangle {
        id: rectangle
        color: "#ff2424"
        anchors.fill: parent

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }
    }
}
