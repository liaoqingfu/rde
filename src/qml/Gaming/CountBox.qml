import QtQuick 2.0
import org.rde.ui 1.0
Rectangle{
    color:'black'
    RText{
        id:resultsLabel
        anchors{left:parent.left;right:parent.horizontalCenter;top:parent.top;bottom:parent.bottom}
        text.text:gameList.count
        text.horizontalAlignment:Text.AlignRight
        text.verticalAlignment:Text.AlignVCenter
    }
    RText{
        id:totalLabel
        anchors{left:parent.horizontalCenter;right:parent.right;top:parent.top;bottom:parent.bottom}
        text.text:"/"+gameList.model.total
        text.horizontalAlignment:Text.AlignLeft
        text.verticalAlignment:Text.AlignVCenter
    }
}