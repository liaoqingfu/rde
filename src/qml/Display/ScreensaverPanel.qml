import QtQuick 2.0
Item{
    anchors.fill: parent

    Rectangle{
        z:0
        anchors.fill: parent
        color:'purple'
        opacity:0.5
        //border.width:1
        //border.color:'purple'
    }
//    ControlBox{
//        id:controlBox
//        anchors{left:parent.left;top:parent.top;right:parent.right;margins:Margin}
//    }
//    ModuleRack{
//        id:moduleRack
//        anchors{top:controlBox.bottom;left:parent.left;right:parent.right;bottom:parent.bottom;margins:Margin}
//    }



    ScreensaverList{
        anchors{left:parent.left;top:parent.top;bottom:parent.bottom;margins:Margin}
        width:320
    }

    //Component.onCompleted: Voice.speak("cat")
}