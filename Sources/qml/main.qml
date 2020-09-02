import QtQuick 2.9
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

Rectangle {
    objectName: "main"
    id: root
    property var dpx: Screen.desktopAvailableWidth / 360
    property var dpy: Screen.desktopAvailableHeight / 640
    property var sceneSource: "garden.qml"
    visible: true
    width: 360*dpx
    height: 640*dpy
    FontLoader { id: font_sourceHan; source: "qrc:/font/SourceHan.ttf" }
    FontLoader { id: font_rtws; source: "qrc:/font/RTWS.ttf" }
    Loader {
        id: backLoader
        source: "background.qml"
    }
    Loader {
        id: sceneLoader
        source: sceneSource
    }
}
