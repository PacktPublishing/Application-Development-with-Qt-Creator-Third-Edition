import QtQuick 2.12

Rectangle {
    id: button

    width: 128
    height: 64

    property alias label: buttonText.text
    property int delay: 0

    color: "green"

    Rectangle {
        id: shade
        anchors.fill: button;
        color: "black"; opacity: 0
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
            for(var i = 0; i < button.delay; i++);
        }
    }

    states: [
        State {
            name: "pressed"; when: mouseArea.pressed === true
            PropertyChanges { target: shade; opacity: .4 }
        }
    ]
}
