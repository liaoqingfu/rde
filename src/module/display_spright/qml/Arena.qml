import QtQuick 2.3
import org.neon.spright 1.0
import org.neon.ui 1.0
ArenaItem{
    id:arenaItem
    anchors.fill:parent
    //focus:true
    Image{
        z:0
        anchors.fill:parent
        source: "file:/games/spright/back.png"
    }
    CharacterModel{
        id:characterModel
    }
    ToolBar{
        id:toolBar
        anchors.top:parent.top
        Button{
            anchors{left:parent.left;top:parent.top;bottom:parent.bottom;margins:Margin}
            width:height
        }
    }
    SpriteList{
        anchors{left:parent.left;top:toolBar.bottom;bottom:parent.bottom}
        width:256
    }
//    Keys{
//        onLeftPressed: Voice.say("left");
//        onRightPressed: Voice.say("right");
//        onUpPressed: Voice.say("up")
//        onDownPressed: Voice.say("down")
//    }
}