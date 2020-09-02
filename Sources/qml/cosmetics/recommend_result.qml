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
        id: img_kouhong
        source: "qrc:/assets/zidantou.png"
        x: 75 * root.dpx
        y: 106*root.dpy
        width: 211*root.dpx
        height: 211*root.dpy
    }
    Text {
        id: txt_kouhong
        text: qsTr(recomModel.lipsticks)
        font.family: "Source Han Sans CN"
        font.weight: Font.Normal
        font.pixelSize: 20*root.dpx
        color: "#E1C6E8"
        anchors.top: img_kouhong.bottom
        anchors.topMargin: 5*root.dpy
        anchors.horizontalCenter: img_kouhong.horizontalCenter
    }
    Rectangle {
        anchors.horizontalCenter: img_kouhong.horizontalCenter
        anchors.top: txt_kouhong.bottom
        anchors.topMargin: 55*root.dpy
        width: 45 * root.dpx
        height: 45 * root.dpy
        color: recomModel.lColor
    }
    Rectangle {
        x: 0
        y: 471 * root.dpy
        width: 360 * root.dpx
        height: 103 * root.dpy
        color: "#856090"
        Text {
            text: qsTr("详情")
            font.family: "Source Han Sans CN"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 13*root.dpy
            font.pixelSize: 12*root.dpx
            color: "#E1C6E8"
        }
        Text {
            id: txt_1
            text: qsTr(recomModel.brands)
            font.family: "Source Han Sans CN"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 45*root.dpy
            font.pixelSize: 12*root.dpx
            color: "#E1C6E8"
        }
        Text {
            id: txt_2
            text: qsTr(recomModel.series)
            font.family: "Source Han Sans CN"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: txt_1.bottom
            anchors.topMargin: 3*root.dpy
            font.pixelSize: 12*root.dpx
            color: "#E1C6E8"
        }
        Text {
            id: txt_3
            text: qsTr(recomModel.lipsticks)
            font.family: "Source Han Sans CN"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: txt_2.bottom
            anchors.topMargin: 3*root.dpy
            font.pixelSize: 12*root.dpx
            color: "#E1C6E8"
        }
        Text {
            id: txt_4
            text: qsTr(recomModel.lColor)
            font.family: "Source Han Sans CN"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: txt_3.bottom
            anchors.topMargin: 3*root.dpy
            font.pixelSize: 12*root.dpx
            color: "#E1C6E8"
        }
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
}
