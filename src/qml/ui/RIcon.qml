import QtQuick 2.2
Image{
    property int defaultSize:64
    property alias mouse:mouse
    Behavior on opacity{NumberAnimation{duration:100}}
    Behavior on scale{NumberAnimation{duration:50}}
    scale:mouse.pressed?0.9:1
    opacity:mouse.containsMouse?1:0.7
    fillMode:Image.PreserveAspectFit
    smooth:true
    antialiasing:true
    asynchronous:true
    clip:false
    sourceSize{width:defaultSize;height:defaultSize}
    width:defaultSize
    height:defaultSize
    MouseArea{
        id:mouse
        anchors.fill: parent
        hoverEnabled: true
    }
}