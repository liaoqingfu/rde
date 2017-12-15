import QtQuick 2.0
import org.rde.ui 1.0
import QtQuick.Layouts 1.3
import org.rde.gaming 1.0
Rectangle{
    color:'transparent'
    border{width:1;color:'black'}
    Layout.minimumWidth: 512
    ColumnLayout{
        anchors{fill:parent;margins:1}
        spacing:0
        InfoDisplay{
            anchors{left:parent.left;right:parent.right}
            height:72
            Flickable{
                id:flick
                anchors.fill:parent


                //                Connections{
                //                    target:LibraryModel
                //                    onTitleChanged:flick.opacity=1
                //                }


                //contentWidth: titleLabel.width
                //opacity:0
                //Behavior on opacity {NumberAnimation{duration:150}}

                Text{
                    id:titleLabel
                    anchors{fill:parent;margins:Margin}
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color:'white'


                    font{family:DefaultFont;pointSize:DefaultLargeFontSize}

                    //font.bold: true

                    text:gameList.model.title
                    clip:true

                    style:Text.Raised
                    //onTextChanged: Voice.say(text)
                }
                TextGlow{
                    id:titleGlow
                    anchors.fill: titleLabel
                    source:titleLabel
                }

            }
            //            Text{
            //                id:subtitleLabel
            //                anchors{left:parent.left;right:parent.right;top:parent.verticalCenter;bottom:parent.bottom;margins:Margin}
            //                horizontalAlignment: Text.AlignLeft
            //                verticalAlignment: Text.AlignVCenter
            //                color:'white'
            //                //font.pointSize: 26
            //                //font{family:DefaultFont;pointSize:26}

            //                font.pointSize: 40
            //                text:libraryModel.subtitle
            //                clip:true
            //                //style:Text.Raised
            //            }


        }
        InfoBar{
            id:developerBar
            anchors{left:parent.left;right:parent.right;}
            key.text:'Developer'
            value.text:gameList.model.developer
        }
        InfoBar{
            id:yearBar
            anchors{left:parent.left;right:parent.right;}
            key.text:'Year'
            value.text:gameList.model.year
        }
        InfoBar{
            id:categoryBar
            anchors{left:parent.left;right:parent.right;}
            key.text:'Category'
            value.text:gameList.model.category
        }
        SystemView{
            id:systemView
            anchors{left:parent.left;right:parent.right}
            Layout.minimumHeight: 64

            //anchors{left:parent.left;bottom:parent.bottom;margins:Margin}
        }

        ReviewView{
            anchors{left:parent.left;right:parent.right}
            Layout.minimumHeight:100
            Layout.fillHeight: true
        }

        //                HistoryView{
        //                    anchors{left:parent.left;right:parent.right}
        //                    Layout.fillHeight: true
        //                }
    }

    RIcon{
        anchors{right:parent.right;bottom:parent.bottom}
        source:'image://Icon/input-gaming'
        mouse.onClicked:gameWindow.refreshDatabase()
        //source:'image://GameLogo/'+Module+'/'+Name
    }

}