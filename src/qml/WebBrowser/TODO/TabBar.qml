import QtQuick 2.0
import WebBrowser 1.0
//-------------------------------------------------------------------------------------------------
Item{
    //---------------------------------------------------------------------------------------------
//    Rectangle{
//        z:0
//        color:'black'
//        anchors.fill: parent
//        opacity:0.5
//        radius:6
//    }
    //---------------------------------------------------------------------------------------------
    TabModel{id:model}
    //---------------------------------------------------------------------------------------------
    ListView{
        anchors.fill: parent
        anchors.margins: 5
        spacing:5
        orientation: ListView.Horizontal
        delegate:Delegate{}
        model:model
    }
    //---------------------------------------------------------------------------------------------
}
//-------------------------------------------------------------------------------------------------
