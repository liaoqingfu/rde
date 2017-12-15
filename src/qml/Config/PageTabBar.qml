import QtQuick 2.0
import org.rde.ui 1.0
RTabBar{
    model:ListModel{
        id:listModel
        ListElement{type:'Environment';IconName:'applications-multimedia';name:'Environment'}
        ListElement{type:'Screens';IconName:'preferences-desktop-display';name:'Screens'}
        //ListElement{type:'Display';IconName:'preferences-desktop-display-color';name:'Display'}
        ListElement{type:'Audio';IconName:'audio-card';name:'Audio'}
        //ListElement{type:'User Interface';IconName:'view-media-playlist';name:'UI'}
        ListElement{type:'Modules';IconName:'preferences-plugin';name:'Modules'}
        ListElement{type:'Gamepad';IconName:'input-gaming';name:'Gamepad'}
        ListElement{type:'Network';IconName:'network-manager';name:'Network'}
        ListElement{type:'Bluetooth';IconName:'preferences-system-bluetooth';name:'Bluetooth'}
        ListElement{type:'Voice';IconName:'preferences-desktop-text-to-speech';name:'Voice'}

    }
    delegate:PageTabDelegate{}
    onCurrentIndexChanged:pageSurface.setPath('/development/rde/src/qml/Config/Page'+listModel.get(currentIndex).name+'.qml')
    //section.property:'Group'
    //section.criteria:ViewSection.FullString
    //section.delegate:Rectangle{anchors{left:parent.left;right:parent.right}height:48}
}