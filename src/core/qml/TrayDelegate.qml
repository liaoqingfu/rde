import QtQuick 2.0
import org.rde.ui 1.0
Item{
    anchors{top:parent.top;bottom:parent.bottom}
    width:trayView.width/3
    RIcon{
        anchors.centerIn: parent
        source:'image://Icon/'+IconName
        mouse.onClicked:MainWindow.setItem('/'+IID+'/Window.qml',Context);
    }
}