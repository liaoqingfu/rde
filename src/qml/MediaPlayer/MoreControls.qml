import QtQuick 2.0
import org.rde.ui 1.0
Row{
    anchors{left:parent.left;right:parent.right;bottom:parent.bottom;margins:Margin}
    height:48
    spacing:Margin
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        anchors.verticalCenter: parent.verticalCenter
        source:'image://Icon/player-volume-muted'
        enabled:MediaPlayer.allowMute
        mouse.onClicked:MediaPlayer.mute()
    }
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        anchors.verticalCenter: parent.verticalCenter
        source:'image://Icon/media-playlist-shuffle'
        enabled:MediaPlayer.allowShuffle
        mouse.onClicked:MediaPlayer.shuffle()
    }
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        source:'image://Icon/media-playlist-repeat'
        anchors.verticalCenter: parent.verticalCenter
        enabled:MediaPlayer.allowRepeat
        mouse.onClicked:MediaPlayer.repeat()
    }
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        source:'image://Icon/view-media-lyrics'
        anchors.verticalCenter: parent.verticalCenter
        mouse.onClicked:MainWindow.setItem("/MediaPlayer/Window.qml",MediaPlayer);
    }
}