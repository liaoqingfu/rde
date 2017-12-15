import org.rde.ui 1.0
import QtQuick 2.0
RListDelegate{
    icon.source:"image://Icon/"+IconName
    label.text:Name
    mouse.onPressed:deviceList.currentIndex=index


    Text{
        anchors{verticalCenter: parent.verticalCenter;right:parent.right}
        renderType: Text.NativeRendering
        color:'white'
        font.pointSize: 20
        text:SignalStrength
    }
}