import QtQuick 2.0
import QtQuick.Controls 1.4
import Qt.labs.folderlistmodel 2.1
import org.rde.ui 1.0
TableView{
    id:tableView
    backgroundVisible:false
    alternatingRowColors: false
    style:TableStyle{}
    headerDelegate:Header{label.text:styleData.value}
    rowDelegate:RRowDelegate{}
    itemDelegate:FolderDelegate{}
    model:FolderListModel{
        id:folderModel;
        sortField:FolderListModel.Name
        showDirsFirst:true
        showDotAndDotDot:false
    }
    TableViewColumn{
        role:'fileBaseName'
        width:48
        movable:false
        delegate:Image{
            sourceSize{width:32;height:32}
            fillMode:Image.PreserveAspectFit
            width:32
            height:32
            source:'image://MimeIcon/'+tableView.model.get(styleData.row,'filePath')
        }
    }
    TableViewColumn{
        role:'fileName'
        title:'File'
        //width:tableView.width/4*3 //causes binding loop warnings
        movable:false
    }
    TableViewColumn{
        role:'fileSize'
        title:'size'
        //width: tableView.width/4 //causes binding loop warnings
        horizontalAlignment:Text.AlignRight
        movable:false
    }
    onClicked:if(model.isFolder(row))
                  ;
              else
                  FileManager.selectedFile=folderModel.get(row,"filePath")
    onActivated:if(model.isFolder(row))
                    model.folder=folderModel.get(row,"filePath");
                else
                    FileManager.openFile()
}