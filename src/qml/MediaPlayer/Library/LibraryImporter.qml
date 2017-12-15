import QtQuick 2.0
import org.rde.mediaplayer 1.0
import QtQuick.Controls 1.4
Importer{
    id:importer
    anchors.fill: parent
    Rectangle{
        z:0
        opacity:0.5
        color:'blue'
        anchors.fill: parent
        radius:16
    }
    Column{
        anchors{fill:parent;margins:Margin}
        spacing:Margin
        Rectangle{
            anchors{left:parent.left;right:parent.right}
            height:48
            color:'transparent'
            border.width: 1
            border.color: 'black'
            radius:8

            gradient:Gradient{
                GradientStop {position:0;color:'lightgray'}
                GradientStop {position:0.5;color:'transparent'}
                GradientStop {position:1;color:'black'}
            }
            Text{
                id:currentText
                renderType: Text.NativeRendering
                anchors{left:parent.left;right:parent.horizontalCenter;top:parent.top;bottom:parent.bottom}
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: 'white'
                text:importer.trackIndex
                font.pointSize: 16
            }
            Text{
                id:totalText
                renderType: Text.NativeRendering
                anchors{left:parent.horizontalCenter;right:parent.right;top:parent.top;bottom:parent.bottom}

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: 'white'
                text:importer.total
                font.pointSize: 16
            }
        }
        ProgressBar{
            id:progressBar
            anchors{left:parent.left;right:parent.right}
            height:48
            minimumValue: 0
            enabled: false
            value:importer.trackIndex




            //        Text{
            //            anchors{fill: parent;margins:Margin}
            //            //anchors{left:parent.left;right:parent.right;top:parent.top;margins:Margin}
            //            //height:48
            //            verticalAlignment: Text.AlignVCenter
            //            horizontalAlignment: Text.AlignHCenter
            //            renderType: Text.NativeRendering
            //            color:'white'
            //            style: Text.Raised
            //            font.pointSize: 14
            //            //text:"Import music"
            //            text:scanner.file
            //        }
        }
    }
    onTotalChanged:{
        progressBar.enabled=true
        progressBar.maximumValue=total
    }
}