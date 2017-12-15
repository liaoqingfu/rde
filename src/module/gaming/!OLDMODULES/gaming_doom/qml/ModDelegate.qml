import org.neon.ui 1.0
ListDelegate{
    label.text:name
    //mouse.onPressed:Doom.setMod(path)
    mouse.onClicked:modView.currentIndex=index
}