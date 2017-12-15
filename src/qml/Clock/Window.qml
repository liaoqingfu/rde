import QtQuick 2.0
import QtQuick.Controls 1.4
import org.rde.clock 1.0
Item{
    anchors.fill:parent
    ListView{
        id:eventView
        model:EventModel{id:eventModel}
        delegate:EventDelegate{}
        anchors{left:parent.left;top:parent.top;bottom:parent.bottom;margins:Margin}
        width:400
        boundsBehavior: Flickable.StopAtBounds
        //            populate: Transition {
        //                NumberAnimation { properties: "x,y"; duration: 1000 }
        //            }

    }

    Calendar{
        anchors{left:eventView.right;right:parent.right;top:parent.top;bottom:parent.bottom;margins:Margin}
        onClicked: eventModel.selectedDate=date
    }
}