import QtQuick 2.0
import org.rde.ui 1.0
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
Rectangle{
    id:toolBar
    height:72

    Row{
        anchors.fill: parent


        Icon{
            //parent:toolBar.row
            anchors{verticalCenter:parent.verticalCenter}
            width:64
            height:64
            sourceSize{width:width;height:height}
            source:"image://Icon/server-database"
            mouse.onClicked:gameModuleModel.importModuleData()
        }
        Icon{
            //parent:toolBar.row
            anchors{verticalCenter:parent.verticalCenter}
            width:64
            height:64
            sourceSize{width:width;height:height}
            source:"image://Icon/edit-delete"
            mouse.onClicked:gameModuleModel.deleteModuleData();
            enabled:gameModuleModel.allowDeleteData;
        }

        BusyIndicator{
            running: image.status === Image.Loading

        }
    }
}


/*
    //height:128
    //color:'darkblue'
    //border{width:2;color:'cyan'}

    //Row{
        //anchors{fill:parent}
        //spacing:Margin


        //gradient: Gradient{GradientStop{color:Qt.red}}

        //color:"transparent"



        //    Glow{
        //        anchors.fill: parent
        //        source: parent
        //        color:'cyan'
        //        samples: 8
        //    }



        Text{
            anchors{top:parent.top;bottom:parent.bottom}
            verticalAlignment: Text.AlignVCenter
            renderType: Text.NativeRendering
            color:'white'
            //text:'Games:'+gameModuleModel.currentRowCount;
        }
    }
    //    Button{
    //        anchors{top:parent.top;bottom:parent.bottom;right:parent.right;margins:Margin}
    //        width:height


    //        BusyIndicator{
    //        }
    //    }
}
*/