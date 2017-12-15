import QtQuick 2.0
import org.rde.ui 1.0
Item{
    clip:true
    Rectangle{
        anchors.fill: parent
        z:0
        color:'black'
        border.color: 'black'
        opacity: 0.5
    }
    RText{
        id:label
        z:1
        anchors{fill: parent;margins:Margin}
        text.text:gameList.model.filter
        text.horizontalAlignment:Text.AlignLeft
        text.verticalAlignment:Text.AlignVCenter
    }
}