import QtQuick 2.0
import QtQuick.Controls 1.4
Rectangle{
    color:'transparent'
    border.width: 3
    radius:8
    height:64
    property alias slider:slider
    //    Text{
    //        anchors{left:parent.left;top:parent.top;bottom:parent.bottom;margins:Margin}
    //        renderType: Text.NativeRendering
    //        color:'white'
    //        text:"EEE"
    //    }
    Slider{
        id:slider
        anchors{left:parent.left;right:parent.right;top:parent.top;bottom:parent.bottom;leftMargin:100;rightMargin:Margin}
        updateValueWhileDragging:true
    }
}