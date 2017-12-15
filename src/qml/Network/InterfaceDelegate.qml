import QtQuick 2.0
import org.rde.ui 1.0
ListDelegate{
    icon.source:IsRunning?'image://Icon/user-online':'image://Icon/user-offline'
    label.text:Name+"/"+MacAddress
    //anchors.verticalCenter: parent.verticalCenter
}