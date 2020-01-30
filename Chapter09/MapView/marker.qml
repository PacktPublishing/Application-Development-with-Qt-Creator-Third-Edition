import QtQuick 2.12
import QtQuick.Controls 2.12
import QtLocation 5.12

MapQuickItem
{
    property double sizeMultiplier: 1

    id: marker
    anchorPoint.x: 0
    anchorPoint.y: icon.height / 2

    sourceItem: Item
    {
        Image
        {
            id: icon
            source: "img/mapmarker.png"
            sourceSize.width: 60
            sourceSize.height: 60
            width: 60
            height: 60
            anchors.centerIn: parent
        }
    }
}
