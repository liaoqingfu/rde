import QtQuick 2.0
//import org.rde.core 1.0
import org.rde.ui 1.0
RBar{
    Row{
        id:row
        anchors{fill:parent}
        Item{
            anchors{top:parent.top;bottom:parent.bottom}
            width:parent.width/3
            RIcon{
                id:shutdownIcon
                anchors.centerIn:parent
                source:'image://Icon/system-shutdown'
                mouse.onClicked:MainWindow.setItem('/rde/ShutdownWindow.qml')
            }
        }
        Item{
            anchors{top:parent.top;bottom:parent.bottom}
            width:parent.width/3
            RIcon{
                id:configureIcon
                anchors.centerIn:parent
                source:'image://Icon/configure'
                mouse.onClicked:MainWindow.setItem('/rde/ConfigureWindow.qml')
            }
        }
        Item{
            anchors{top:parent.top;bottom:parent.bottom}
            width:parent.width/3
            RIcon{
                anchors.centerIn:parent
                source:'image://Icon/error'
                mouse.onClicked:MainWindow.setItem('/rde/ErrorWindow.qml')
            }
        }
    }
    IconShadow{
        anchors.fill: parent
        source:row
    }
}