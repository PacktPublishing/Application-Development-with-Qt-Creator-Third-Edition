import QtQuick 2.12

Rectangle {
    property string label: "Something"
    property alias xValue: xValue.text
    property alias yValue: yValue.text
    property alias zValue: zValue.text

    width: parent.width
    height: 32

    Text {
        id: xLabel
        anchors.left: parent.left
        anchors.top: parent.top
        text: label + " X: "
    }
    Text {
        id: xValue
        anchors.left: xLabel.right
        anchors.top: parent.top
        text: "N/A"
    }

    Text {
        id: yLabel
        anchors.right: yValue.left
        anchors.top: parent.top
        text: label + " Y: "
    }

    Text {
        id: yValue
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        text: "N/A"
    }

    Text {
        id: zLabel
        anchors.right: zValue.left
        anchors.top: parent.top
        text: label + " Z: "
    }

    Text {
        id: zValue
        anchors.right: parent.right
        anchors.top: parent.top
        text: "N/A"
    }
}
