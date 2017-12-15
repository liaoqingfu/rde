import QtQuick 2.0
Tile{
    id:item
    Behavior on scale{NumberAnimation{duration:50}}
    property alias mouse:mouse
    property alias icon:icon
    focus:false
    scale:mouse.pressed?0.9:1
    Image{
        id:icon
        anchors.centerIn:parent
        sourceSize{width:64;height:64}
        width:64
        height:64
        fillMode: Image.PreserveAspectFit
        opacity:mouse.containsMouse?1:0.5
        Behavior on opacity{NumberAnimation{duration:100}}
    }
    MouseArea{
        id:mouse
        anchors.fill:parent
        hoverEnabled:true
    }
}