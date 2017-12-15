import org.rde.ui 1.0
RListDelegate{
    icon.source:"image://Icon/audio-x-generic"
    label.text:Name
    mouse{
        onPressed:streamsView.currentIndex=index;
        onDoubleClicked:MediaPlayer.openStream(File)
    }
}