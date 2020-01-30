import QtQuick 2.12
import QtQuick.Window 2.12

import MyLib 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MyToast
    {
        id: toast
    }

    MouseArea {
        anchors.fill: parent
        onClicked: toast.callToast("My message here. Hello World!")
    }
}
