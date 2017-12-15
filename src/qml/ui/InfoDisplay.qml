import QtQuick 2.0
Rectangle{
    id:background
    //radius:8
    border{width:1;color:'black'}
    clip:true
    gradient:Gradient{
        GradientStop{position:0;color:Qt.rgba(0.4,0.4,0.4,0.8)}
        //GradientStop{position:0.5;color:Qt.rgba(0.4,0.4,0.4,0.1)}
        GradientStop{position:1;color:Qt.rgba(0.2,0.2,0.2,0.8)}
    }
}