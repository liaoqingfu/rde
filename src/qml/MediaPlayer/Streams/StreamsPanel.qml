import QtQuick 2.0
import org.rde.mediaplayer 1.0
Item{
    anchors.fill: parent
    ListView{
        id:streamsView
        anchors.fill: parent
        clip:true
        boundsBehavior:Flickable.StopAtBounds
        snapMode:ListView.SnapToItem
        model:StreamsModel{id:streamsModel}
        delegate:StreamDelegate{}
    }
}