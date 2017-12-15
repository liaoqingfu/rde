import QtQuick 2.0
//import QtQuick.Layouts 1.3
import org.rde.ui 1.0
//import QtGraphicalEffects 1.0
Item{
    Column{
        anchors{left:parent.left;right:parent.horizontalCenter;top:parent.top;bottom:parent.verticalCenter;margins:Margin}
        spacing:Margin

        InfoDisplay{
            anchors{left:parent.left;right:parent.right}
            height:72
            Text{
                id:titleLabel
                anchors{left:parent.left;right:parent.right;top:parent.top;bottom:parent.verticalCenter;margins:10}
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                color:'white'


                font{family:DefaultFont;pointSize:26}
                //font.pointSize: 26
                //font.family:DefaultFont
                //font.bold: true

                text:libraryModel.title
                clip:true

                //style:Text.Raised
                //onTextChanged: Voice.say(text)
            }
            Text{
                id:subtitleLabel
                anchors{left:parent.left;right:parent.right;top:parent.verticalCenter;bottom:parent.bottom;margins:Margin}
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                color:'white'
                //font.pointSize: 26
                font{family:DefaultFont;pointSize:26}
                text:libraryModel.subtitle
                clip:true
                //style:Text.Raised
            }

            TextGlow{
                anchors.fill: titleLabel
                source:titleLabel
            }
            TextGlow{
                anchors.fill: subtitleLabel
                source:subtitleLabel
            }
        }
    }
}


/*

    CoverView{
        id:coverView
        anchors{left:parent.horizontalCenter;right:parent.right;top:parent.top;bottom:parent.verticalCenter;margins:5}
        //anchors{left:parent.left;right:parent.right}
        //Layout.fillHeight: true
        z:0
    }

    ColumnLayout{
        z:1
        anchors{left:parent.left;right:parent.horizontalCenter;top:parent.top;bottom:parent.verticalCenter;margins:Margin}



        InfoBar{
            anchors{left:parent.left;right:parent.right;}
            key.text:'Category'
            value.text:libraryModel.category
        }
        //        RatingBar{
        //            anchors{left:parent.left;right:parent.right;}
        //        }



        //        SystemView{
        //            id:systemView
        //            anchors{left:parent.left;right:parent.right}
        //            Layout.minimumHeight: 64
        //            Layout.maximumHeight: 64
        //        }
        //        ReviewView{
        //            anchors{left:parent.left;right:parent.right}
        //            Layout.fillHeight: true
        //        }

        /*
        HistoryView{
            anchors{left:parent.left;right:parent.right}
            Layout.fillHeight: true
        }






        //        MovieView{
        //            id:movieView
        //            anchors{left:parent.left;right:parent.right}
        //            Layout.fillHeight: true
        //        }


        // acts weird when cover
        //        SystemView{
        //            id:systemView
        //            anchors{left:parent.left;right:parent.right}
        //            Layout.fillHeight: true
        //        }
        //        MusicView{
        //            id:musicView
        //            anchors{left:parent.left;right:parent.right}
        //            Layout.fillHeight: true
        //        }
    }
    Connections{
        target: libraryModel
        onGameSelected:infoPanel.update(module,game)
    }


}
*/