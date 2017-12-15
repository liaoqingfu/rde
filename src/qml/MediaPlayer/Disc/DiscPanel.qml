import QtQuick 2.0
import org.rde.mediaplayer 1.0
import org.rde.ui 1.0
import QtQuick.Controls 1.4
Item{
    anchors.fill: parent
    TableView{
        id:trackView
        anchors{left:parent.left;right:parent.right;top:parent.top;margins:Margin}
        height:480
        model:CDTrackModel{id:cdTrackModel}
        itemDelegate:CDTrackDelegate{}
        backgroundVisible: false
        rowDelegate:RTableRowDelegate{}
        alternatingRowColors: false
        style:TableStyle{}
        headerDelegate:TableHeader{}
        TableViewColumn{
            role:'Length'
            title:'Length'
            width: trackView.width/4
        }
    }
    RIcon{
        source:"image://Icon/media-optical-cd-mixed"
        anchors{left:parent.left;right:parent.right;top:trackView.bottom;bottom:parent.bottom;margins:Margin}
        mouse.onClicked:cdTrackModel.ripCD()
    }
}