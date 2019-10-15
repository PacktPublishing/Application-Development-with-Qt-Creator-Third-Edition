import QtQuick 2.12
import QtQuick.Window 2.12

/*Window {
    visible: true
    width: 360
    height: 360
    Rectangle {
        id: rect1
        height: 100
        width: 100
        anchors.centerIn: parent
        color: "grey"
    }
    Rectangle {
        id: rect2
        height: 100
        width: 100
        anchors.left: rect1.right
        anchors.top: rect1.top
        color: "black"
    }
}*/

/*Window {
    visible: true
    width: 360
    height: 360

    Rectangle {
        id: rect1
        height: 100
        width: 100
        anchors.left: parent.left;
        anchors.verticalCenter: parent.verticalCenter
        color: "grey"
    }

    Rectangle {
        id: rect2
        anchors.left: rect1.right
        anchors.top: rect1.top;
        anchors.bottom: rect1.bottom
        anchors.right: rect3.left
        color: "black"
    }

    Rectangle {
        id: rect3
        height: 100
        width: 100
        anchors.right: parent.right;
        anchors.verticalCenter: parent.verticalCenter
        color: "grey"
    }
}*/

Window {
    visible: true
    width: 360
    height: 360

    Flow {
        anchors.fill: parent
        anchors.margins: 4
        spacing: 10

        Rectangle { height: 40; width: 40; color: "grey" }
        Rectangle { height: 40; width: 40; color: "black" }
        Rectangle { height: 40; width: 40; color: "grey" }
        Rectangle { height: 40; width: 40; color: "black" }
        Rectangle { height: 40; width: 40; color: "grey" }
        Rectangle { height: 40; width: 40; color: "black" }
        Rectangle { height: 40; width: 40; color: "grey" }
        Rectangle { height: 40; width: 40; color: "black" }
        Rectangle { height: 40; width: 40; color: "grey" }
    }
}
