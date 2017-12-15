import QtQuick 2.0
import org.rde.gamepad 1.0
import org.rde.ui 1.0
AbstractPage{
    ListView{
        id:gamepadView
        anchors{top:parent.top;bottom:parent.bottom;left:parent.left}
        width:256
        onCurrentIndexChanged: gamepadModel.currentIndex=currentIndex
        boundsBehavior: Flickable.StopAtBounds
        snapMode: ListView.SnapToItem
        model:GamepadModel{id:gamepadModel}
        delegate:GamepadDelegate{}
    }
    TempGamepad{
        id:preview
        anchors{top:parent.top;bottom:parent.bottom;left:gamepadView.right;right:parent.right}
    }
}