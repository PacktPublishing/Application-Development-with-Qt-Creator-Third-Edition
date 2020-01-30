import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 180
    height: 360
    title: qsTr("Slow Button")

    Column
    {
        spacing: 20
        Button
        {
            delay: 10000;
            label: "fast";
        }
        Button
        {
            delay: 100000;
            label: "medium";
        }
        Button
        {
            delay: 300000;
            label: "slow";
        }
    }
}
