import QtQuick 2.0
import org.rde.ui 1.0
Item{
    width:grid.cellWidth
    height:grid.cellHeight
    RIcon{
        id:icon
        anchors.centerIn: parent
        sourceSize{width:64;height:64}
        width:64
        height:64
        //sourceSize{width:parent.width;height:parent.height}
        source:"image://Icon/"+IconName;
        mouse.onClicked:desktopFilesModel.click(index)
        //Component.onCompleted: console.log("Icon "+IconName)
    }
}