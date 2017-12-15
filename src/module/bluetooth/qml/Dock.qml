import QtQuick 2.0
import org.rde.core 1.0
import org.rde.ui 1.0
ModuleDockItem{
    Tile{anchors.fill:parent}
    Icon{
        id:icon
        anchors{left:parent.left;verticalCenter:parent.verticalCenter;margins:Margin}
        source:Bluetooth.active?'image://Icon/preferences-system-bluetooth':'image://Icon/preferences-system-bluetooth-inactive'
        mouse.onPressed:Bluetooth.toggleAdapter();
    }
    Button{
        id:button
        anchors{top:parent.top;bottom:parent.bottom;right:parent.right;margins:5}
        width:height
        mouse.onClicked:MainWindow.setItem("/Bluetooth/Window.qml",Bluetooth);
        enabled:Bluetooth.active?true:false
    }
    Connections{
        target:Bluetooth
        //onActiveChanged:active?Voice.say("on"):Voice.speak("off")
        onDeviceConnected:Voice.say("device has connected")
        onDeviceDisconnected:Voice.say("device has disconnected")
    }
}