import QtQuick 2.0
import org.rde.ui 1.0
RListDelegate{
    icon.source:'image://Icon/input-gaming'
    label.text:DeviceID
    mouse.onClicked:gamepadView.currentIndex=index

    Rectangle{
        opacity:0.2
        anchors.fill: parent
        z:0
        color:IsConnected?'green':'red'
    }
}