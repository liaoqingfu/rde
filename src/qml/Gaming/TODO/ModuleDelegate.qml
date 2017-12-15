import org.rde.ui 1.0
ListDelegate{
    icon.source:'image://Icon/'+IconName
    label.text:Description
    mouse.onPressed:moduleList.currentIndex=index;

    height:72

    icon{
        width:64
        height:64
        sourceSize{width:64;height:64}
    }

    Icon{
        anchors{top:parent.top;bottom:parent.bottom;right:parent.right}
        height:64
        width:64
        sourceSize{width:64;height:64}
        source:'image://Icon/input-gaming'
        //mouse.onClicked:Voice.say("click")
        mouse.onClicked:gameModuleModel.importModuleData(index)
    }
}