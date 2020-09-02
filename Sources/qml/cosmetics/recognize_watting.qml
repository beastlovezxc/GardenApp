import QtQuick 2.0

Item {
    Rectangle {
        id: rec_top_bak
        z: 2
        x: 0
        y: 22*root.dpy
        height: 56 * root.dpy
        width: 360 * root.dpx
        color: "#E1C5E8"
        border.color: "#707070"
        border.width: 1 * root.dpx
        Text {
            anchors.left: parent.left
            anchors.leftMargin: 84*root.dpx
            anchors.verticalCenter: parent.verticalCenter
            text: qsTr("AI彩妆识别")
            font.family: "Source Han Sans CN"
            font.pixelSize: 20*root.dpx
            font.weight: Font.Medium
            color: "#6F487A"
        }
    }
    Image {
        id: img_back
        x: 18 * root.dpx
        y: 26 * root.dpy
        z: 4
        height: 54 * root.dpy
        width: 54 * root.dpx
        source: "qrc:/assets/back.png"
        MouseArea {
            anchors.fill: parent
            onClicked:
               root.sceneSource = "garden.qml"
        }
    }
    Image {
        id: img_jiazai
        x: 159 * root.dpx
        y: 278 * root.dpy
        height: 44* root.dpy
        width: 41 * root.dpx
        source: "qrc:/assets/jiazai.png"
    }
    Text {
        text: qsTr("分析中")
        font.pixelSize: 12 * root.dpx
        anchors.horizontalCenter: img_jiazai.horizontalCenter
        anchors.top: img_jiazai.bottom
        anchors.topMargin: 13 * root.dpy
        font.family: "Source Han Sans CN"
        color: "#E1C6E8"
    }

    Rectangle {
        id: rec_footer
        x: 0
        y: 574 * root.dpy
        z: 1
        width: 360 * root.dpx
        height: 66 * root.dpy
        color: "#B79EBB"

        Image {
            id: img_home
            height: 33 * root.dpy
            width: 36 * root.dpx
            anchors.top: parent.top
            anchors.topMargin: 17*root.dpy
            anchors.left: parent.left
            anchors.leftMargin: 68*root.dpx
            z: 2
            source: "qrc:/assets/home.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.sceneSource="garden.qml"
                }
            }
        }
        Image {
            id: img_like
            height: 28 * root.dpy
            width: 35 * root.dpx
            anchors.top: parent.top
            anchors.topMargin: 19*root.dpy
            anchors.horizontalCenter: parent.horizontalCenter
            z: 2
            source: "qrc:/assets/like.png"
        }

        Image {
            id: img_my
            z: 2
            height: 32 * root.dpy
            width: 32 * root.dpx
            anchors.top: parent.top
            anchors.topMargin: 19*root.dpy
            anchors.left: parent.left
            anchors.leftMargin: 257*root.dpx
            source: "qrc:/assets/user2.png"
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    root.sceneSource = "collect/collect_brands.qml"
                }
            }
        }

    }
    Connections {
        target: httpView
        onSignalRecognizeFinished: {
            root.sceneSource = "cosmetics/recognize_result.qml"
        }
    }
}
