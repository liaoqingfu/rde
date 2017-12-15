import QtQuick 2.0
import org.rde.launcher 1.0
GridView{
    clip:true;
    cellWidth:width/3;
    cellHeight:cellWidth
    boundsBehavior:Flickable.StopAtBounds
    model:DesktopFilesModel{id:desktopFilesModel}
    delegate:Delegate{}
}