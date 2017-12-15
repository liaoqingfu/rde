import QtQuick 2.0
import org.rde.ui 1.0
Row{
    spacing:8
    height:48
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        anchors.verticalCenter: parent.verticalCenter
        source:'image://Icon/media-skip-backward';
        mouse.onClicked:MediaPlayer.previous();
        //enabled:MediaPlayer.allowPrevious
    }
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        anchors.verticalCenter: parent.verticalCenter
        source:'image://Icon/media-seek-backward'
        mouse.onPressed:MediaPlayer.seekBackward()
        mouse.onReleased:MediaPlayer.stopSeeking()
        //enabled:MediaPlayer.allowSeeking
    }
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        anchors.verticalCenter: parent.verticalCenter
        source:'image://Icon/media-playback-start';
        mouse.onClicked:MediaPlayer.play()
        //enabled:MediaPlayer.allowPlay
    }
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        anchors.verticalCenter: parent.verticalCenter
        source:'image://Icon/media-playback-stop';
        mouse.onClicked:MediaPlayer.stop();
        //enabled:MediaPlayer.allowStop
    }
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        anchors.verticalCenter: parent.verticalCenter
        source:'image://Icon/media-seek-forward';
        mouse.onPressed:MediaPlayer.seekForward()
        mouse.onReleased:MediaPlayer.stopSeeking()
        //enabled:MediaPlayer.allowSeeking
    }
    RIcon{
        sourceSize{width:32;height:32}
        width:32
        height:32
        anchors.verticalCenter: parent.verticalCenter
        source:'image://Icon/media-skip-forward';
        mouse.onClicked:MediaPlayer.next();
        //enabled:MediaPlayer.allowNext
    }
}