import QtQuick 2.0
import org.rde.ui 1.0
import QtQuick.Layouts 1.3
Item{
    anchors.fill: parent
    RToolBar{
        id:toolBar
        anchors.top:parent.top
    }
    RowLayout{
        anchors{left:parent.left;right:parent.right;top:toolBar.bottom;bottom:parent.bottom}
        BookmarkPanel{
            id:bookmarkPanel
            anchors{top:parent.top;bottom:parent.bottom}
            width:200
            Layout.minimumWidth:200
        }
        WebPageDisplay{
            anchors{top:parent.top;bottom:parent.bottom}
            Layout.fillWidth: true
        }
    }

//    function toggleBookmarkPanel(){
//        if(bookmarkPanel===null){
//            bookmarkPanel=Qt.createComponent('BookmarkPanel.qml').createObject(webCore);

//            //errorWindow.open("fufufufuenenekek");
//        }
//        else
//            //errorWindow.close();
//            bookmarkPanel.destroy();
//    }

}