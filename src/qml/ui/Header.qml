import QtQuick 2.0
Rectangle{
    property alias label:label
    anchors{left:parent.left;right:parent.right}
    height:48
    gradient: Gradient{
        //GradientStop {position:0;color:Qt.rgba(0.7,0.7,0.7,0.5)}
        //GradientStop {position:0.5;color:Qt.rgba(0.4,0.4,0.4,0.2)}
        //GradientStop {position:1;color:Qt.rgba(0.3,0.3,0.3,0.5)}
        GradientStop {position:0;color:Qt.rgba(0.7,0.7,0.7,1)}
        GradientStop {position:1;color:Qt.rgba(0.3,0.3,0.3,1)}
    }



    Text{
        id:label
        anchors{fill:parent;margins:Margin}
        renderType: Text.NativeRendering
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:'white'
        font.pointSize: 12
    }
}