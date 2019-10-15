import QtQuick 2.12
import QtQuick.Window 2.12

/*Window {
 visible: true
    width: 256
    height: 256

    Rectangle
    {
        id: button

        anchors.fill: parent

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

        //states: State {
        //    name: "pressed";
        //    when: mouseArea.pressed === true;
        //    PropertyChanges {
        //        target: shade; opacity: .4
        //    }
        //}
        states: [
            State {
                name: "pressed"; when: mouseArea.pressed === true
                PropertyChanges { target: shade; opacity: .4 }
            },
            State {
                name: "released"; when: mouseArea.pressed !== true
                PropertyChanges { target: shade; opacity: 0.0 }
            }
        ]
    }
}*/

/*Window
{
    visible: true
 height: 360
    width: 360

    Rectangle {
        id: rect1
        width: 100; height: 100
        color: "red"

        MouseArea {
            id: mouseArea
            anchors.fill: parent
        }

        states: State {
            name: "moved"; when: mouseArea.pressed
            PropertyChanges { target: rect1; x: 100; y: 100 }
        }

        transitions: Transition {
            NumberAnimation {
                properties: "x,y"
                easing.type: Easing.InOutQuad
            }
        }
    }
}*/

Window
{
    visible: true
    height: 360
    width: 360

    Item {
        width: 300; height: 300

        Rectangle {
            id: rect
            width: 150; height: 100;
            anchors.centerIn: parent
            color: "red"
            antialiasing: true

            states: State {
                name: "rotated"
                PropertyChanges { target: rect; rotation: 180 }
            }

            transitions: Transition {
                RotationAnimation {
                    duration: 1000
                    direction: RotationAnimation.Counterclockwise
                }
            }
        }

        MouseArea {
            anchors.fill: parent;
            onClicked: rect.state = "rotated"
        }
    }
}
