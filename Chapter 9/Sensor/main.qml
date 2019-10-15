import QtQuick 2.12
import QtQuick.Window 2.12
import QtPositioning 5.12
import QtSensors 5.12

Window {
    visible: true
    width: 360
    height: 360

    Text {
        id: positionLabel
        text: qsTr("Position:")
        anchors.top: parent.top
        anchors.left: parent.left
        color: position.valid ? "red" : "black"
    }

    Text {
        id: position
        text: qsTr("Hello World")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
    }

    PositionSource {
        id: src
        updateInterval: 1000
        active: true

        onPositionChanged: {
            var coord = src.position.coordinate;
            position.text =
                    Math.abs(coord.latitude) +
                    (coord.latitude < 0 ? " S " : " N " ) +
                    Math.abs(coord.longitude) +
                    (coord.longitude < 0 ? " W " : " E " );
        }
    }

    LabelThreePart {
        id: accelerometerReading
        label: "Accel"
        anchors.top: position.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Accelerometer {
        id: accel
        dataRate: 100
        active:true

        onReadingChanged: {
            accelerometerReading.xValue = (reading.x).toFixed(2);
            accelerometerReading.yValue = (reading.y).toFixed(2);
            accelerometerReading.zValue = (reading.z).toFixed(2);
        }
    }

    LabelThreePart {
        id: gyroscopeReading
        label: "Gyro"
        anchors.top: accelerometerReading.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Gyroscope {
        id: gyroscope
        dataRate: 100
        active: true

        onReadingChanged: {
            gyroscopeReading.xValue = (reading.x).toFixed(2);
            gyroscopeReading.yValue = (reading.y).toFixed(2);
            gyroscopeReading.zValue = (reading.z).toFixed(2);
        }
    }

    Text {
        id: lightSensorLabel
        anchors.top: gyroscopeReading.bottom
        anchors.right: lightSensorValue.left
        text: qsTr("Light Sensor:")
    }

    Text {
        id: lightSensorValue
        anchors.top: lightSensorLabel.top
        anchors.horizontalCenter: parent.horizontalCenter
        text: "N/A"
    }

    // Light Sensor
    LightSensor {
        id: lightSensor
        dataRate: 100
        active: true

        onReadingChanged: {
            lightSensorValue.text = (reading.illuminance).toFixed(2);
        }
    }

    // Magnetometer
    LabelThreePart {
        id: magnetometerReading
        label: "Mag"
        anchors.top: lightSensorValue.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: magcLabel
        anchors.right: magcValue.left
        anchors.top: magnetometerReading.bottom
        text: "Mag Cal: "
    }
    Text {
        id: magcValue
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: magcLabel.top
        text: "N/A"
    }

    Magnetometer {
        onReadingChanged: {
            magnetometerReading.xValue = (reading.x).toFixed(2);
            magnetometerReading.yValue = (reading.y).toFixed(2);
            magnetometerReading.zValue = (reading.z).toFixed(2);
            magcValue.text = (reading.calibrationLevel).toFixed(2);
        }
    }
}
