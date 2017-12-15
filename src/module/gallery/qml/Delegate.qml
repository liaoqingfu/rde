import QtQuick 2.0
Image {
    id:image
    sourceSize{width:194;height:194}
    width:194
    height:194
    asynchronous: true
    smooth:true
    source:"image://Gallery/"+FilePath
    fillMode:Image.PreserveAspectFit
    Text{
        anchors{horizontalCenter: parent.horizontalCenter;bottom:parent.bottom;bottomMargin:10}
        renderType: Text.NativeRendering
        color:'white'
        style:Text.Raised
        font.pointSize: 16
        text:FileName
    }
    MouseArea{
        anchors.fill: parent
        onClicked:viewer.source=image.source
        onPressAndHold: Display.file=FilePath
    }
}