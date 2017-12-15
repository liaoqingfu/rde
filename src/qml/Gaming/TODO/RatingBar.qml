import QtQuick 2.0
import org.rde.ui 1.0
import org.rde.gaming 1.0
Stripe{
    //id:rating
    //height:48

    Text{
        renderType: Text.NativeRendering
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        anchors{left:parent.left;right:parent.horizontalCenter;top:parent.top;bottom:parent.bottom;margins:Margin}
        //anchors{verticalCenter:parent.verticalCenter;left:parent.left;leftMargin:Margin}




        color:'white'
        font.pointSize: 24
        font.family:DefaultFont
        textFormat: Text.PlainText
        //style: Text.Raised
        //styleColor:'black'
        text:'Rating'
    }

    //    Connections{
    //        target:GameLibraryModel
    //        onGameSelected:updateRating(module,game)
    //    }
}