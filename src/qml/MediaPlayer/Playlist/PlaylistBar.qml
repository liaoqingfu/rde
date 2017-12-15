import QtQuick 2.2
import org.rde.mediaplayer 1.0
//import org.neon.ui 1.0
ListView{
    boundsBehavior: Flickable.StopAtBounds
    snapMode: ListView.SnapToItem
    model:PlaylistsModel{id:playlistsModel}
    delegate:PlaylistBarDelegate{}
    //onCurrentIndexChanged:playlistModel.index=currentIndex
}