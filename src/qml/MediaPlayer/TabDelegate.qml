import org.rde.ui 1.0
RTabButton{
    label.text:type
    mouse.onClicked:tabBar.currentIndex=index
    icon.source:'image://Icon/'+iconName
    //onActiveFocus:Voice.say(type)
}