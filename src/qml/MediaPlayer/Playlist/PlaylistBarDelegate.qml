import org.rde.ui 1.0
RListDelegate{
    label.text:Name
    mouse{
        onPressed:playlistBar.currentIndex=index;
        onClicked:playlistsModel.file=File;
        onDoubleClicked: MediaPlayer.openPlaylist(File)
    }
    //onClicked:playlistContentView.playlistModel.currentPlaylist=File
    //onDoubleClicked: MediaPlayer.currentPlaylist=File
    icon.source:"image://Icon/audio-x-mp3-playlist";
}