import org.rde.core 1.0
import org.rde.ui 1.0
import QtQuick 2.0
ModuleDockItem{
    RBar{anchors.fill: parent}
    TimeDateDisplay{
        id:display
        anchors{fill:parent;margins:Margin}
    }
    Connections{
        target:Clock
        onAnnounceTime:Voice.say(speech);
    }
}