import QtQuick 2.0
import org.rde.ui 1.0
Rectangle{
    border.width: 1
    anchors{top:parent.top;bottom:parent.bottom}
    color:'transparent'
    property alias label:label
    property alias list:listView


    Rectangle{
        id:header

        anchors{left:parent.left;right:parent.right;top:parent.top}
        height:32
        color:'black'
        Text{
            id:label
            renderType: Text.NativeRendering
            color:'white'
            style:Text.Raised
            anchors.fill: parent

            //anchors{top:parent.top;left:parent.left;right:parent.right;margins:Margin}

            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            //height:32
            font.bold: true
            font.pointSize: 12
        }

    }

    //    Rectangle{
    //        z:0
    //        anchors.fill: parent
    //        color:'black'
    //        opacity:0.5
    //        radius:8
    //    }

    //    ColumnModel{
    //        id:model
    //    }

    //Background{
    //anchors{left:parent.left;right:parent.right;top:header.bottom;bottom:parent.bottom}
    ListView{
        id:listView
        //anchors.fill: parent
        anchors{left:parent.left;right:parent.right;top:header.bottom;bottom:parent.bottom}
        //z:1


        //anchors{fill:parent;margins:5}
        delegate:LibraryColumnDelegate{}
        clip:true

        boundsBehavior: ListView.StopAtBounds

    }
    //}
}