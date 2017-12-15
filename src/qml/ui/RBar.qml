import QtQuick 2.0
Rectangle{
    anchors{left:parent.left;right:parent.right}
    height:48
    gradient:Gradient{
        GradientStop {position:0;color:Qt.rgba(0.7,0.7,0.7,0.7)}
        GradientStop {position:0.5;color:Qt.rgba(0.4,0.4,0.4,0.4)}
        GradientStop {position:1;color:Qt.rgba(0.3,0.3,0.3,0.7)}
    }
}