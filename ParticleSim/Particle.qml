import QtQuick 1.0

Item {
    property real xvel: 0.0
    property real yvel: 0.0
    property real radius: 10.0
    property alias color: blob.color

    Rectangle {
        id: blob
        anchors.centerIn: parent
        width: parent.radius * 2
        height: parent.radius * 2
        color: "black"
    }

    function move(time_elapsed) {
        x += xvel * (time_elapsed / 1000)
        y += yvel * (time_elapsed / 1000)
    }
}
