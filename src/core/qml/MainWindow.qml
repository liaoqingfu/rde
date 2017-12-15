import QtQuick 2.0
import QtGraphicalEffects 1.0
Rectangle{
    z:0
    anchors.fill:parent
    border{width:1;color:'black'}
    color:'transparent'
    RadialGradient{
        anchors.fill: parent
        gradient:Gradient{
            GradientStop{position:0.0;color:Qt.rgba(0,0,0.1,0.4)}
            GradientStop{position:0.9;color:Qt.rgba(0,0,0.1,0.7)}
        }
    }
}