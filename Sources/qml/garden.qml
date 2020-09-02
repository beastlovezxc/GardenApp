import QtQuick 2.0
import QtQuick.Controls 2.5
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
            anchors.leftMargin: 28*root.dpx
            anchors.verticalCenter: parent.verticalCenter
            text: qsTr("Garden")
            font.family: "RTWS ShangYa Demo"
            font.pixelSize: 24*root.dpx
            font.weight: Font.Bold
            color: "#6F487A"
        }
    }
    Rectangle {
        id: rec_user
        x: 296*root.dpx
        y: 33*root.dpy
        z: 3
        color: "transparent"
        border.width: 1*root.dpx
        border.color: "#6E4779"
        height: 36*root.dpx
        width: 36*root.dpx
        radius: 18*root.dpx
        Image {
            z: 4
            source: "qrc:/assets/user.png"
            height: 26*root.dpy
            width: 24*root.dpx
            anchors.centerIn: parent
        }
    }

    Rectangle {
        width: 326*root.dpx
        height: 261*root.dpy
        x: 16*root.dpx
        y: 141*root.dpy
        z: 4
        color: "transparent"
        SwipeView {
            id: view

            currentIndex: 1
            anchors.fill: parent

            Item {
                id: firstPage
                Rectangle {
                    color: "transparent"
                    anchors.fill: parent
                    radius: 15*root.dpx
                    anchors.margins: 10*root.dpx
                    Image {
                        anchors.fill: parent
                        source: "qrc:/assets/makeup.png"
                    }
                }
            }
            Item {
                id: secondPage
                Rectangle {
                    color: "transparent"
                    anchors.fill: parent
                    radius: 15*root.dpx
                    anchors.margins: 10*root.dpx
                    Image {
                        anchors.fill: parent
                        source: "qrc:/assets/makeup.png"
                    }
                }
            }
            Item {
                Rectangle {
                    color: "transparent"
                    anchors.fill: parent
                    radius: 15*root.dpx
                    anchors.margins: 10*root.dpx
                    Image {
                        anchors.fill: parent
                        source: "qrc:/assets/makeup.png"
                    }
                }
            }
        }

        PageIndicator {
            id: indicator

            count: view.count
            currentIndex: view.currentIndex

            anchors.bottom: view.bottom
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Rectangle {
        id: rec_kouhong
        width: 88 * root.dpx
        height: 88 * root.dpx
        radius: 44*root.dpx
        x: 28 * root.dpx
        y: 459*root.dpy
        z: 3
        color: "#707070"
        border.color: "#707070"
        border.width: 1 * root.dpx
        Image {
            id: img_kouhong
            anchors.centerIn: parent
            width: 25*root.dpx
            height: 60*root.dpy
            source: "qrc:/assets/kouhong.png"
        }
        MouseArea {
            anchors.fill: parent
            onClicked:
               root.sceneSource = "cosmetics/recommend_camera.qml"
        }
    }
    Text {
        font.family: "Source Han Sans CN"
        font.pixelSize: 15*root.dpx
        color: "#FBF9FC"
        anchors.top: rec_kouhong.bottom
        anchors.topMargin: 8*root.dpy
        anchors.horizontalCenter: rec_kouhong.horizontalCenter
        text: qsTr("彩妆推荐")
    }
    Text {
        font.family: "Source Han Sans CN"
        font.pixelSize: 15*root.dpx
        color: "#FBF9FC"
        anchors.top: rec_chaxun.bottom
        anchors.topMargin: 8*root.dpy
        anchors.horizontalCenter: rec_chaxun.horizontalCenter
        text: qsTr("彩妆查询")
    }
    Text {
        font.family: "Source Han Sans CN"
        font.pixelSize: 15*root.dpx
        color: "#FBF9FC"
        anchors.top: rec_log.bottom
        anchors.topMargin: 8*root.dpy
        anchors.horizontalCenter: rec_log.horizontalCenter
        text: qsTr("美丽日志")
    }

    Rectangle {
        id: rec_chaxun
        width: 88 * root.dpx
        height: 88 * root.dpx
        radius: 44*root.dpx
        x: 136 * root.dpx
        y: 459*root.dpy
        z: 3
        color: "#707070"
        border.color: "#707070"
        border.width: 1 * root.dpx
        MouseArea {
            anchors.fill: parent
            onClicked:
               root.sceneSource = "search/search_main.qml"
        }
        Image {
            id: img_chaxun
            anchors.centerIn: parent
            width: 50*root.dpx
            height: 50*root.dpy
            source: "qrc:/assets/chaxun.png"
        }
    }
    Rectangle {
        id: rec_log
        width: 88 * root.dpx
        height: 88 * root.dpx
        radius: 44*root.dpx
        x: 244 * root.dpx
        y: 459*root.dpy
        z: 3
        color: "#707070"
        border.color: "#707070"
        border.width: 1 * root.dpx
        Image {
            id: img_log
            anchors.centerIn: parent
            width: 25*root.dpx
            height: 60*root.dpy
            source: "qrc:/assets/kouhong.png"
        }
    }
}
