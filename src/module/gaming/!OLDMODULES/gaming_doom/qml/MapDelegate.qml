import org.neon.ui 1.0
ListDelegate{
    label.text:name
    //mouse.onPressed:{Doom.setMap(path)}
    mouse.onClicked:{mapView.currentIndex=index;}
}