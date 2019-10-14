import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 360
    height: 200
    title: qsTr("Calculator")
    color: "grey"

    TextInput {
        id: argument1
        anchors.left: parent.left
        width: 160
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        text: "2"
        font.pointSize: 18
    }

    TextInput {
        id: argument2
        anchors.right: parent.right
        width: 160
        anchors.top: parent.top
        anchors.topMargin: 10
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        text: "2"
        font.pointSize: 18
    }

    Text {
        id: result
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: argument2.bottom
        anchors.topMargin: 10
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        text: "4"
        font.pointSize: 24
    }

    Row {
        id: buttonRow
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        spacing: 20
        Button {
            id: plusButton
            operation: "+"
            onClicked: result.text = parseFloat(argument1.text) + parseFloat(argument2.text)
        }

        Button {
            id: minusButton
            operation: "-"
            onClicked: result.text = parseFloat(argument1.text) - parseFloat(argument2.text)
        }

        Button {
            id: timesButton
            operation: "*"
            onClicked: result.text = parseFloat(argument1.text) * parseFloat(argument2.text)
        }

        Button {
            id: divideButton
            operation: "/"
            onClicked: result.text = parseFloat(argument1.text) / parseFloat(argument2.text)
        }
    }
}
