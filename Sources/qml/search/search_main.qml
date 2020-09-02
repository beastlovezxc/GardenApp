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
            text: qsTr("彩妆查询")
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
    Rectangle {
        id: rec_ai
        x: 16*root.dpx
        y: 97*root.dpy
        z: 4
        color: "transparent"
        width: 328 * root.dpx
        height: 169 * root.dpy
        radius: 15*root.dpx
        Image {
            anchors.fill: parent
            source: "qrc:/assets/aishibie.png"
        }
        MouseArea {
            anchors.fill: parent
            onClicked:
                root.sceneSource = "camera.qml"
        }
    }
    Rectangle {
        id: rec_chungao
        x: 0
        z: 3
        y: 290 * root.dpy
        width: 115*root.dpx
        height: 74*root.dpy
        color: "#E8DFEB"
        Text {
            z: 4
            text: qsTr("唇膏查询")
            font.family: "Source Han Sans CN"
            font.pixelSize: 16*root.dpx
            font.weight: Font.Normal
            anchors.top: parent.top
            anchors.topMargin: 11*root.dpy
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Image {
            z: 4
            height: 23*root.dpy
            width: 37*root.dpx
            anchors.top: parent.top
            anchors.topMargin: 38*root.dpy
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/assets/kouhong_1.png"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.sceneSource="search/search_chungao.qml"
                httpView.getBrands()
            }
        }
    }
    Rectangle {
        id: rec_fendi
        z: 3
        x: 246*root.dpx
        y: 290 * root.dpy
        width: 114*root.dpx
        height: 74*root.dpy
        color: "#E8DFEB"
        Text {
            z: 4
            text: qsTr("粉底查询")
            font.family: "Source Han Sans CN"
            font.pixelSize: 16*root.dpx
            font.weight: Font.Normal
            anchors.top: parent.top
            anchors.topMargin: 11*root.dpy
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Image {
            z: 4
            height: 23*root.dpy
            width: 29*root.dpx
            anchors.top: parent.top
            anchors.topMargin: 35*root.dpy
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/assets/fendiye.png"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.sceneSource="garden.qml"
            }
        }
    }
    Rectangle {
        id: rec_saihong
        z: 3
        x: 123 * root.dpx
        y: 290 * root.dpy
        width: 115*root.dpx
        height: 74*root.dpy
        color: "#E8DFEB"
        Text {
            z: 4
            text: qsTr("腮红查询")
            font.family: "Source Han Sans CN"
            font.pixelSize: 16*root.dpx
            font.weight: Font.Normal
            anchors.top: parent.top
            anchors.topMargin: 11*root.dpy
            anchors.horizontalCenter: parent.horizontalCenter
        }
        Image {
            z: 4
            height: 30*root.dpy
            width: 30*root.dpx
            anchors.top: parent.top
            anchors.topMargin: 34*root.dpy
            anchors.horizontalCenter: parent.horizontalCenter
            source: "qrc:/assets/saihong.png"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                root.sceneSource="garden.qml"
            }
        }
    }

    Rectangle {
        x: 0
        y: 390 * root.dpy
        z: 3
        height: 154 * root.dpy
        width: 360*root.dpx
        color: "#E7DEEA"
        Text {
            text: qsTr("热门推荐")
            font.family: "Source Han Sans CN"
            font.pixelSize: 12*root.dpx
            font.weight: Font.Normal
            anchors.left: parent.left
            anchors.leftMargin: 24*root.dpx
            anchors.top: parent.top
            anchors.topMargin: 6*root.dpy
        }
        Text {
            text: qsTr("全部")
            font.family: "Source Han Sans CN"
            font.pixelSize: 8*root.dpx
            font.weight: Font.Normal
            anchors.left: parent.left
            anchors.leftMargin: 308*root.dpx
            anchors.top: parent.top
            anchors.topMargin: 8*root.dpy
        }
        Image {
            source: "qrc:/assets/back3.png"
            width: 6*root.dpx
            height: 9*root.dpy
            anchors.left: parent.left
            anchors.leftMargin: 329*root.dpx
            anchors.top: parent.top
            anchors.topMargin: 8*root.dpy
        }
        Rectangle {
            border.color: "#8A8A8A"
            border.width: 0.5 * root.dpx
            x: 0
            y: 414*root.dpy
            width: 360*root.dpx
            height: 1*root.dpy
        }
        Image {
            source:"qrc:/assets/ad1.png"
            anchors.top: parent.top
            anchors.topMargin: 52 * root.dpy
            anchors.left: parent.left
            anchors.leftMargin: 15*root.dpx
            width: 151 *root.dpx
            height: 68 * root.dpy
        }
        Image {
            source:"qrc:/assets/ad2.png"
            anchors.top: parent.top
            anchors.topMargin: 52 * root.dpy
            anchors.left: parent.left
            anchors.leftMargin: 192*root.dpx
            width: 151 *root.dpx
            height: 68 * root.dpy
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
