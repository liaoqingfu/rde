import QtQuick 2.0
import QtQuick.Controls 1.4
Item{
    anchors{left:parent.left;right:parent.right}
    height:24
    property alias label:label
    property alias bar:bar
    Text{
        id:label
        anchors{left:parent.left;top:parent.top;bottom:parent.bottom}
        width:32
        horizontalAlignment:Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
        color:'white'
        style: Text.Raised
    }
    ProgressBar{
        id:bar
        anchors{left:label.right;right:parent.right;top:parent.top;bottom:parent.bottom}
    }
}