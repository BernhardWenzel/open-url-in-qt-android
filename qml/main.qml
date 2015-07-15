import QtQuick 2.0

Rectangle {
    width: 500
    height: 500
    color: "white"

    Column {
        anchors.fill: parent

        Text {
            id: title
            color: "black"
            font.pixelSize: parent.width / 20
            text: "Url opened: " + openUrlClient.url
            width: parent.width
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
