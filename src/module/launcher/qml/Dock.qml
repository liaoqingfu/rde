import org.rde.core 1.0
import org.rde.ui 1.0
ModuleDockItem{
    height:320
    RBar{anchors.fill: parent}
    Background{
        anchors{fill:parent;margins:Margin}
        Grid{
            id:grid
            anchors.fill:parent

            //            IconShadow{
            //                anchors.fill:parent
            //                source:parent
            //            }
        }
    }
}