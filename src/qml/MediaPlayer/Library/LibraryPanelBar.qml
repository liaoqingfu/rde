import org.rde.ui 1.0
RToolBar{


    RIcon{
        parent:libraryPanelBar.row
        anchors.verticalCenter:parent.verticalCenter
        source:'image://Icon/games-config-options'
        mouse.onClicked:libraryPanel.openImport()
        //mouse.onClicked:libraryPanel.toggleConfigWindow()
    }



    //    Icon{
    //        parent:libraryPanelBar.row
    //        anchors.verticalCenter:parent.verticalCenter
    //        source:'image://Icon/view-file-columns'
    //        //mouse.onClicked:libraryPanel.toggleColumns()
    //    }
    //    LibraryCounter{
    //        parent:libraryPanelBar.row
    //        anchors{top:parent.top;bottom:parent.bottom}
    //        width:100
    //    }
    //    SearchBox{
    //        id:searchBox;
    //        parent:libraryPanelBar.row
    //        anchors{top:parent.top;bottom:parent.bottom}
    //        //enabled:musicLibraryModel.searchEnabled
    //        input.text:libraryModel.filter
    //        //input.maximumLength:musicLibraryModel.filterLength
    //        input.onTextChanged:libraryModel.filter=input.text
    //        //input.onAccepted:libraryPanelView.hey()
    //    }
}