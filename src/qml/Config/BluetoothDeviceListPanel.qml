import QtQuick 2.0
import org.rde.ui 1.0
import org.rde.bluetooth 1.0
Item{
    ToolBar{
        id:deviceListToolBar
        anchors{top:parent.top;left:parent.left;right:parent.right}
    }
    ListView{
        id:deviceList
        anchors{left:parent.left;right:parent.right;top:deviceListToolBar.bottom;bottom:parent.bottom}
        model:deviceModel
        delegate:BluetoothDeviceDelegate{}
        currentIndex:deviceModel.currentIndex;
        onCurrentIndexChanged:deviceModel.currentIndex=currentIndex;
        highlight: Rectangle{color:'blue';opacity:0.5}

        clip:true
        boundsBehavior: Flickable.StopAtBounds
        snapMode: ListView.SnapToItem

        //        function connectDevice(){
        //            deviceModel.startConnection()
        //        }
    }
}