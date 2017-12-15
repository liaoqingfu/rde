import QtQuick 2.0
import org.rde.core 1.0
import org.rde.ui 1.0
Item{
    anchors.fill: parent
    PageTabBar{
        id:pageTabBar
    }
    Surface{
        id:pageSurface
        anchors{left:parent.left;right:parent.right;top:pageTabBar.bottom;bottom:parent.bottom}
    }
}