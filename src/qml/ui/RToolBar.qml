import QtQuick 2.0
Rectangle{
    anchors{left:parent.left;right:parent.right}
    height:72
    border{width:1;color:'black'}
    gradient:Gradient{
        GradientStop{position:0;color:Qt.rgba(0.9,0.9,0.9,0.6)}
        GradientStop{position:0.5;color:Qt.rgba(0.5,0.5,0.5,0.3)}
        GradientStop{position:1;color:Qt.rgba(0.1,0.1,0.1,0.6)}
    }
    Row{
        id:row
        anchors{fill:parent;margins:Margin}
        spacing:Margin
    }
    property alias row:row
}