import QtQuick 2.12
import QtQuick.Window 2.12

import QtLocation 5.12
import QtPositioning 5.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Map View")
    id: window

    property MapQuickItem item

    PositionSource {
        id: src
        updateInterval: 1000
        active: false

        onPositionChanged: {
            var coord = src.position.coordinate;

            map.center = coord;
            item.coordinate = coord;
        }
    }

    Plugin {
        id: mapPlugin
        name: "osm"
    }

    Map {
        id: map
        anchors.fill: parent
        plugin: mapPlugin
        zoomLevel: 14
        minimumZoomLevel: 6
        maximumZoomLevel: 18
        copyrightsVisible: false
        gesture.enabled: true
        gesture.acceptedGestures: MapGestureArea.PinchGesture | MapGestureArea.PanGesture
    }

    Component.onCompleted: {
        map.center = QtPositioning.coordinate(-37.8163521,144.9275631);
        map.zoomLevel = 12;

        var component = Qt.createComponent("marker.qml");
        item = component.createObject(window, { coordinate: QtPositioning.coordinate(-37.8163521,144.9275631) });
        map.addMapItem(item);

        src.active = true
    }
}
