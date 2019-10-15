import QtQuick 2.12
import QtQuick.Window 2.12

/*Window {
    visible: true
    width: 360
    height: 360

    ListModel {
        id: model
        ListElement {
            name: "Bill Smith"
            number: "555 3264"
        }
        ListElement {
            name: "John Brown"
            number: "555 8426"
        }
        ListElement {
            name: "Sam Wise"
            number: "555 0473"
        }
    }

    ListView {
        model: model
        anchors.top: parent.top;
        anchors.bottom: parent.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        delegate: Item {
            width: 180
            height: 100
            Column {
                Text { text: name }
                Text { text: number }
            }
        }
    }
}*/

Window {
    visible: true
    width: 360
    height: 360

    ListView {
        model: ContactModel {}
        anchors.top: parent.top;
        anchors.bottom: parent.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
        delegate: ListModelDelegate {}
    }
}
