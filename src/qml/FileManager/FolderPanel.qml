import QtQuick 2.0
import org.rde.ui 1.0
Item{
    RToolBar{
        id:toolBar
    }
    FolderTableView{
        id:view
        anchors{top:toolBar.bottom;bottom:parent.bottom;left:parent.left;right:parent.right}
    }
    RIcon{
        parent:toolBar.row
        source:'image://Icon/back'
    }
    RIcon{
        parent:toolBar.row
        //source:'/Image::/Icon/
        source:'image://Icon/forward'
    }
    property alias view:view
}