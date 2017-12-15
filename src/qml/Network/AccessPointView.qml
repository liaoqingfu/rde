import QtQuick 2.0
import org.rde.network 1.0
ListView{
    id:view
    z:1

    model:AccessPointModel{id:accessPointModel}
    delegate: AccessPointDelegate{}
    boundsBehavior: Flickable.StopAtBounds
    clip:true
    highlight:Rectangle{}
}
