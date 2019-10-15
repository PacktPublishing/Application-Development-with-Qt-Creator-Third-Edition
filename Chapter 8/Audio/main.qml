import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12

Window {
    visible: true
    width: 320
    height: 240
    title: qsTr("Play Sound")

    Text {
        text: "Click Me!";
        font.pointSize: 24;
        width: 150; height: 50;

        SoundEffect {
            id: playSound
            source: "soundeffect.wav"
        }

        /*
        Audio {
            id: playMusic
            source: "music.wav"
        }
        */

        MouseArea {
            id: playArea
            anchors.fill: parent
            onPressed: { playSound.play() }
            //onPressed: { playMusic.play() }
        }
    }
}
