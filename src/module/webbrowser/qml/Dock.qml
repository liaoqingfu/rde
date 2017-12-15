import QtQuick 2.0
import org.rde.core 1.0
import org.rde.ui 1.0
ModuleDockItem{
    Tile{anchors.fill: parent}
    Icon{
        source:'image://Icon/internet-web-browser'
        anchors{left:parent.left;leftMargin:Margin;verticalCenter:parent.verticalCenter}
        mouse.onClicked:MainWindow.setItem("/WebBrowser/Window.qml",WebBrowser);
    }
}