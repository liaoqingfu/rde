import QtQuick 2.2
//-------------------------------------------------------------------------------------------------
Image {
    sourceSize{width:32;height:32}
    width: 32
    height: 32
    scale:mouseArea.pressed?0.9:1
    fillMode:Image.PreserveAspectFit
    smooth:true
    antialiasing: true
    //---------------------------------------------------------------------------------------------
    MouseArea{
        id:mouseArea
        anchors.fill: parent
    }
    //---------------------------------------------------------------------------------------------
    property alias mouseArea:mouseArea
}
//-------------------------------------------------------------------------------------------------