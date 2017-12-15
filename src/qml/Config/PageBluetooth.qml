import org.rde.ui 1.0
import org.rde.bluetooth 1.0
AbstractPage{
    ToolBar{
        id:toolBar
        Icon{
            id:refreshIcon
            parent:toolBar.row
            //anchors{left:parent.left;verticalCenter:parent.verticalCenter;margins:Margin}
            anchors{verticalCenter:parent.verticalCenter;margins:Margin}
            source:'image://Icon/view-refresh'
            //sorce:Bluetooth.active?'image://Icon/preferences-system-bluetooth':'image://Icon/preferences-system-bluetooth-inactive'
            mouse.onPressed:Bluetooth.scan();
            enabled:Bluetooth.active
        }
        Icon{
            id:activeIcon
            parent:toolBar.row
            //anchors{left:parent.left;verticalCenter:parent.verticalCenter;margins:Margin}
            anchors{verticalCenter:parent.verticalCenter;margins:Margin}
            source:Bluetooth.active?'image://Icon/preferences-system-bluetooth':'image://Icon/preferences-system-bluetooth-inactive'
            mouse.onPressed:Bluetooth.active?Bluetooth.active=false:Bluetooth.active=true

        }
    }
    BluetoothDeviceModel{id:deviceModel}
    BluetoothDeviceListPanel{
        id:deviceListPanel
        anchors{left:parent.left;top:toolBar.bottom;bottom:parent.bottom}
        width:384
        visible: Bluetooth.active
    }
    BluetoothDeviceInfoPanel{
        id:deviceInfo
        anchors{top:toolBar.bottom;bottom:parent.bottom;right:parent.right;left:deviceListPanel.right}
        visible: Bluetooth.active
    }
}