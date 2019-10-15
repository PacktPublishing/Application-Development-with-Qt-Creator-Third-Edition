import QtQuick 2.12
import QtQuick.Window 2.12
import QtWebEngine 1.8

Window {
    visible: true
    width: 640
    height: 480

    WebEngineView {
        anchors.top: parent.top;
        anchors.left: parent.left
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
        id: web
        url: "http://www.zhieng.com"
    }
}
