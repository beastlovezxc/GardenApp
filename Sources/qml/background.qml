import QtQuick 2.0

Item {
    Rectangle {
        x:0
        y:0
        z:0
        height: 640*root.dpy
        width: 360*root.dpx
        gradient: Gradient {
            GradientStop { position: 0.0; color: "#D9AEE4" }
            GradientStop { position: 0.33; color: "#91699C" }
            GradientStop { position: 0.66; color: "#875694" }
            GradientStop { position: 1.0; color: "#56395F" }
        }
    }

    Rectangle {
        x: 0
        y: 0
        z: 1
        height: 24*root.dpy
        width: 360*root.dpx
    }
}
