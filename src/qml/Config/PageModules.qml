import QtQuick 2.0
import org.rde.core 1.0
import org.rde.ui 1.0
AbstractPage{
    //    ModuleModel{
    //        id:moduleModel
    //    }
    //    ListView{
    //        id:moduleView
    //        model:moduleModel
    //        anchors{top:parent.top;bottom:parent.bottom;left:parent.left}
    //        width:256
    //        //currentIndex:0
    //        boundsBehavior: ListView.StopAtBounds
    //        snapMode: ListView.SnapToItem
    //        //highlight: Rectangle{color:'darkblue'}
    //        delegate:ModuleDelegate{}
    //        //onCurrentIndexChanged:Voice.say(moduleModel.data(moduleModel.index(currentIndex,0),0));
    //        onCurrentIndexChanged: moduleModel.currentIndex=currentIndex
    //        section.property: 'Device'
    //        section.criteria: ViewSection.FullString
    //        section.delegate:Header{label.text:section}
    //    }
    //    Item{
    //        anchors{top:parent.top;bottom:parent.bottom;left:moduleView.right;right:parent.right;margins: Margin}

    //        Column{
    //            anchors.fill: parent
    //            InfoBar{
    //                key.text:'Description'
    //                value.text:moduleModel.description
    //            }
    //            InfoBar{
    //                key.text:'Version'
    //                value.text:moduleModel.version
    //            }
    //        }
    //    }
}