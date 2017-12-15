import org.rde.core 1.0
import org.rde.ui 1.0
import QtQuick 2.0
ModuleDockItem{
    RBar{anchors.fill: parent}
    Column{
        anchors{fill: parent;margins: Margin}
        spacing:Margin
        StatBar{
            id:cpuBar
            label.text: 'CPU'
        }
        StatBar{
            id:memBar
            label.text: 'RAM'
            bar.value: StatsMonitor.usedRAM
            bar.maximumValue: StatsMonitor.totalRAM
        }
    }
}