import QtQuick 2.0
import org.rde.ui 1.0
Item{
    anchors.fill: parent
    //Tile{}
    Icon{
        source:'image://Icon/system-file-manager'
        anchors{verticalCenter:parent.verticalCenter}
        //mouse.onPressed:WindowManager.createWindow("/FileManager/Window.qml",FileManager);
        //mouse.onClicked:console.log(FileManager)
    }
}