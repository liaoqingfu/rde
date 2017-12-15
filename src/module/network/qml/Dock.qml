import org.neon.core 1.0
import org.neon.ui 1.0
ModuleDockItem{
    Tile{anchors.fill: parent}
    Icon{
        anchors{left:parent.left;verticalCenter:parent.verticalCenter;leftMargin:Margin}
        source:'image://Icon/network-manager';
        mouse.onPressed:MainWindow.setItem("/Network/Window.qml",Network);
    }


    Icon{
        anchors{right:parent.right;verticalCenter:parent.verticalCenter;rightMargin:Margin}
        source:Network.isOnline?'image://Icon/user-online':'image://Icon/user-offline';
    }
}