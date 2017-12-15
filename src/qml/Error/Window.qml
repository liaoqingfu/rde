import QtQuick 2.0
import org.rde.ui 1.0
import org.rde.message 1.0
Item{
    anchors.fill: parent
    RBar{
        id:header
        anchors{left:parent.left;right:parent.right;top:parent.top}
        height:64
        //Tile{}

        Text{
            anchors{verticalCenter:parent.verticalCenter;left:parent.left;margins:Margin}
            renderType: Text.NativeRendering
            color:'white'
            text:"Errors:"+errorList.count
            font.pointSize: 20
        }
    }
//    Rectangle{
//        id:errorBack
//        anchors{left:parent.left;top:header.bottom;bottom:errorDetails.top;margins:Margin}
//        width:500
//        color:'black'
//        opacity:0.5
//    }


    MessageModel{
        id:messageModel
    }
    ListView{
        id:errorList
        anchors{left:parent.left;top:header.bottom;bottom:parent.bottom;margins:Margin}
        width:800
        clip:true
        focus:true
        boundsBehavior:ListView.StopAtBounds
        snapMode:ListView.SnapToItem
        spacing:Margin
        delegate:MessageDelegate{}
        model:messageModel
        highlight:Rectangle{color:'darkblue'}
        highlightFollowsCurrentItem: true
        //onCountChanged:{currentIndex=count;positionViewAtEnd();}
        onCurrentIndexChanged:messageModel.currentIndex=currentIndex
        currentIndex:messageModel.currentIndex
        Component.onCompleted: forceActiveFocus();
    }

    ErrorPreview{
        id:errorPreview
        //anchors{top:header.bottom;bottom:errorDetails.top;right:parent.right;left:errorBack.right;margins:Margin}
        //anchors{top:header.bottom;bottom:parent.bottom;right:parent.right;left:errorBack.right;margins:Margin}
        anchors{top:header.bottom;bottom:parent.bottom;right:parent.right;left:errorList.right;margins:Margin}
    }
//    Item{
//        id:errorDetails
//        anchors{left:parent.left;right:parent.right;bottom:parent.bottom;margins:Margin}
//        height:64
//        Tile{}
//    }
}
