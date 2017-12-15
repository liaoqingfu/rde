import org.neon.ui 1.0
import org.neon.gaming 1.0
import QtQuick.Layouts 1.3
LaunchWindowItem{
    id:launchWindow
    anchors.fill: parent
    focus:true
    RowLayout{
        //anchors.fill: parent
        anchors{left:parent.left;right:parent.right;top:parent.top;bottom:button.top}
        MapView{
            id:mapView
            anchors{top:parent.top;bottom:parent.bottom}
            Layout.minimumWidth:300
            Layout.fillWidth: true
        }
        ModView{
            id:modView
            anchors{top:parent.top;bottom:parent.bottom}
            Layout.minimumWidth:300

        }
    }
    Button{
        id:button
        anchors{left:parent.left;right:parent.right;bottom:parent.bottom;margins:Margin}
        height:64
        //mouse.onPressed:launchWindow.d
    }
}