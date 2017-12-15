import QtQuick 2.0
import QtMultimedia 5.4
Item {

    MediaPlayer{
        id:mediaPlayer
        source:"file://"+FileManager.selectedFile
        loops:200
    }

    VideoOutput {
        anchors.fill: parent
        source: mediaPlayer
    }

    Component.onCompleted: mediaPlayer.play();
}