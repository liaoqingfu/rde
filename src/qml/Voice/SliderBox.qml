import QtQuick 2.0
import QtQuick.Controls 1.4
Item{
    anchors{left:parent.left;right:parent.right}
    height:32
    property alias label:label
    property alias slider:slider
    Rectangle{
        z:0
        anchors.fill: parent
        color:'black'
        radius:6
        opacity:0.5
    }
    Slider{
        id:slider
        anchors{left:label.right;top:parent.top;bottom:parent.bottom;right:parent.right;margins:Margin}
        updateValueWhileDragging: false
    }
    Text{
        id:label
        renderType: Text.NativeRendering
        color:'white'
        style:Text.Raised
        //anchors{verticalCenter:parent.verticalCenter;left:parent.left;margins:Margin}
        anchors{left:parent.left;top:parent.top;bottom:parent.bottom}
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 16
        width:100
    }
}