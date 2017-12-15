//import QtQuick 2.0
////import QtQuick.Layouts 1.3
////import QtGraphicalEffects 1.0
////import QtMultimedia 5.8
//import org.neon.ui 1.0
//import org.neon.gaming 1.0
//Item{
//    ListView{
//        orientation: ListView.Horizontal
//        id:libraryView
//        //spacing:Margin
//        //anchors{left:parent.left;right:parent.right;top:filterBox.bottom;bottom:parent.bottom;margins:Margins}
//        anchors.fill: parent
//        clip:true
//        focus:true
//        boundsBehavior:Flickable.StopAtBounds
//        //snapMode:GridView.SnapToRow
//        snapMode:ListView.SnapToItem
//        enabled:libraryModel.isReady
//        model:libraryModel
//        delegate:LibraryDelegate{}
//        //cellWidth:width/libraryModel.gridWidth
//        //cellHeight:height/libraryModel.gridHeight
//        //cacheBuffer:libraryModel.gridWidth*libraryModel.gridHeight*3




//        //onCountChanged:currentIndex=0



//        //preferredHighlightBegin:3
//        //preferredHighlightEnd:3

//        //highlight: Rectangle{color:'darkred'}
//        highlightRangeMode:ListView.StrictlyEnforceRange
//        highlightMoveDuration:100
//        preferredHighlightBegin:height/5*2
//        preferredHighlightEnd:height/5*3


//        onCurrentIndexChanged:libraryModel.currentIndex=currentIndex
//

//        Keys.onPressed:{
//            if(event.key===Qt.Key_Backspace)
//                libraryModel.backspaceKey()
//            else if(event.key===Qt.Key_Delete)
//                libraryModel.deleteKey()
//            else if(event.key===Qt.Key_Return)
//                Gaming.launchGame(libraryModel.module,libraryModel.game)
//            else if(event.key===Qt.Key_Escape)
//                Voice.say("escape")
//            else{
//                libraryModel.typeKey(event.text)
//                //libraryView.currentIndex=0
//            }
//        }
//    }



//    // this causes keypresses to be registered twice!
//    //Keys.forwardTo: libraryView
//    //Component.onCompleted: forceActiveFocus()



//    Rectangle{
//        id:filterBox
//        anchors{left:parent.left;right:parent.right;top:parent.top}
//        height:72
//        color:'darkblue'
//        opacity:0.5
//        Text{
//            id:filterLabel
//            anchors.fill: parent
//            horizontalAlignment: Text.AlignLeft
//            verticalAlignment: Text.AlignVCenter
//            color:'white'
//            text:libraryModel.filter
//            font.pointSize: 26
//            onTextChanged: {
//                if(text.length==0)
//                    filterBox.visible=false
//                else
//                    filterBox.visible=true
//                //Voice.say("clear")
//            }
//        }

//        Connections{
//            target:libraryModel
//            onFilterEmpty:Voice.say("no")
//        }
//    }

//    Component.onCompleted:libraryView.forceActiveFocus()
//}



///*
//ColumnLayout{
//    //    states:[
//    //        State{
//    //            name:'select'
//    //            ParentChange{target:libraryView.currentItem;parent:libraryView}
//    //            PropertyChanges{target:libraryPanel;opacity:1;scale:1;enabled:true}
//    //        },
//    //        State{
//    //            name:'launching'
//    //            ParentChange{target:libraryView.currentItem;parent:gameWindow}
//    //            PropertyChanges{target:libraryPanel;opacity:0;scale:0.8;enabled:false}
//    //        }
//    //    ]
//    //    onStateChanged:
//    //        if(state=="select"){
//    //            //delete gameWindow.detailsWindow.
//    //            Voice.speak("selecting")
//    //        }
//    //        else if(state=="launching"){
//    //            gameWindow.openDetailsWindow()
//    //        }
//    //Behavior on scale{NumberAnimation{duration:500}}
//    //Behavior on opacity{NumberAnimation{duration:500}}
//    //spacing:0
//    ToolBar{
//        id:toolBar
//        Rectangle{
//            anchors{top:parent.top;bottom:parent.bottom;right:parent.right;margins: Margin}
//            width:320
//            color:'black'


//        }
//        Icon{
//            id:configButton
//            parent:toolBar.row
//            anchors.verticalCenter:parent.verticalCenter
//            source:'image://Icon/games-config-options'
//            mouse.onClicked:gameWindow.openConfigWindow()
//        }
//        //        IconShadow{
//        //            source:configButton
//        //            anchors.fill:toolBar
//        //        }
//        Icon{
//            parent:toolBar.row
//            anchors.verticalCenter:parent.verticalCenter
//            source:'image://Icon/view-file-columns'
//            mouse.onClicked:libraryPanel.toggleColumnPanel()
//        }
//        Icon{
//            parent:toolBar.row
//            anchors.verticalCenter:parent.verticalCenter
//            source:'image://Icon/help-feedback'

