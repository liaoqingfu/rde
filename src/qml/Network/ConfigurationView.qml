import QtQuick 2.0
import org.rde.network 1.0
import org.rde.ui 1.0
ListView{
    model:ConfigurationModel{id:configModel}
    delegate:ConfigurationDelegate{}
    highlight:ListHighlight{}
    snapMode: ListView.SnapToItem
    boundsBehavior: Flickable.StopAtBounds
    clip:true
    section.property:'Bearer'
    section.criteria:ViewSection.FullString
    section.delegate:Header{
        label.text:section
    }

    onCurrentIndexChanged: configModel.select(currentIndex)
    //onCurrentItemChanged: console.log(currentItem.label.text)
}