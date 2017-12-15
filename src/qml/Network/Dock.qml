import QtQuick 2.0
import org.rde.ui 1.0
DockItem{
    Button{
        anchors{top:parent.top;bottom:parent.bottom;right:parent.right;margins:Margin}
        width:height

    }

//    Connections{
//        target:Network
//        //onConnecting:Voice.speak("connecting")
//        //onConnected:Voice.speak("connected")
//        //onDisconnected:Voice.speak("disconnected")
//        onOpened:Voice.speak("network connection established")
//        onClosed:Voice.speak("network connection disabled")
//    }
}