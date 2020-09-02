import QtQuick 2.0

Item {
    property int currentIndex: seriesListView.currentIndex
    property string currentSeriesName: ""
    property int currentSeriesIndex: 0
    property string currentSName:""
    property string currentBName:""
    property string currentName:""
    property int currentLid
    property string currentColor:""
    property int currentBid
    property int currentSid
    property int currentID
    property string currentColorGamut

    Component.onCompleted:	{
        currentSeriesName = seriesList.getName(0)
        console.log("currentSeriesName: " + currentSeriesName)
        currentSeriesIndex = seriesList.getIndex(0)
        console.log("currentSeriesIndex: " + currentSeriesIndex)
        httpView.getLipsticks(currentSeriesIndex)
    }
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
            text: qsTr(httpView.brands)
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
               root.sceneSource = "search/search_chungao.qml"
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

    ListView {
        id: seriesListView
        anchors.fill: parent
        model: seriesList
        delegate: Rectangle {
            visible: false
        }
    }
    Text {
        text: qsTr(currentSeriesName)
        font.family: "Source Han Sans CN"
        font.weight: Font.Normal
        font.pixelSize: 20*root.dpx
        color: "#E1C6E8"
        anchors.top: img_kouhong.bottom
        anchors.topMargin: 5*root.dpy
        anchors.horizontalCenter: img_kouhong.horizontalCenter
    }




    Image {
        id: img_left_arrow
        x: 27*root.dpx
        y: 192*root.dpy
        z: 4
        height: 41*root.dpy
        width: 24*root.dpx
        source: "qrc:/assets/left_arrow.png"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                seriesListView.currentIndex--
                if (seriesListView.currentIndex < 0) {
                    seriesListView.currentIndex = seriesListView.count-1;
                }
                currentSeriesName = seriesList.getName(currentIndex)
                currentSeriesIndex = seriesList.getIndex(currentIndex)
                httpView.getLipsticks(currentSeriesIndex)
                console.log(seriesListView.currentIndex);
            }
        }
    }
    Image {
        id: img_right_arrow
        x: 308*root.dpx
        y: 191*root.dpy
        z: 4
        height: 41*root.dpy
        width: 24*root.dpx
        source: "qrc:/assets/right_arrow.png"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                seriesListView.currentIndex++
                if (seriesListView.currentIndex >= seriesListView.count) {
                    seriesListView.currentIndex = 0;
                }
                currentSeriesName = seriesList.getName(currentIndex)
                currentSeriesIndex = seriesList.getIndex(currentIndex)
                httpView.getLipsticks(currentSeriesIndex)
                console.log(seriesListView.currentIndex);
            }
        }
    }
//    Component {
//        id: listDelegate
//        Item {
//            width: 45*root.dpx
//            height: 45*root.dpx
//            Rectangle {
//                z: 5
//                anchors.fill: parent
//                color: lcolor
//                border.width: 1
//                border.color: "#E4E0E0"
//                MouseArea {
//                    anchors.fill: parent
//                    onClicked: {
//                    }
//                }
//            }
//        }
//    }

    Rectangle {
        width: 360 * root.dpx
        height: 45*root.dpy
        x: 0
        y: 398*root.dpy
        z: 3
        color: "transparent"
        ListView {
            z:1
            anchors.fill: parent
            model: lipsticksList
            delegate:
                Item {
                    id:delegateitem
                    width: 50*root.dpx
                    height: 50*root.dpx
                    Rectangle {
                        anchors.fill: parent
                        z: 4
                        color: delegateitem.ListView.isCurrentItem? "yellow":"transparent"
                        Rectangle {
                            z: 5
                            width: 45*root.dpx
                            height: 45*root.dpx
                            anchors.centerIn: parent
                            color: model.lcolor
                            border.width: 1
                            border.color: "#E4E0E0"
                            MouseArea {
//                                m_roleNames[LIDRole] = "lid";
//                                m_roleNames[LColorRole] = "lcolor";
//                                m_roleNames[IDRole] = "id";
//                                m_roleNames[NameRole] = "name";
//                                m_roleNames[ColorGamutRole] = "color_gamut";
//                                m_roleNames[SIDRole] = "sid";
//                                m_roleNames[SNameRole] = "sname";
//                                m_roleNames[BIDRole] = "bid";
//                                m_roleNames[BNameRole] = "bname";
                                anchors.fill: parent
                                onClicked: {
                                    delegateitem.ListView.view.currentIndex = index
                                    console.log("color :"+ model.lcolor)
                                    currentLid = lid
                                    currentColor = lcolor
                                    currentID = id
                                    currentName = name
                                    currentColorGamut = color_gamut
                                    currentSid = sid
                                    currentSName = sname
                                    currentBid = bid
                                    currentBName = bname
                                }
                            }
                        }
                    }
                }

            focus: true
            highlightFollowsCurrentItem :true
            spacing: 10*root.dpx
            orientation: ListView.Horizontal
            snapMode: ListView.SnapOneItem
        }
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
            text: qsTr(currentBName)
            font.family: "Source Han Sans CN"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: 45*root.dpy
            font.pixelSize: 12*root.dpx
            color: "#E1C6E8"
        }
        Text {
            id: txt_2
            text: qsTr(currentSName)
            font.family: "Source Han Sans CN"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: txt_1.bottom
            anchors.topMargin: 3*root.dpy
            font.pixelSize: 12*root.dpx
            color: "#E1C6E8"
        }
        Text {
            id: txt_3
            text: qsTr(currentName)
            font.family: "Source Han Sans CN"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: txt_2.bottom
            anchors.topMargin: 3*root.dpy
            font.pixelSize: 12*root.dpx
            color: "#E1C6E8"
        }
        Text {
            id: txt_4
            text: qsTr(currentColor)
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
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    httpView.insertCollection(currentLid)
                }
            }
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
