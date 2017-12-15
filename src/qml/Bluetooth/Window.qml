import QtQuick 2.0
import org.rde.bluetooth 1.0
import org.rde.element 1.0
Item{
    anchors.fill: parent
    BluetoothDeviceModel{id:deviceModel}
    DeviceListPanel{
        z:1
        id:deviceListPanel
        anchors{left:parent.left;top:parent.top;bottom:parent.bottom}
        width:256
    }
    DeviceInfoPanel{
        id:deviceInfo
        z:1
        anchors{top:parent.top;bottom:parent.bottom;right:parent.right;left:deviceListPanel.right}
    }
}