import QtQuick 2.0
import QtWebKit 3.0
import WebBrowser 1.0
//-------------------------------------------------------------------------------------------------
WebBrowserWebPage {
    id:page
    anchors{top:parent.top;bottom:parent.bottom}
    width:100
    clip:true
    //---------------------------------------------------------------------------------------------
    Rectangle{
        id:background
        z:0
        anchors.fill: parent
        color:'darkblue'
        opacity:0.5
        //border.width: 1
        //border.color: 'white'
    }
    //---------------------------------------------------------------------------------------------
    Text{
        id:title
        //anchors{left: parent.left;leftMargin:5;verticalCenter:parent}
        color:'white'
        font.pointSize: 12
        renderType: Text.NativeRendering
        text:page.url;
    }
    //---------------------------------------------------------------------------------------------
    WebView{
        parent:webBrowserItem.webPageSurface
        anchors.fill: parent
        url:page.url
        //onLoadStarted: console.log("started loading "+page.url)

        onLoadingChanged:console.log("load chaged");
    }

}
//-------------------------------------------------------------------------------------------------
