import QtQuick 2.11
import QtQuick.Window 2.11
import Qt.labs.handlers 1.0

Item {
    id: item
    width: bg.width
    height: bg.height
    //title: qsTr("Tap Handler")
    signal qmlSignal()
    Image {
        id: bg
        source: "qrc:/bg.jpeg"
    }
    Rectangle {
        id: forwarder
        width: 100; height: 40
        x: parent.width/2 - width/2
        y: parent.height/2 - height/2
        color: "blue"
        border.color: "white"
        radius: 8
        Text {
            anchors.centerIn: parent
            id: txtBox
            text: qsTr("Button")
        }
        signal btnClicked()
        onBtnClicked: console.log("Send clicked")

        TapHandler {
            id: mousearea

            onTapped:{
                console.log("Mouse clicked")
                item.qmlSignal()
            }
        }

        Component.onCompleted: {
            mousearea.tapped.connect(btnClicked)
        }
    }
}

