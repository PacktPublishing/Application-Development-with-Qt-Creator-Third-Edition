import QtQuick 2.12
import QtQuick.Window 2.12
import QtScxml 5.8

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("State Machine")

    Rectangle {
        id: rectangle
        width: 200
        height: 200
        color: "red"
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    StateMachineLoader {
        id: sm
        source: "qrc:///statemachine.scxml"
        stateMachine.onReachedStableState:
        {
            if (stateMachine.red)
                rectangle.color = "red"
            else if (stateMachine.green)
                rectangle.color = "green"
            else if (stateMachine.blue)
                rectangle.color = "blue"
        }
    }
}
