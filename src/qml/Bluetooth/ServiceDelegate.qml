import QtQuick 2.0
import org.rde.ui 1.0
ListDelegate {
    //anchors{left:parent.left;right:parent.right}
    height:36
    Rectangle{
        z:0
        anchors.fill: parent
        opacity:0.5
    }
    Text{
        id:nameLabel
        text:"Name:"+Name
        color:'white'
        renderType: Text.NativeRendering
        //anchors{top:parent.top;left:icon.right}
        anchors{top:parent.top;left:parent.left}
        font.pointSize: 12
        z:1
        style:Text.Raised
    }
    Text{
        id:descriptionLabel
        //text:"Desc:"+Description
        text:"UUID:"+UUID
        color:'white'
        renderType: Text.NativeRendering
        anchors{bottom:parent.bottom;left:parent.left}
        font.pointSize: 12
        z:1
        style:Text.Raised
    }
}
