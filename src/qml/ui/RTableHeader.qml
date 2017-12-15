import QtQuick 2.0
Rectangle{
    height:48
    gradient: Gradient{
        GradientStop {position:0;color:Qt.rgba(0.7,0.7,0.7,1)}
        GradientStop {position:1;color:Qt.rgba(0.3,0.3,0.3,1)}
    }
    RText{
        anchors.fill: parent
        text.verticalAlignment: Text.AlignVCenter
        text.horizontalAlignment: Text.AlignHCenter
        text.text:styleData.value
    }
}