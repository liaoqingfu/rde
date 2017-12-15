import QtQuick 2.0
Rectangle{
    property alias mouse:mouse
    property alias label:label
    property alias icon:icon
    anchors{top:parent.top;bottom:parent.bottom}
    width:200
    border.width: 1
    border.color: 'black'
    gradient: Gradient{
        GradientStop {position:0;color:Qt.rgba(0.7,0.7,0.7,0.7)}
        GradientStop {position:0.5;color:Qt.rgba(0.4,0.4,0.4,0.4)}
        GradientStop {position:1;color:Qt.rgba(0.3,0.3,0.3,0.7)}
    }
    scale:mouse.pressed?0.97:1

    Image{
        id:icon
        width:32
        height:32
        sourceSize{width:32;height:32}
        fillMode: Image.PreserveAspectFit
        anchors{left:parent.left;verticalCenter:parent.verticalCenter;margins:8}
    }

    Text{
        id:label
        anchors{top:parent.top;bottom:parent.bottom;left:icon.right;margins:8}
        renderType: Text.NativeRendering
        color:'white'
        style: Text.Raised
        //horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font{family:DefaultFont;pointSize:20}
        elide: Text.ElideRight
    }

    TextGlow{
        anchors.fill:label
        source:label
    }
    MouseArea{
        id:mouse
        anchors.fill: parent
        hoverEnabled: true
    }
}