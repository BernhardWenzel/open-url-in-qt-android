import QtQuick 2.0

Rectangle {
    width: 500
    height: 500
    color: "white"
    property alias text1Text: text1.text

    Text {
        id: text1
        objectName: "urlText"
        color: "black"
        font.pixelSize: parent.width / 30
        text: "..."
        height: parent.height
        width: parent.width
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
