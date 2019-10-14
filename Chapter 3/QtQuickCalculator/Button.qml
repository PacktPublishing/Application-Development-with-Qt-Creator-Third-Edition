import QtQuick 2.12

Rectangle {
    id: button

    width: 64
    height: 64
    property alias operation: buttonText.text
    signal clicked

    color: "green"

    Rectangle {
        id: shade
        anchors.fill: button;
        color: "black";
        opacity: 0
    }

    Text {
        id: buttonText
        anchors.centerIn: parent;
        color: "white"
        font.pointSize: 16
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        onClicked: {
            button.clicked();
        }
    }

    states: State {
        name: "pressed"; when: mouseArea.pressed === true
        PropertyChanges { target: shade; opacity: .4 }
    }
}
