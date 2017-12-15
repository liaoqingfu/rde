import org.rde.ui 1.0
RListDelegate{
    height:errorList.height/20
    icon.source:'image://Icon/'+IconName
    label.text: Content
    mouse.onPressed:errorList.currentIndex=index;
}