import org.rde.core 1.0
import org.rde.ui 1.0
import QtQuick 2.0
ModuleDockItem{
    RBar{anchors.fill: parent}
    Rectangle{
        id:vis
        anchors{fill: parent;margins:10}
        radius: 8
        border.width: 1
        border.color: 'black'
        color:'black'

        MouseArea{
            anchors.fill: parent
            onClicked:MainWindow.setItem("/Voice/Window.qml",Voice);
        }
    }
    Connections{
        target: Voice
        onSpeaking:vis.color='red'
        onReady:vis.color='darkred'
        onPaused:vis.color='orange'
        onError:vis.color='black';
    }
}