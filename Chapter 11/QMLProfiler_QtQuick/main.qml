import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Component.onCompleted: {
        var component = Qt.createComponent("myRectangle.qml");

        for (var i = 0; i < 200; i++)
        {
            var x = Math.floor((Math.random() * window.width) + 1);
            var y = Math.floor((Math.random() * window.height) + 1);

            //Qt.createQmlObject('import QtQuick 2.12; Rectangle {color: "red"; width: 20; height: 20; x: ' + x + '; y: ' + y + ';}', window, 'rect');
            component.createObject(window, {x: x, y: y});
        }
    }
}