//            mouse.onClicked:{
//                libraryModel.selectRandomGame();
//                libraryView.currentIndex=libraryModel.currentIndex
//                libraryView.positionViewAtIndex(libraryModel.currentIndex,GridView.Visible)
//            }
//        }
//        InfoDisplay{
//            id:totalDisplay
//            parent:toolBar.row
//            anchors{top:parent.top;bottom:parent.bottom}
//            width:100
//            Text{
//                anchors.fill: parent
//                horizontalAlignment: Text.AlignHCenter
//                verticalAlignment: Text.AlignVCenter
//                renderType: Text.NativeRendering
//                color:'white'
//                text:libraryModel.total
//                font.pointSize: 20
//            }
//        }
//        InfoDisplay{
//            id:countDisplay
//            parent:toolBar.row
//            anchors{top:parent.top;bottom:parent.bottom}
//            width:100
//            Text{
//                anchors.fill: parent
//                horizontalAlignment: Text.AlignHCenter
//                verticalAlignment: Text.AlignVCenter
//                renderType: Text.NativeRendering
//                color:'white'
//                text:libraryView.count
//                font.pointSize: 20
//            }
//        }

//    }

//    /*
//    LibraryColumnPanel{
//        id:columnPanel
//        anchors{left:parent.left;right:parent.right}
//        Layout.minimumHeight: 300
//    }


//    Item{
//        //anchors{left:parent.left;right:parent.right}
//        anchors{left:parent.left}
//        width:320
//        Layout.fillHeight: true



//            Keys.onReturnPressed:activate()
//            //Keys.onReturnPressed: state="launching"

//            onCurrentItemChanged:{
//                glow.parent=currentItem;
//                glow.anchors.fill=currentItem.logo;
//                glow.source=currentItem.logo;


//                //rectGlow.parent=currentItem;
//                //rectGlow.anchors.fill=currentItem.frame;
//                //selectSound.play()

//            }
//            function activate(){
//                //libraryPanel.state='launching'

//                //currentItem.parent=gameWindow

//                gameWindow.openDetailsWindow();
//                //Gaming.launchGame(libraryModel.module,libraryModel.game)
//            }









//            populate: Transition{
//                NumberAnimation { properties:'scale,opacity';from:0;to:1;duration:100}
//            }


//            //        MouseArea{
//            //            anchors.fill: parent
//            //            //hoverEnabled: true
//            //            onEntered: {parent.forceActiveFocus();parent.currentIndex=0}
//            //            //onEntered: {parent.currentIndex=0;parent.currentItem.forceActiveFocus()}
//            //            //onExited: parent
//            //        }


//        }


//        RectangularGlow {
//            id: rectGlow
//            //anchors.fill: rect
//            glowRadius: 8
//            spread: 0.1
//            color: 'cyan'
//            z:0

//            //cornerRadius: rect.radius + glowRadius
//        }

//        SoundEffect{
//            id:selectSound
//            source: "/system/data/sounds/220183__gameaudio__click-casual.wav"
//            volume: 0.3
//        }





//        //Component.onCompleted: console.log("set box to "+libraryModel.filter)

//    }
//    function toggleColumnPanel(){
//        columnPanel.visible=false
//    }
//    property alias libraryView:libraryView

//    //Component.onCompleted: libraryModel.filter="sa"

//        //searchBox.input.text=libraryModel.filter

//}




//            Icon{
//                parent:toolBar.row
//                anchors.verticalCenter:parent.verticalCenter
//                source:'image://Icon/games-config-options'
//                mouse.onClicked:gameWindow.openConfigWindow()
//            }
//            Icon{
//                parent:toolBar.row
//                anchors.verticalCenter:parent.verticalCenter
//                source:'image://Icon/view-file-columns'
//                mouse.onClicked:libraryPanel.toggleColumnPanel()
//            }
//            Icon{
//                parent:toolBar.row
//                anchors.verticalCenter:parent.verticalCenter
//                source:'image://Icon/help-feedback'
//                mouse.onClicked:libraryModel.selectRandomGame();
//            }
//            InfoDisplay{
//                id:totalDisplay
//                parent:toolBar.row
//                anchors{top:parent.top;bottom:parent.bottom}
//                width:100
//                Text{
//                    anchors.fill: parent
//                    horizontalAlignment: Text.AlignHCenter
//                    verticalAlignment: Text.AlignVCenter
//                    renderType: Text.NativeRendering
//                    color:'white'
//                    text:libraryModel.total
//                    font.pointSize: 20
//                }
//            }
//            InfoDisplay{
//                id:countDisplay
//                parent:toolBar.row
//                anchors{top:parent.top;bottom:parent.bottom}
//                width:100
//                Text{
//                    anchors.fill: parent
//                    horizontalAlignment: Text.AlignHCenter
//                    verticalAlignment: Text.AlignVCenter
//                    renderType: Text.NativeRendering
//                    color:'white'
//                    text:"0"
//                    //text:libraryPanelView.count
//                    font.pointSize: 20
//                }
//            }
//            SearchBox{
//                id:searchBox;
//                parent:toolBar.row
//                anchors{top:parent.top;bottom:parent.bottom}
//                enabled:libraryModel.isReady
//                //input.text:libraryModel.filter
//                input.maximumLength:libraryModel.filterLength
//                input.onTextChanged:libraryModel.filter=input.text
//                input.onAccepted:{
//                    libraryView.currentIndex=0
//                    libraryView.forceActiveFocus()
//                }
//            }
//        }

//*/