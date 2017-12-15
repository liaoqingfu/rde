import QtQuick 2.0
import org.rde.ui 1.0
Item{
    id:details
    anchors{fill:parent}
    scale:0.9
    opacity:0
    ParallelAnimation{
        id:fadeIn
        PropertyAnimation{target:details;property:'scale';to:1;duration:200}
        PropertyAnimation{target:details;property:'opacity';to:1;duration:200}
        PropertyAnimation{target:gameWindow;property:'scale';to:1.1;duration:200}
        PropertyAnimation{target:gameWindow;property:'opacity';to:0;duration:200}
        onStarted: forceActiveFocus()

        //onStarted:libraryPanel.enabled=false
        //onStopped:gameWindow.forceActiveFocus()
    }

    ParallelAnimation{
        id:fadeOut
        PropertyAnimation{target:details;property:'scale';to:0.9;duration:200}
        PropertyAnimation{target:details;property:'opacity';to:0;duration:200}
        PropertyAnimation{target:gameWindow;property:'scale';to:1;duration:200}
        PropertyAnimation{target:gameWindow;property:'opacity';to:1;duration:200}
        onStarted:{}
        //onStopped:{details.destroy();libraryPanel.enabled=true;libraryPanel.forceActiveFocus();}
        onStopped:details.destroy()
    }
    //Component.onCompleted:{fadeIn.start();forceActiveFocus()}
    Component.onCompleted:fadeIn.start()
    Keys.onEscapePressed:fadeOut.start()
}