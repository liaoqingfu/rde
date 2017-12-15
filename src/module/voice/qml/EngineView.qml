import QtQuick 2.0
import org.rde.voice 1.0
ListView{
    snapMode: ListView.SnapToItem
    boundsBehavior: Flickable.StopAtBounds
    clip:true
    model:EngineModel{id:engineModel}
    delegate:EngineDelegate{}
}