import org.rde.ui 1.0
RListDelegate{
    icon.source:'image://Icon/audio-card'
    label.text:DeviceName
    mouse.onClicked:parent.currentIndex=index
}