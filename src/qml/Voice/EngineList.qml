import QtQuick 2.0
import org.rde.voice 1.0
ListView{
    model:EngineModel{id:engineModel}
    delegate:EngineDelegate{}
    highlight: Rectangle{color:'darkblue'}
    boundsBehavior: Flickable.StopAtBounds
    snapMode: ListView.SnapToItem
    currentIndex:engineModel.currentIndex
    onCurrentIndexChanged: engineModel.currentIndex=currentIndex
}