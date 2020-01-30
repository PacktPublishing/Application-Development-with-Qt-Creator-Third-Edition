import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 1080 / 2
    height: 1920 / 2

    Item {
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        clip: true

        GridView {
            id: grid
            anchors.fill: parent;
            cellHeight: 190
            cellWidth: 250
            model: ListModel {}
            delegate:  Image {
                width: 240; height: 180
                fillMode: Image.PreserveAspectFit
                source: "image://file/" + path
            }
        }
    }

    Timer {
        interval: 10
        running: true
        repeat: false
        onTriggered: {
            controller.deferredInit()
            grid.model = model
        }
    }
}
