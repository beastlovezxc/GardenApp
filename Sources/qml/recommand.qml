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
            anchors.leftMargin: 84*root.dpx
            anchors.verticalCenter: parent.verticalCenter
            text: qsTr("彩妆推荐")
            font.family: "Source Han Sans CN"
            font.pixelSize: 20*root.dpx
            color: "#6F487A"
        }
    }
    Image {
        id: img_back
        x: 18 * root.dpx
        y: 26 * root.dpy
        z: 2
        height: 54 * root.dpy
        width: 54 * root.dpx
        source: "qrc:/assets/back.png"
        MouseArea {
            anchors.fill: parent
            onClicked:
               root.sceneSource = "garden.qml"
        }
    }
    Rectangle {
        width: 328*root.dpx
        height: 169*root.dpy
        x: 16*root.dpx
        y: 97*root.dpy
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
                        source: "qrc:/assets/canva.png"
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
                        source: "qrc:/assets/canva.png"
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
                        source: "qrc:/assets/canva.png"
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
        x: 0
        y: 297 * root.dpy
        z:1
        width: 360*root.dpx
        height: 250*root.dpy
        color: "#E7DEEA"
    }
    Rectangle {
        id: rec_add
        z: 2
        x: 160 * root.dpx
        y: 380 * root.dpy
        width: 41 * root.dpx
        height: 41 * root.dpy
        Image {
            id: img_add
            anchors.fill: parent
            source: "qrc:/assets/add.png"
        }
    }
    Text {
        text: qsTr("添加一张照片")
        anchors.top: rec_add.bottom
        anchors.topMargin: 13*root.dpy
        anchors.horizontalCenter: rec_add.horizontalCenter
        z: 2
        font.family: "Source Han Sans CN"
        font.pixelSize: 12*root.dpx
    }

    Rectangle {
        id: rec_footer
        x: 0
        y: 574 * root.dpy
        z: 1
        width: 360 * root.dpx
        height: 66 * root.dpy
        color: "#B79EBB"
    }

    Image {
        id: img_home
        height: 33 * root.dpy
        width: 36 * root.dpx
        x: 71 * root.dpx
        y: 589 * root.dpy
        z: 2
        source: "qrc:/assets/home.png"
    }
    Image {
        id: img_like
        height: 28 * root.dpy
        width: 35 * root.dpx
        x: 162 * root.dpx
        y: 591 * root.dpy
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
