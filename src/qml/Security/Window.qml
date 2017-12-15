import QtQuick 2.0
import org.rde.ui 1.0
//import QtQuick.Layouts 1.3
Rectangle{
    anchors.fill: parent
    //color:'green'
    color:'transparent'

    RButton{
        anchors.fill: parent
        enabled:securityWindow.clamReady
        mouse.onClicked:securityWindow
    }
}