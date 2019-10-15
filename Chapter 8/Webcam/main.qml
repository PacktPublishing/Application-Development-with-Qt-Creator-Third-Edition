import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Webcam")

    Item {
        width: 640
        height: 360

        Camera {
            id: camera

            imageCapture {
                onImageCaptured: {
                    // Show the preview in an Image
                    photoPreview.source = preview
                }
            }
        }

        VideoOutput {
            source: camera
            focus : visible // to receive focus and capture key events
            width: 320
            height: 180
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter

            MouseArea {
                anchors.fill: parent;
                onClicked: camera.imageCapture.capture();
            }
        }

        Image {
            id: photoPreview
            width: 320
            height: 180
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
}
