import QtQuick 2.0
import org.rde.ui 1.0
ListView{
    clip:true
    focus:true
    model:gameModuleModel


    delegate:ModuleDelegate{}
    highlight:ListHighlight{}
    highlightFollowsCurrentItem:true
    highlightMoveDuration:100
    boundsBehavior:Flickable.StopAtBounds
    snapMode:ListView.SnapToItem
    onCurrentIndexChanged:gameModuleModel.currentIndex=currentIndex
    onCurrentItemChanged:loader.setPath(currentItem.label.text+"/config.qml")

    Connections{
        target:gameModuleModel
        onImportBusy:Voice.say("go")
        onImportReady:Voice.say("ready")
    }
}