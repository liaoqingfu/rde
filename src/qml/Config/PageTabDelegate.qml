import org.rde.ui 1.0
RTabButton{
    label.text:type
    mouse.onClicked:pageTabBar.currentIndex=index
    icon.source:'image://Icon/'+IconName
}