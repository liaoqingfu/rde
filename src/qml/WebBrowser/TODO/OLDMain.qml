import QtQuick 2.0
import org.sqew.element 1.0
//-------------------------------------------------------------------------------------------------
Item{
    anchors.fill: parent


    PathBar{
        //anchors.fill: parent
        anchors{left:parent.left;right:parent.right}
    }
    //---------------------------------------------------------------------------------------------
//    BookmarkView{
//        id:bookmarkView
//        anchors{left:parent.left;top:parent.top;bottom:parent.bottom;margins:5}
//        width:200
//    }
    //---------------------------------------------------------------------------------------------
//    TabBar{id:tabBar;
//        //anchors.top:toolBar.bottom
//        anchors{top:parent.top;left:bookmarkView.right;right:parent.right;margins:5}
//        height:40
//    }
    //---------------------------------------------------------------------------------------------
}
//-------------------------------------------------------------------------------------------------
