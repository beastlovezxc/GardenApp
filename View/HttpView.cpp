#include "HttpView.h"

#include <QAndroidJniObject>
#include "Controller/ResultReceiver.h"
#include <QtAndroid>
#include <QAndroidJniEnvironment>
HttpView::HttpView()
{
    m_imagePath = "";
    connect(this, SIGNAL(imagePathChanged(QString)), gHttpManager, SLOT(postImageFile(QString)), Qt::QueuedConnection);
    connect(this, SIGNAL(recImagePathChanged(QString, int)), gHttpManager, SLOT(postRecImageFile(QString, int)), Qt::QueuedConnection);
    connect(this, SIGNAL(signalGetBrands()), gHttpManager, SLOT(slotGetBrands()), Qt::QueuedConnection);
    connect(this, SIGNAL(signalGetSeries(int)), gHttpManager, SLOT(slotGetSeries(int)), Qt::QueuedConnection);
    connect(this, SIGNAL(signalGetLipsticks(int)), gHttpManager, SLOT(slotGetLipsticks(int)), Qt::QueuedConnection);
    connect(this, SIGNAL(signalGetBrandsColl()), gHttpManager, SLOT(slotGetBrandsColl()), Qt::QueuedConnection);
    connect(this, SIGNAL(signalGetSeriesColl(int)), gHttpManager, SLOT(slotGetSeriesColl(int)), Qt::QueuedConnection);
    connect(this, SIGNAL(signalGetLipsColl(int)), gHttpManager, SLOT(slotGetLipsColl(int)), Qt::QueuedConnection);
    connect(gHttpManager, SIGNAL(signalRecognizeFinished()), this, SLOT(slotRecognizeFinished()), Qt::QueuedConnection);
    connect(gHttpManager, SIGNAL(signalRecommendFinished()), this, SLOT(slotRecommendFinished()), Qt::QueuedConnection);
    connect(this, SIGNAL(signalInsertCollection(int)), gHttpManager, SLOT(slotInsertCollection(int)), Qt::QueuedConnection);
}

HttpView::~HttpView()
{

}

void HttpView::getImgsPath()
{
    QAndroidJniObject action = QAndroidJniObject::getStaticObjectField(
                    "android/content/Intent",
                    "ACTION_OPEN_DOCUMENT",
                    "Ljava/lang/String;");
//    QAndroidJniObject action = QAndroidJniObject::fromString("android.intent.action.GET_CONTENT");
    QAndroidJniObject intent("android/content/Intent","(Ljava/lang/String;)V", action.object<jstring>());
    QAndroidJniObject image = QAndroidJniObject::fromString("image/*");
    intent.callObjectMethod("setType", "(Ljava/lang/String;)Landroid/content/Intent;", image.object<jstring>());
    ResultReceiver *receiver = new ResultReceiver(1);
    connect(receiver, SIGNAL(sendData(QString)), this, SLOT(handleData(QString)));
    QtAndroid::startActivity(intent, 1, receiver);
    QAndroidJniEnvironment env;
    if(env->ExceptionCheck())
    {
        qDebug() << "exception occured";
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
}

void HttpView::getBrands()
{
    qDebug() << " get brands" << endl;
    emit signalGetBrands();
}

void HttpView::getLipsticks(int sid)
{
    int m_sid = sid;
    emit signalGetLipsticks(m_sid);
}

void HttpView::getSeries(int bid)
{
    m_bid = bid;
    emit signalGetSeries(m_bid);
}

void HttpView::getBrandsColl()
{
    emit signalGetBrandsColl();
}

void HttpView::getSeriesColl(int bid)
{
    int m_bid = bid;
    emit signalGetSeriesColl(m_bid);
}

void HttpView::getLipsColl(int sid)
{
    int m_sid = sid;
    emit signalGetLipsColl(m_sid);
}

void HttpView::recImage(QString recImagePath, int type)
{
    m_recImagePath = recImagePath;
    m_recType = type;
    emit recImagePathChanged(m_recImagePath, m_recType);
}

void HttpView::insertCollection(int lid)
{
    m_insertCollectionLid = lid;
    emit signalInsertCollection(m_insertCollectionLid);
}

void HttpView::setBrands(QString brands)
{
    if (m_brands != brands)
        m_brands = brands;
    emit brandsChanged(m_brands);
}

void HttpView::setImagePath(QString imagePath)
{
    m_imagePath = imagePath;
    emit imagePathChanged(m_imagePath);
}

void HttpView::handleData(QString imgPath)
{
    qDebug() << imgPath << endl;
}

void HttpView::slotRecognizeFinished()
{
    emit signalRecognizeFinished();
}

void HttpView::slotRecommendFinished()
{
    emit signalRecommendFinished();
}
