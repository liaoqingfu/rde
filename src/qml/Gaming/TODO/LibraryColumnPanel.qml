import QtQuick 2.0
import QtQuick.Layouts 1.1
import org.rde.gaming 1.0
RowLayout{
    //spacing:5
    LibraryColumnPanelDataColumn{
        label.text:'System'
        //Layout.minimumWidth:200
        Layout.fillWidth:true
    }
    LibraryColumnPanelDataColumn{
        label.text:'Developer'
        //Layout.minimumWidth:200
        Layout.fillWidth:true
    }
    LibraryColumnPanelDataColumn{
        label.text:'Year'
        list.model: YearModel{
            sourceModel:libraryModel
        }



        //Layout.minimumWidth:200
        Layout.fillWidth:true
    }
    LibraryColumnPanelDataColumn{
        label.text:'Category'
        //Layout.minimumWidth:200
        Layout.fillWidth:true
    }
}