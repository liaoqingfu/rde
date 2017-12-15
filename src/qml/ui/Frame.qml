import QtQuick 2.0

Rectangle{
    radius:16
    border{color:'cyan';width:2}
    gradient: Gradient{
        GradientStop {position:0;color:Qt.rgba(0.7,0.7,0.7,0.5)}
        GradientStop {position:0.5;color:Qt.rgba(0.4,0.4,0.4,0.2)}
        GradientStop {position:1;color:Qt.rgba(0.3,0.3,0.3,0.5)}
    }
}