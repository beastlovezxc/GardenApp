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
            text: qsTr("唇膏查询")
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
    Component {
        id: listDelegate
        Item {
            width: 360*root.dpx
            height: 35*root.dpy
            Rectangle {
                z: 2
                anchors.fill: parent
                color: "transparent"
                border.width: 1
                border.color: "#E4E0E0"
                Image {
                    z: 3
//                    source: img_path
                    source: "qrc:/assets/mac.png"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 34*root.dpx
                    width: 22*root.dpx
                    height: 22*root.dpx
                }
                Text {
                    z: 3
                    text: name
                    font.family: "Source Han Sans CN"
                    font.pixelSize: 12*root.dpx
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 77*root.dpx
                }
                Image {
                    z: 3
                    source: "qrc:/assets/goto.png"
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.left: parent.left
                    anchors.leftMargin: 331*root.dpx
                    height: 10*root.dpy
                    width: 7*root.dpx
                }
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        root.sceneSource="search/search_chungao_series.qml"
                        httpView.brands = name
                        httpView.getSeries(bid)
                    }
                }
            }
        }
    }

    Rectangle {
        width: 360 * root.dpx
        height: 496*root.dpy
        x: 0
        y: 78*root.dpy
        z: 1
        color: "transparent"
        ListView {
            z:1
            anchors.fill: parent
//            model: listModels
            model: brandsList
            delegate: listDelegate
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
