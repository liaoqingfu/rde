import QtQuick 2.0
import QtWebKit 3.0
//-------------------------------------------------------------------------------------------------
Rectangle {
    id:view
    anchors.top: topBar.bottom
    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    anchors.margins: 5
    color:"red"


    WebView {
        anchors.fill: parent
        anchors.margins: 5

        //url:"http://www.google.com"
        //settings.pluginsEnabled: true //crash!!

        //-----------------------------------------------------------------------------------------
        onUrlChanged: {
            topBar.addressBar.text=url
        }
        //-----------------------------------------------------------------------------------------
//        onBackChanged: {
//            console.log("Back changed");
//        }
//        //-----------------------------------------------------------------------------------------
//        onForwardChanged: {
//            console.log("Forward changed");
//        }
        //-----------------------------------------------------------------------------------------
    }
}
//-------------------------------------------------------------------------------------------------
