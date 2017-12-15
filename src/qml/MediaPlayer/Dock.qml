import QtQuick 2.0
import org.rde.ui 1.0
RBar{
    anchors.fill: parent
    Info{
        id:infoDisplay
        anchors{top:parent.top;left:parent.left;right:parent.right;margins:Margin}
    }
    ProgressSlider{
        id:progressSlider
        anchors{left:parent.left;right:parent.right;top:infoDisplay.bottom;margins:Margin}
    }
    MediaControls{
        id:mediaControls
        anchors{left:parent.left;right:parent.right;top:progressSlider.bottom;margins:Margin}
    }
    ExtraControls{
        id:extraControls
        anchors{left:parent.left;right:parent.right;top:mediaControls.bottom;margins:Margin}
    }
    MoreControls{
        anchors{left:parent.left;right:parent.right;bottom:parent.bottom;margins:Margin}
    }

    Connections{
        target: MediaPlayer
        onAnnounce:Voice.say(text)
    }
}