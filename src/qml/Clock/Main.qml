import QtQuick 2.0
import org.rde.ui 1.0
DockItem{
    Button{
        id:button
        anchors{right:parent.right;top:parent.top;bottom:parent.bottom;margins:Margin}
        width:height
        mouse.onPressed:WindowManager.createWindow("/Clock/Window.qml",Clock);
    }
    TimeDateDisplay{
        id:display
        anchors{left:parent.left;right:button.left;top:parent.top;bottom:parent.bottom;margins:Margin}
    }
    Connections{
        target:Clock
        onNotifyHour:Voice.speak("new hour");
    }
}