import QtQuick 2.0
import Element 1.0
ListDelegate{
    label.text:File
    icon.source:"image://Icon/preferences-desktop-screensaver"
    mouse.onClicked:screensaverList.model.currentIndex=index;
}