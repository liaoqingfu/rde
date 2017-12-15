import org.rde.ui 1.0
ListDelegate{
    icon.source:'image://Icon/audio-x-generic'
    label.text:Name
    mouse.onClicked:MusicModel.currentIndex=index
}