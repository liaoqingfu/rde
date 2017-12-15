import QtQuick 2.0

Item {
    anchors{top:parent.top;bottom:parent.bottom}
    width:200



    Text{anchors{left:parent.left;verticalCenter: parent.verticalCenter}
        anchors.centerIn: parent
        renderType: Text.NativeRendering
        color:'white'
        text:URL
        font.pointSize: 10
        style: Text.Raised
        styleColor:'black'
        textFormat: Text.PlainText
    }

}
