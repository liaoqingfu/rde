import QtQuick 2.0

Item {
    anchors{left:parent.left;right:parent.right}
    height:40

    Row{
        anchors.fill: parent
        spacing:5

        Image{
            asynchronous: true
            fillMode:Image.PreserveAspectFit
            sourceSize{width:32;height:32}
            width:32
            height:32
            anchors.verticalCenter: parent.verticalCenter
        }

        Text{
            anchors.verticalCenter: parent.verticalCenter
            renderType: Text.NativeRendering
            font.pointSize: 10
            color:'white'
            style: Text.Raised
            styleColor: 'black'
            text:Name
        }
    }
}