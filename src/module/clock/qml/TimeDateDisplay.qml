import QtQuick 2.0
import org.rde.ui 1.0
InfoDisplay{
    Text{
        id:timeLabel
        anchors{left:parent.left;top:parent.top;right:parent.right;bottom:parent.verticalCenter;margins:1}
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
        color:'white'
        font.pointSize:24
        text:Clock.hours+":"+Clock.minutes
        textFormat: Text.PlainText
    }
    TextGlow{
        anchors.fill:timeLabel
        source:timeLabel
        cached:false
    }
    Text{
        id:dateLabel
        anchors{left:parent.left;right:parent.right;bottom:parent.bottom;top:parent.verticalCenter;margins:1}
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        renderType: Text.NativeRendering
        color:'white'
        font.pointSize: 14
        text:Clock.date
        textFormat: Text.PlainText
    }
    TextGlow{
        anchors.fill:dateLabel
        source:dateLabel
        cached:false
    }
    MouseArea{
        anchors.fill: parent
        onClicked:MainWindow.setItem("/Clock/Window.qml",Clock);
    }
}