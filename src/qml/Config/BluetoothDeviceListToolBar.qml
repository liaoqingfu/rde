import QtQuick 2.0
import org.rde.ui 1.0
ToolBar{
    Icon{
        anchors{right:parent.right;verticalCenter:parent.verticalCenter;rightMargin:Margin}
        source:'image://Icon/task-recurring'
        //source:Bluetooth.active?'image://Icon/preferences-system-bluetooth':'image://Icon/preferences-system-bluetooth-inactive'
        //mouse.onPressed:Bluetooth.toggleAdapter();
    }
}