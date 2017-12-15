import QtQuick 2.0
import org.rde.ui 1.0
import org.rde.audio 1.0
AbstractPage{
    Item{
        id:inputDevicePanel
        anchors{top:parent.top;bottom:parent.verticalCenter;left:parent.left;right:parent.right}
        ToolBar{
            id:inputBar
        }
        ListView{
            id:inputView
            anchors{left:parent.left;right:parent.right;top:inputBar.bottom;bottom:parent.bottom}
            height:200
            model:InputDeviceModel{}
            delegate:AudioDeviceDelegate{}
            boundsBehavior: Flickable.StopAtBounds
            snapMode: ListView.SnapToItem
            clip:true
            //highlight: Highlight{}
            onCurrentIndexChanged:Voice.say(currentIndex)
        }
    }
    Item{
        id:outputDevicePanel
        anchors{top:parent.verticalCenter;bottom:parent.bottom;left:parent.left;right:parent.right}
        ToolBar{
            id:outputBar
        }
        ListView{
            id:outputView
            anchors{top:outputBar.bottom;left:parent.left;right:parent.right;bottom:parent.bottom}
            model:OutputDeviceModel{}
            delegate:AudioDeviceDelegate{}
            boundsBehavior: Flickable.StopAtBounds
            snapMode: ListView.SnapToItem
            clip:true
        }
    }
}