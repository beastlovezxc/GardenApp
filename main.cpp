#include <QGuiApplication>
#include <QQmlContext>
#include <QTextCodec>
#include <QSurfaceFormat>
#include <signal.h>
#include <QtAndroid>
#include <QTimer>
#include <QList>

#include "Common/GQviewer.h"
#include "Model/BrandsModel.h"
#include "Model/SeriesModel.h"
#include "Model/LipsticksModel.h"
#include "Model/RecogModel.h"
#include "View/HttpView.h"

#define SAFE_RELEASE(x)	if ( nullptr != x ) { delete x; x = nullptr; }
QtQuick2Viewer* gHmiView;


bool checkPermission(const QString &permission)
{

    QtAndroid::PermissionResult r = QtAndroid::checkPermission(permission);
       if(r != QtAndroid::PermissionResult::Granted) {
           QtAndroid::requestPermissionsSync( QStringList() << permission );
           r = QtAndroid::checkPermission(permission);
           if(r == QtAndroid::PermissionResult::Denied) {
                return false;
           }
      }


    return true;
}
/*
 * ===  FUNCTION  ======================================================================
 *  Name:  on_hmi_exit_cmd 退出函数
 *  Description:
 * =====================================================================================
 */
void on_hmi_exit_cmd (int pid)
{
    qWarning()<<__FUNCTION__<<pid;
    if(gHmiView != nullptr) {
        gHmiView->hide();
        delete gHmiView;
        gHmiView = nullptr;
    }
    QGuiApplication::exit();
}
int main(int argc, char *argv[])
{
    gHmiView             =     nullptr;
    QGuiApplication app(argc, argv);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    checkPermission( "android.permission.WRITE_EXTERNAL_STORAGE");
    checkPermission( "android.permission.CAMERA");
#if defined(Q_OS_WIN32)
     //TODO
#elif defined(Q_OS_LINUX) || defined(Q_OS_ANDROID)
    signal(SIGUSR1, on_hmi_exit_cmd);	//HMI需要处理进程终止信号
    signal(SIGINT, on_hmi_exit_cmd);    //HMI需要处理进程终止信号
    //signal(SIGCHLD, SIG_IGN);
#endif
    QTimer::singleShot(3000,NULL,[=](){
        QtAndroid::hideSplashScreen(500);
    });
    qRegisterMetaType<LipsticksList_t>("LipsticksList_t");
//    qRegisterMetaType<BrandsList>("BrandsList");
    gHmiView               =       new QtQuick2Viewer();

    BrandsModel brandsList;
    SeriesModel seriesList;
    LipsticksModel lipsticksList;
    RecogModel recogModel;
    RecogModel recomModel;
    BrandsModel brandsCollectionList;
    SeriesModel seriesCollectionList;
    LipsticksModel lipsticksCollectionList;


    gHttpManager->setBrandsList(&brandsList);
    gHttpManager->setSeriesList(&seriesList);
    gHttpManager->setLipsticksList(&lipsticksList);
    gHttpManager->setRecogModel(&recogModel);
    gHttpManager->setRecomModel(&recomModel);
    gHttpManager->setBrandsCollectionList(&brandsCollectionList);
    gHttpManager->setSeriesCollectionList(&seriesCollectionList);
    gHttpManager->setLipsticksCollectionList(&lipsticksCollectionList);
    gHmiView->rootContext()->setContextProperty("httpView", gHttpView);
    gHmiView->rootContext()->setContextProperty("brandsList", &brandsList);
    gHmiView->rootContext()->setContextProperty("seriesList", &seriesList);
    gHmiView->rootContext()->setContextProperty("lipsticksList", &lipsticksList);
    gHmiView->rootContext()->setContextProperty("brandsCollectionList", &brandsCollectionList);
    gHmiView->rootContext()->setContextProperty("seriesCollectionList", &seriesCollectionList);
    gHmiView->rootContext()->setContextProperty("lipsticksCollectionList", &lipsticksCollectionList);
    gHmiView->rootContext()->setContextProperty("recogModel", &recogModel);
    gHmiView->rootContext()->setContextProperty("recomModel", &recomModel);
    //window property
    QSurfaceFormat surfaceFormat = gHmiView->requestedFormat();
    surfaceFormat.setAlphaBufferSize(8);/*颜色缓冲区的alpha通道的大小。*/
    gHmiView->setColor(QColor(Qt::transparent));/*设置窗口为透明*/
    gHmiView->setFormat(surfaceFormat);
    gHmiView->setSource(QStringLiteral("qrc:/qml/main.qml"));
    gHmiView->setResizeMode(QQuickView::SizeRootObjectToView);/*窗体大小根据root.qml决定*/
    gHmiView->showFullScreen();

    return app.exec();
}
