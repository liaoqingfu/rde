import QtQuick 2.0
import WebBrowser 1.0
//-------------------------------------------------------------------------------------------------
WebBrowserTabView {
    height:32
    //---------------------------------------------------------------------------------------------
    Rectangle {
        id:background
        anchors.fill: parent
        opacity:0.5
        color:'black'
        //radius:6
    }
    //---------------------------------------------------------------------------------------------
    Item{
        id:tabBar

        anchors.fill: parent

        //-----------------------------------------------------------------------------------------
        Rectangle{
            id:tabBarBackground
            opacity:0.5
            anchors.fill: parent
            radius:6
            color:'darkred'
        }
        //-----------------------------------------------------------------------------------------
        ListView{
            id:listView
            boundsBehavior: Flickable.StopAtBounds
            anchors.fill: parent
            model:WebBrowserPageModel
            delegate:TabDelegate{}
            anchors.margins: 5
            orientation: ListView.Horizontal
            spacing:1
        }
    }
    //-----------------------------------------------------------------------------------------









    //---------------------------------------------------------------------------------------------
    //    Loader{
    //        id:viewLoader
    //        anchors.fill: parent
    //        anchors.margins: 5
    //    }
    //---------------------------------------------------------------------------------------------
    //    WebView {
    //        id:view
    //        anchors.fill: parent
    //    }
    //---------------------------------------------------------------------------------------------
    //property alias view:view

    //---------------------------------------------------------------------------------------------
    //    function addTab(address){
    //        tabModel.append({url:address})

    //        webPage=Qt.createComponent('WebPage.qml').createObject(container);
    //        webPage.openUrl(address)

    //        //webPage.openUrl("http://www.mameworld.info")

    //        //if(bookmarkPanel===null){
    //        //property WebPage page=Qt.createComponent('BookmarkPanel.qml').createObject(webCore);

    //        //errorWindow.open("fufufufuenenekek");
    //        //}
    //        //        else
    //        //            //errorWindow.close();
    //        //            bookmarkPanel.destroy();
    //        //    }


    //        //Qt.createComponent()
    //        //tabModel.append(ListElement{label:url});
    //    }
    //---------------------------------------------------------------------------------------------
}
//-------------------------------------------------------------------------------------------------
