import QtQuick 2.0
import org.rde.ui 1.0
RListDelegate{
    icon.source:IsActive?"image://Icon/user-online":"image://Icon/user-offline"
    label.text:Name
    mouse.onPressed:configurationView.currentIndex=index
    mouse.onPressAndHold:configModel.hold(index)
}