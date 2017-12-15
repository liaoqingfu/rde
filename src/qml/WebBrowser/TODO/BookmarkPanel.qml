import QtQuick 2.0
//import WebBrowser 1.0

Item {



    Rectangle{
        id:background
        anchors.fill: parent
        z:0
        opacity:0.5
        color:'black'
        radius:6
    }

    ListView{
        id:bookmarkView
        anchors.fill: parent
        model:WebBrowserBookmarkModel
        delegate:BookmarkDelegate{}
        spacing:5
        anchors.margins:5
    }

    states: [
        State{name:"on";AnchorChanges{target:bookmarkPanel;anchors.left:parent.left}},
        State{name:"off";AnchorChanges{target:bookmarkPanel;anchors.right:parent.left}}
    ]

    transitions:Transition{
        AnchorAnimation{
            duration:500;
            easing.type: Easing.OutBounce;
        }
    }
    state:"on"
}