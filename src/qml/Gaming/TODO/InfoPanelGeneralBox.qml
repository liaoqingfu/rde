import QtQuick 2.0
import org.rde.ui 1.0
Tile{
    Column{
        anchors{fill:parent;margins:Margin}
        spacing:Margin
        GameInfoNameDisplay{
            anchors{left:parent.left;right:parent.right}
            height:100
        }
        InfoBar{
            anchors{left:parent.left;right:parent.right;}
            key.text:'Developer'
            value.text:infoPanel.developer
        }
        InfoBar{
            anchors{left:parent.left;right:parent.right;}
            key.text:'Year'
            value.text:infoPanel.year
        }
        InfoBar{
            anchors{left:parent.left;right:parent.right;}
            key.text:'Category'
            value.text:infoPanel.category
        }
    }
}