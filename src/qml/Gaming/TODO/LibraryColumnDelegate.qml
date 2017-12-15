import QtQuick 2.0
Rectangle{
    anchors{left:parent.left;right:parent.right}
    height:32
    color:'orange'


    Text{
        id:label
        renderType: Text.NativeRendering
        color:'white'
        style:Text.Raised
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pointSize: 12
        text:"Hehehe"
    }
}