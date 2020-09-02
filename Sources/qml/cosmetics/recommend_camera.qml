import QtQuick 2.4
import QtQuick.Window 2.2
import QtMultimedia 5.12
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    property var cameras: QtMultimedia.availableCameras
    property int currentType: 1
    property int currentCamera: 1
    property var imgPath: ""

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
            text: qsTr("AI彩妆推荐")
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
        id: img_back2
        x: 40*root.dpx
        y: 98 * root.dpy
        z: 4
        width: 10 * root.dpx
        height: 16 * root.dpy
        source: "qrc:/assets/back2.png"
        visible: false
        MouseArea {
            anchors.fill: parent
            onClicked: {
                photoPreview.visible = false
                img_cam_huaban.visible = true
                img_confirm.visible = false
                img_back2.visible = false
                img_front_cam.visible = true
            }
        }
    }
    Image {
        id: img_front_cam
        x: 308 * root.dpx
        y: 96 * root.dpy
        z: 4
        width: 21 * root.dpx
        height: 19 * root.dpy
        visible: true
        source: "qrc:/assets/front_cam.png"
        MouseArea {
            anchors.fill: parent
            onClicked: {
                currentCamera++
                if (currentCamera >= cameras.length)
                    currentCamera = 0
                camera1.deviceId = cameras[currentCamera].deviceId
                console.log(currentCamera)
            }
        }
    }
//    Image {
//        id: img_pic_set
//        x: 69 * root.dpx
//        y: 556 * root.dpy
//        z: 4
//        width: 29 * root.dpx
//        height: 28 * root.dpy
//        source: "qrc:/assets/pic_set.png"
//        MouseArea {
//            anchors.fill: parent
//            onClicked: {
//                httpView.getImgsPath()
//            }
//        }
//    }
    Image {
        id: img_confirm
        x: 150 * root.dpx
        y: 464 * root.dpy
        z: 4
        visible: false
        width: 60 * root.dpx
        height: 60 * root.dpy
        source: "qrc:/assets/confirm.png"
        MouseArea {
            anchors.fill: parent;
            onClicked: {
                httpView.recImage(imgPath, currentType)
//                httpView.recommend_imagePath = imgPath;
//                root.sceneSource = "cosmetics/recognize_watting.qml"
                root.sceneSource = "cosmetics/recommend_watting.qml"
            }
        }
    }

    Image {
        id: img_cam_huaban
        x: 150 * root.dpx
        y: 464 * root.dpy
        z: 4
        visible: true
        width: 60 * root.dpx
        height: 54 * root.dpy
        source: "qrc:/assets/cam_huaban.png"
        MouseArea {
            anchors.fill: parent;
            onClicked: {
                camera1.imageCapture.capture();
            }
        }
    }
    function saveImage() {
        console.log("123123123")
        camera1.imageCapture.captureToLocation("file://"+getCurrentTime())
    }
    function getCurrentTime(){
         var time = Qt.formatDateTime(new Date(), "yyyyMMdd_hh_mm_ss_zzz");
         console.log(time)
         return time;
     }
    Rectangle {
        x: 0
        y: 78 * root.dpy
        z: 2
        width: 360 * root.dpx
        height: 562 * root.dpy
        color: "transparent"
        Camera {
            id: camera1
            deviceId : cameras[currentCamera].deviceId
            captureMode: Camera.CaptureStillImage
            imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash

            focus{
                focusMode:Camera.FocusContinuous;//自动变焦
                focusPointMode: Camera.FocusPointCenter;//中心焦点
            }
            exposure {
                exposureCompensation: -1.0
                exposureMode: Camera.ExposurePortrait
            }

            flash.mode: Camera.FlashRedEyeReduction

            imageCapture {
                id: image_cap
                onImageCaptured: {
                    photoPreview.source = preview  // Show the preview in an Image
                    photoPreview.visible = true
                    img_cam_huaban.visible = false
                    img_confirm.visible = true
                    img_back2.visible = true
                    img_front_cam.visible = false
//                    saveImage()

                }
                onImageSaved: {
                    console.log(path);
                    imgPath = path
                         }

            }
        }



        VideoOutput {
            id:viewfinder
            z: 3
            source: camera1
            fillMode: VideoOutput.PreserveAspectCrop
            anchors.fill: parent
            autoOrientation: true
            focus : visible // to receive focus and capture key events when visible
        }

        Image {
            id: photoPreview
            z: 4
            anchors.fill:parent;
        }
    }
    ListModel {
        id: typeList
        ListElement {
            type: 1
            img_path: "qrc:/assets/type1.png"
            txt: qsTr("基础妆")
        }
        ListElement {
            type: 2
            img_path: "qrc:/assets/type2.png"
            txt: qsTr("少女妆")
        }
        ListElement {
            type: 3
            img_path: "qrc:/assets/type3.png"
            txt: qsTr("活力妆")
        }
        ListElement {
            type: 4
            img_path: "qrc:/assets/type4.png"
            txt: qsTr("优雅妆")
        }
        ListElement {
            type: 5
            img_path: "qrc:/assets/type5.png"
            txt: qsTr("魅惑妆")
        }
        ListElement {
            type: 6
            img_path: "qrc:/assets/type6.png"
            txt: qsTr("梅子妆")
        }
    }

    Component{
             id:typeListDelegate
             Item{
                 id:delegateitem
                 width: 45*root.dpx
                 height:70*root.dpy
                 Rectangle {
                     width: 50*root.dpx
                     height: 50*root.dpy
                     anchors.top: parent.top
                     anchors.horizontalCenter: parent.horizontalCenter
//                     border.width: typeListView.isCurrentItem? 2:0
                     color: delegateitem.ListView.isCurrentItem? "yellow":"transparent"
//                     color: typeListView.isCurrentItem? "yellow":"transparent"
                     Image {
                         source: img_path
                         anchors.centerIn: parent
                         width: 45*root.dpx
                         height: 45*root.dpy
                     }
                 }

                 Text {
                    text: txt
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 57*root.dpy
                    font.family: "Source Han Sans CN"
                    font.pixelSize: 12*root.dpx
                    color: "#FFFFFF"
                 }

                 MouseArea {
                     anchors.fill: parent
                     onClicked:{
                        delegateitem.ListView.view.currentIndex = index
                        currentType = type
                        console.log("currentIndex: " + index)
                        console.log("currentType:" + currentType)
                     }
                 }
             }
         }

    Rectangle {
        x: 0
        y: 551 * root.dpy
        width: 360 * root.dpx
        height: 70 * root.dpy
        z: 4
        color: "transparent"
        ListView {
            id: typeListView
            anchors.fill: parent
            model: typeList
            focus: true
            highlightFollowsCurrentItem :true
            orientation: ListView.Horizontal
            spacing: 20*root.dpx
            delegate: typeListDelegate
        }
    }

}
