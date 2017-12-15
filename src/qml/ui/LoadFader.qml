import QtQuick 2.0
Item {
    id:main
    property int fadeTime:100
    property alias loadA:loadA
    property alias loadB:loadB
    property string currentWindow
    property Loader currentLoader
    clip:true
    Loader{
        id:loadA
        objectName:"LoadA"
        anchors.fill: parent
        opacity: 0
        onSourceChanged:fromBtoA.start()
        asynchronous: true
    }
    Loader{
        id:loadB
        objectName:"LoadB"
        anchors.fill: parent
        opacity: 0
        onSourceChanged:fromAtoB.start()
        asynchronous: true
    }
    ParallelAnimation{
        id:fromAtoB
        PropertyAnimation{target:loadA;property:"opacity";to:0;duration: fadeTime}
        PropertyAnimation{target:loadB;property:"opacity";to:1;duration: fadeTime}
        onStarted: fromBtoA.stop()
        onStopped: loadA.setSource("")
    }

    ParallelAnimation{
        id:fromBtoA
        PropertyAnimation{target:loadA;property:"opacity";to:1;duration: fadeTime}
        PropertyAnimation{target:loadB;property:"opacity";to:0;duration: fadeTime}
        onStarted: fromAtoB.stop()
        onStopped: loadB.setSource("")
    }

    function clear(){
        currentLoader.setSource("")
        currentLoader=loadA
        currentWindow=""
    }

    function set(window){
        if(window===currentWindow){
            clear();
            return null;
        }
        else{
            if(!loadA.item){
                loadA.setSource(window)
                currentWindow=window
                currentLoader=loadA
                return loadA.item
            }
            else{
                loadB.setSource(window)
                currentWindow=window
                currentLoader=loadB
                return loadB.item
            }
        }
    }
}