import QtQuick 2.0
import org.rde.core 1.0
import org.rde.ui 1.0
RBar{
    ListView{
        id:trayView
        anchors.fill: parent
        model:TrayModel{}
        delegate: TrayDelegate{}
        boundsBehavior: ListView.StopAtBounds
        orientation:ListView.Horizontal
    }
    IconShadow{
        anchors.fill: parent
        source:trayView
    }
}