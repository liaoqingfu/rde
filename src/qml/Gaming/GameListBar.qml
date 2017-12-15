import QtQuick 2.0
import org.rde.ui 1.0
RBar{
    height:48
    FilterBox{
        id:filterBox
        anchors{left:parent.left;right:parent.horizontalCenter;top:parent.top;bottom:parent.bottom;margins:Margin}
    }
    CountBox{
        id:countBox
        anchors{left:parent.horizontalCenter;right:parent.right;top:parent.top;bottom:parent.bottom;margins:Margin}
    }
}