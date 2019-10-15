import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12

Window {
    visible: true
    width: 800
    height: 600
    title: qsTr("Play Video")

    /*Video {
        id: video
        width : 800
        height : 600
        source: "video.avi"

        MouseArea {
            anchors.fill: parent
            onClicked: {
                video.play()
            }
        }

        focus: true
        Keys.onSpacePressed:
            video.playbackState == MediaPlayer.PlayingState ?
                video.pause() :
                video.play()
    }*/

    Rectangle {
        width: 800
        height: 600
        color: "black"

        MediaPlayer {
            id: player
            source: "video.avi"
            autoPlay: true
        }

        VideoOutput {
            id: videoOutput
            source: player
            anchors.fill: parent
        }
    }
}
