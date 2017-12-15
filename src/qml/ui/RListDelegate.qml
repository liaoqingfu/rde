import QtQuick 2.0
import org.rde.ui 1.0
RBar{
    property alias mouse:mouse
    property alias icon:icon
    property alias label:label.text
    MouseArea{
        id:mouse
        anchors.fill:parent
        hoverEnabled:true
    }
    Image{
        id:icon
        fillMode:Image.PreserveAspectFit
        anchors{left:parent.left;leftMargin:Margin;verticalCenter: parent.verticalCenter}
        width:32
        height:32
        sourceSize{width:width;height:height}
        asynchronous:true
        antialiasing:true
        opacity:mouse.containsMouse?1:0.7
        scale:mouse.containsMouse?1.2:1
        Behavior on scale{NumberAnimation{duration:200}}
        Behavior on opacity{NumberAnimation{duration:200}}
    }
    RText{
        id:label
        anchors{left:icon.right;right:parent.right;top:parent.top;bottom:parent.bottom;margins:Margin}
        text.verticalAlignment:Text.AlignVCenter
        text.color:mouse.containsMouse?'white':'lightgray'
    }
}