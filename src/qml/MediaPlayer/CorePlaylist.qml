import QtQuick 2.2
import QtQuick.Controls 1.4
import org.rde.ui 1.0
import org.rde.mediaplayer 1.0
TableView{
    model:PlaylistModel{id:playlistModel}
    alternatingRowColors:false
    backgroundVisible:false
    style:TableStyle{}
    headerDelegate:RTableHeader{}
    rowDelegate:RRowDelegate{}
    itemDelegate:CorePlaylistDelegate{}
    focus:true
    highlightOnFocus:true
    TableViewColumn{
        width: 64
        delegate:Image{
            sourceSize{width:32;height:32}
            width:32
            height:32
            source:"image://Icon/audio-x-flac"
            fillMode: Image.PreserveAspectFit
        }
    }
    TableViewColumn{
        role:'Title'
        title:'Title'
        width:playlist.width/2
    }
    TableViewColumn{
        role:'Artist'
        title:'Artist'
        width:playlist.width/2
    }
    //    TableViewColumn{
    //        role:'Album'
    //        title:'Album'
    //        width:playlist.width/4
    //    }
    //    TableViewColumn{
    //        role:'Genre'
    //        title:'Genre'
    //        width:playlist.width/4
    //    }
    //onActivated: MediaPlayer.setMedia(playlistModel.data(playlistModel.index(row,0),"File"))
    //onSe
    //onh
    onActivated:playlistModel.currentIndex=row
}