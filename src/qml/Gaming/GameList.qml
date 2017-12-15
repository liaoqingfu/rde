import QtQuick 2.0
import org.rde.ui 1.0
import org.rde.gaming 1.0
ListView{
    anchors{fill:parent;leftMargin:40;rightMargin:40}
    model:LibraryModel{}
    delegate: GameListDelegate{}
    focus:true
    snapMode: ListView.SnapToItem
    boundsBehavior: Flickable.StopAtBounds
    highlightRangeMode:ListView.StrictlyEnforceRange
    highlightMoveDuration:100
    preferredHighlightBegin:height/5*2
    preferredHighlightEnd:height/5*3
    //cacheBuffer:10
    Keys.onPressed:{
        if(event.key===Qt.Key_Backspace)
            gameList.model.backspaceKey()
        else if(event.key===Qt.Key_Delete)
            gameList.model.deleteKey()
        else if(event.key===Qt.Key_Return)
            gameWindow.startGame(gameList.model.module,gameList.model.game)
        else if(event.key===Qt.Key_Escape)
            //gameWindow.destroy()
            Voice.say("escape")
        else{
            gameList.model.typeKey(event.text)
        }
    }
    Connections{
        target:gameList.model
        //onModelReset:{console.log("setting game list index to 0");gameList.currentIndex=0;}

        onModelReset:{
            //Voice.say(gameList.count)
            //if(gameList.model.currentIndex
            gameList.currentIndex=gameList.model.currentIndex;
        }




        //onGameSelected:Voice.say(gameList.model.title)
        //onTitleChanged:Voice.say(title)
    }
    Connections{
        target: gameWindow
        onGameStarted:gamePadConnections.enabled=false
        onGameStopped:gamePadConnections.enabled=true
    }
    //    Connections{
    //        id:gamePadConnections
    //        target:Gamepad
    //        onUpOn:list.decrementCurrentIndex();
    //        onDownOn:list.incrementCurrentIndex();
    //        onAOn:gameWindow.startGame(gameList.model.module,gameList.model.game)
    //        //onSelectOn:gameLibraryView.selectRandomGame();
    //    }



    //    add:Transition{
    //        NumberAnimation { properties: "x"; from: 100; to:19;duration: 1000 }
    //        NumberAnimation { property:"opacity";from:0;to:1;duration:1000}
    //    }

    //        onCurrentIndexChanged:{
    //            flick.opacity=0
    //            //LibraryModel.currentIndex=currentIndex;
    //        }
    onCurrentItemChanged:{
        glow.parent=currentItem;
        glow.anchors.fill=currentItem.logo;
        glow.source=currentItem.logo;
        //selectSound.play()

        gameList.model.currentIndex=currentIndex;
    }

    TextGlow{
        id:glow
        radius:20
        //samples:16
        //spread:2
        color:'hotpink'

        //color:'cyan'
        //transparentBorder: true
    }

    //    Component.onCompleted:{
    //        console.log("setting the list index to "+model.currentIndex)

    //        currentIndex=model.currentIndex
    //    }
}