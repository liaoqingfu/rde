import QtQuick 2.0
import Gallery 1.0
GridView{    
    cellWidth: 200
    cellHeight: 200
    snapMode: GridView.SnapToRow
    boundsBehavior: Flickable.StopAtBounds
    clip:true
    model:ImageModel{id:imageModel}
    delegate:Delegate{}
//    displaced:Transition {
//        NumberAnimation {properties:"opacity";from:0;to:1;duration:300;easing.type: Easing.InOutQuad }
//    }
//    populate: Transition {
//        NumberAnimation { properties: "x,y"; duration: 1000 }
//    }
}