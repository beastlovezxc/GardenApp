#include "HttpManager.h"

#include <QNetworkReply>
#include <QUrlQuery>
#include <QHttpPart>
#include <QFile>
#include <QDebug>
#include <QEventLoop>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>

#include "Model/BrandsModel.h"
HttpManager::HttpManager()
{
    this->moveToThread(&m_workthread);
    connect(&m_workthread, SIGNAL(started()), this, SLOT(HttpManagerProcess()), Qt::QueuedConnection);
//    m_serverUrl = "http://192.168.1.3:8000/";
    m_serverUrl = "http://192.168.1.5:8000/";
//    m_serverUrl = "http://192.168.43.173:8000/";
//    m_serverUrl = "http://121.15.171.85:8000/";
    m_workthread.start();
}

HttpManager::~HttpManager()
{
    delete m_manager;
}

void HttpManager::setBrandsList(BrandsModel *brandsList)
{
    m_brandsList = brandsList;
    connect(this, SIGNAL(newBrands(int, QString)), m_brandsList, SLOT(addList(int,QString)), Qt::QueuedConnection);
    connect(this, SIGNAL(clearBrands()), m_brandsList, SLOT(clear()), Qt::QueuedConnection);
}

void HttpManager::setSeriesList(SeriesModel *seriesList)
{
    m_seriesList = seriesList;
    connect(this, SIGNAL(newSeries(int,QString)), m_seriesList, SLOT(addList(int,QString)), Qt::QueuedConnection);
    connect(this, SIGNAL(clearSeries()), m_seriesList, SLOT(clear()), Qt::QueuedConnection);
}

void HttpManager::setLipsticksList(LipsticksModel *lipsticksList)
{
    m_lipsticksList = lipsticksList;
    connect(this, SIGNAL(newLipsticks(LipsticksList_t)), m_lipsticksList, SLOT(addList(LipsticksList_t)), Qt::QueuedConnection);
    connect(this, SIGNAL(clearLipsticks()), m_lipsticksList, SLOT(clear()), Qt::QueuedConnection);
}

void HttpManager::setBrandsCollectionList(BrandsModel *brandsList)
{
    m_brandsCollectionList = brandsList;
    connect(this, SIGNAL(newBrandColl(int, QString)), m_brandsCollectionList, SLOT(addList(int, QString)), Qt::QueuedConnection);
    connect(this, SIGNAL(clearBrandsColl()), m_brandsCollectionList, SLOT(clear()), Qt::QueuedConnection);
}

void HttpManager::setSeriesCollectionList(SeriesModel *seriesList)
{
    m_seriesCollectionList = seriesList;
    connect(this, SIGNAL(newSeriesColl(int, QString)), m_seriesCollectionList, SLOT(addList(int, QString)), Qt::QueuedConnection);
    connect(this, SIGNAL(clearSeriesColl()), m_seriesCollectionList, SLOT(clear()), Qt::QueuedConnection);
}

void HttpManager::setLipsticksCollectionList(LipsticksModel *lipsticksList)
{
    m_lipsticksCollectionList = lipsticksList;
    connect(this, SIGNAL(newLipsColl(LipsticksList_t)), m_lipsticksCollectionList, SLOT(addList(LipsticksList_t)), Qt::QueuedConnection);
    connect(this, SIGNAL(clearLipsColl()), m_lipsticksCollectionList, SLOT(clear()), Qt::QueuedConnection);
}

void HttpManager::setRecogModel(RecogModel *recogModel)
{
    m_recogModel = recogModel;
}

void HttpManager::setRecomModel(RecogModel *recomModel)
{
    m_recomModel = recomModel;
}

void HttpManager::recognizeImg()
{
    QNetworkRequest requestInfo;
    requestInfo.setUrl(m_serverUrl + "api/v1/cosmetics/recognize/"+ m_uploadPath+"/");
//    requestInfo.setUrl(m_serverUrl + "api/v1/cosmetics/recognize/"+ "7"+"/");
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    m_manager->get(requestInfo);
}

void HttpManager::recommendImg()
{
    QNetworkRequest requestInfo;
    requestInfo.setUrl(m_serverUrl + "api/v1/cosmetics/recommend/"+ m_uploadPath+"/" + QString::number(m_recType));
//    requestInfo.setUrl(m_serverUrl + "api/v1/cosmetics/recommend/"+ "7"+"/" + QString::number(m_recType));
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    m_manager->get(requestInfo);
}

void HttpManager::HttpManagerProcess()
{
    m_manager = new QNetworkAccessManager();
//    m_multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    connect(m_manager,&QNetworkAccessManager::finished,this, &HttpManager::replyFinished, Qt::QueuedConnection);
//    QNetworkRequest requestInfo;
//    requestInfo.setUrl(QUrl("http://192.168.1.3:8000/api/v1/activity"));
//    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
//    while(1) {
//        qDebug() << "request" << endl;
//        m_manager->get(requestInfo);
//        m_manager->get(QNetworkRequest(QUrl("http://192.168.1.3:8000/api/v1/activity/")));
//        QThread::sleep(1);
//    }
}

void HttpManager::replyFinished(QNetworkReply *reply)
{
    qDebug() << "response" << endl;
    if(reply->error()!=QNetworkReply::NoError){
            //处理中的错误信息
            qDebug()<<"reply error:"<<reply->errorString();
        }else{
            //请求方式
            qDebug()<<"operation:"<<reply->operation();
            //状态码
            qDebug()<<"status code:"<<reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
            qDebug()<<"url:"<<reply->url();
            //qDebug()<<"raw header:"<<reply->rawHeaderList();
            if (reply->url() == m_serverUrl+"api/v1/cosmetics/brands/") {
                //获取响应信息
                qDebug() << "get brands response" << endl;
                const QByteArray reply_data=reply->readAll();
                qDebug()<<"read all:"<<reply_data;
                QJsonArray json_array = QJsonDocument::fromJson(reply_data).array();
                emit clearBrands();
                for(int i = 0; i < json_array.size(); ++i) {
                    QJsonObject json = json_array.at(i).toObject();
                    emit newBrands(json.value("b_id").toInt(),json.value("name").toString());
                }
            } else if (reply->url() == m_serverUrl+"api/v1/cosmetics/series/" + QString::number(m_bid) + "/") {
                qDebug() << "get series response" << endl;
                const QByteArray reply_data=reply->readAll();
                qDebug()<<"read all:"<<reply_data;
                QJsonArray json_array = QJsonDocument::fromJson(reply_data).array();
                emit clearSeries();
                for(int i = 0; i < json_array.size(); ++i) {
                    QJsonObject json = json_array.at(i).toObject();
//                    SeriesList series(json.value("s_id").toInt(), json.value("name").toString());
                    emit newSeries(json.value("s_id").toInt(), json.value("name").toString());
//                    m_seriesList->addList(series);
                }
            } else if (reply->url() == m_serverUrl+"api/v1/cosmetics/lipsticks/" + QString::number(m_sid) + "/") {
                qDebug() << "get lipsticks response" << endl;
                const QByteArray reply_data=reply->readAll();
                qDebug()<<"read all:"<<reply_data;
                QJsonArray json_array = QJsonDocument::fromJson(reply_data).array();
                emit clearLipsticks();
                for(int i = 0; i < json_array.size(); ++i) {
                    QJsonObject json = json_array.at(i).toObject();
                    LipsticksList_t ll;
                    ll.lid = json.value("l_id").toInt();
                    ll.color = "#"+json.value("color").toString();
                    ll.id = json.value("id").toInt();
                    ll.name = json.value("name").toString();
                    ll.colorGamut = json.value("color_gamut").toString();
                    QJsonObject sjson = json.value("series_info").toObject();
                    ll.sid = sjson.value("s_id").toInt();
                    ll.sname = sjson.value("name").toString();
                    QJsonObject bjson = sjson.value("brands").toObject();
                    ll.bid = bjson.value("b_id").toInt();
                    ll.bname = bjson.value("name").toString();
//                    LipsticksList lipsticks(json.value("l_id").toInt(), json.value("color").toString());
//                    m_lipsticksList->addList(lipsticks);
                    qDebug() << ll.lid << " " <<  ll.color << endl;
                    emit newLipsticks(ll);
                }
            } else if (reply->url() == m_serverUrl + "api/v1/cosmetics/imgurl/upload/" && m_flagType == 1) {
                emit uploadFinish();
                const QByteArray reply_data=reply->readAll();
                QJsonObject json = QJsonDocument::fromJson(reply_data).object();
                m_uploadPath = json.value("img_path").toString();
                qDebug() << "uploadPath: " << m_uploadPath << endl;
                recognizeImg();
            } else if (reply->url() == m_serverUrl + "api/v1/cosmetics/recognize/"+ m_uploadPath+"/" && m_flagType == 1) {
//            } else if (reply->url() == m_serverUrl + "api/v1/cosmetics/recognize/"+ "7"+"/" && m_flagType == 1) {
                const QByteArray reply_data=reply->readAll();
                QJsonObject json = QJsonDocument::fromJson(reply_data).object();
                m_recogModel->setBrands(json.value("brands").toString());
                m_recogModel->setLColor("#"+json.value("color").toString());
                qDebug() << "recogModel color: " << m_recogModel->lColor() << endl;
                m_recogModel->setSeries(json.value("series").toString());
                m_recogModel->setLipsticks(json.value("lipsticks").toString());
                emit signalRecognizeFinished();
            } else if (reply->url() == m_serverUrl + "api/v1/cosmetics/imgurl/upload/" && m_flagType == 2) {
                emit uploadFinish();
                const QByteArray reply_data=reply->readAll();
                QJsonObject json = QJsonDocument::fromJson(reply_data).object();
                m_uploadPath = json.value("img_path").toString();
                qDebug() << "uploadPath: " << m_uploadPath << endl;
                recommendImg();
            } else if (reply->url() == m_serverUrl + "api/v1/cosmetics/recommend/"+ m_uploadPath+"/" +QString::number(m_recType)) {
//            } else if (reply->url() == m_serverUrl + "api/v1/cosmetics/recommend/"+ "7"+"/" +QString::number(m_recType)) {
                const QByteArray reply_data=reply->readAll();
                QJsonObject json = QJsonDocument::fromJson(reply_data).object();
                m_recomModel->setBrands(json.value("brands").toString());
                m_recomModel->setLColor("#"+json.value("color").toString());
                qDebug() << "recomModel color: " << m_recomModel->lColor() << endl;
                m_recomModel->setSeries(json.value("series").toString());
                m_recomModel->setLipsticks(json.value("lipsticks").toString());
                emit signalRecommendFinished();
            } else if (reply->url() == m_serverUrl+"api/v1/cosmetics/userbrands/") {
                //获取响应信息
                qDebug() << "get brands response" << endl;
                const QByteArray reply_data=reply->readAll();
                qDebug()<<"read all:"<<reply_data;
                QJsonArray json_array = QJsonDocument::fromJson(reply_data).array();
                emit clearBrandsColl();
                for(int i = 0; i < json_array.size(); ++i) {
                    QJsonObject json = json_array.at(i).toObject();
                    emit newBrandColl(json.value("b_id").toInt(),json.value("name").toString());
                }
            } else if (reply->url() == m_serverUrl+"api/v1/cosmetics/user_series/" + QString::number(m_bid) + "/") {
                qDebug() << "get series response" << endl;
                const QByteArray reply_data=reply->readAll();
                qDebug()<<"read all:"<<reply_data;
                QJsonArray json_array = QJsonDocument::fromJson(reply_data).array();
                emit clearSeriesColl();
                for(int i = 0; i < json_array.size(); ++i) {
                    QJsonObject json = json_array.at(i).toObject();
//                    SeriesList series(json.value("s_id").toInt(), json.value("name").toString());
                    emit newSeriesColl(json.value("s_id").toInt(), json.value("name").toString());
//                    m_seriesList->addList(series);
                }
            } else if (reply->url() == m_serverUrl+"api/v1/cosmetics/user_lipsticks/" + QString::number(m_sid) + "/") {
                qDebug() << "get lipsticks response" << endl;
                const QByteArray reply_data=reply->readAll();
                qDebug()<<"read all:"<<reply_data;
                QJsonArray json_array = QJsonDocument::fromJson(reply_data).array();
                emit clearLipsColl();
                for(int i = 0; i < json_array.size(); ++i) {
                    QJsonObject json = json_array.at(i).toObject();
                    LipsticksList_t ll;
                    ll.lid = json.value("l_id").toInt();
                    ll.color = "#"+json.value("color").toString();
                    ll.id = json.value("id").toInt();
                    ll.name = json.value("name").toString();
                    ll.colorGamut = json.value("color_gamut").toString();
                    QJsonObject sjson = json.value("series_info").toObject();
                    ll.sid = sjson.value("s_id").toInt();
                    ll.sname = sjson.value("name").toString();
                    QJsonObject bjson = sjson.value("brands").toObject();
                    ll.bid = bjson.value("b_id").toInt();
                    ll.bname = bjson.value("name").toString();
//                    LipsticksList lipsticks(json.value("l_id").toInt(), json.value("color").toString());
//                    m_lipsticksList->addList(lipsticks);
                    qDebug() << ll.lid << " " <<  ll.color << endl;
                    emit newLipsColl(ll);
                }
            }
    }
    reply->deleteLater();

}

void HttpManager::postImageFile(QString imagePath)
{

    QEventLoop eventLoop;
    m_flagType = 1;
    m_imagePath = imagePath;
    QFile *file = new QFile(m_imagePath);
    if (!file->open(QIODevice::ReadOnly) || file->size() == 0) {
        file->close();
        qDebug() << "Open image file error" << endl;
        return ;
    }
    QHttpMultiPart* m_multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart m_imagePart;
    qDebug() << "22222222" << endl;
    m_imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
    m_imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"image\"; filename=\"test.jpg\""));
    m_imagePart.setBodyDevice(file);
    file->setParent(m_multiPart);
    m_multiPart->append(m_imagePart);
    qDebug() << "444444444444" << endl;

    QNetworkRequest m_request;
    m_request.setUrl(m_serverUrl+"api/v1/cosmetics/imgurl/upload/");

    m_reply = m_manager->post(m_request, m_multiPart);
    m_multiPart->setParent(m_reply);
    connect(m_reply, SIGNAL(uploadProgress(qint64,qint64)), this, SLOT(loadProgress(qint64, qint64)));
    eventLoop.exec();
    connect(this, SIGNAL(uploadFinish()), &eventLoop, SLOT(quit()), Qt::QueuedConnection);
    qDebug() << "6666666666666" << endl;
}

void HttpManager::postRecImageFile(QString recImagePath, int type)
{
    QEventLoop eventLoop;
    m_flagType = 2;
    m_recImagePath = recImagePath;
    m_recType = type;
    QFile *file = new QFile(m_recImagePath);
    if (!file->open(QIODevice::ReadOnly) || file->size() == 0) {
        file->close();
        qDebug() << "Open image file error" << endl;
        return ;
    }
    QHttpMultiPart* m_multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart m_imagePart;
    m_imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg"));
    m_imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"image\"; filename=\"test.jpg\""));
    m_imagePart.setBodyDevice(file);
    file->setParent(m_multiPart);
    m_multiPart->append(m_imagePart);

    QNetworkRequest m_request;
    m_request.setUrl(m_serverUrl+"api/v1/cosmetics/imgurl/upload/");

    m_reply = m_manager->post(m_request, m_multiPart);
    m_multiPart->setParent(m_reply);
    connect(m_reply, SIGNAL(uploadProgress(qint64,qint64)), this, SLOT(loadProgress(qint64, qint64)));
    eventLoop.exec();
    connect(this, SIGNAL(uploadFinish()), &eventLoop, SLOT(quit()), Qt::QueuedConnection);
}

void HttpManager::loadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    qDebug() << "loaded" << bytesSent << "of" << bytesTotal << endl;
}

void HttpManager::slotGetBrands()
{
    QNetworkRequest requestInfo;
    requestInfo.setUrl(m_serverUrl+"api/v1/cosmetics/brands/");
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    m_manager->get(requestInfo);
}

void HttpManager::slotGetSeries(int bid)
{
    m_bid = bid;
    QNetworkRequest requestInfo;
    qDebug() << "bid :" << m_bid << endl;
    qDebug() << "bid :" << QString::number(m_bid) << endl;
    requestInfo.setUrl(m_serverUrl+"api/v1/cosmetics/series/" + QString::number(m_bid) + "/");
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    m_manager->get(requestInfo);
}

void HttpManager::slotGetLipsticks(int sid)
{
    m_sid = sid;
    QNetworkRequest requestInfo;
    qDebug() << "sid :" << m_sid << endl;
    qDebug() << "sid :" << QString::number(m_sid) << endl;
    requestInfo.setUrl(m_serverUrl+"api/v1/cosmetics/lipsticks/" + QString::number(m_sid) + "/");
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    m_manager->get(requestInfo);
}

void HttpManager::slotInsertCollection(int lid)
{
    QNetworkRequest requestInfo;
    requestInfo.setUrl(m_serverUrl+"api/v1/cosmetics/user_insert/" + QString::number(lid) + "/");
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    m_manager->get(requestInfo);
}

void HttpManager::slotGetBrandsColl()
{
    QNetworkRequest requestInfo;
    requestInfo.setUrl(m_serverUrl+"api/v1/cosmetics/userbrands/");
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    m_manager->get(requestInfo);
}

void HttpManager::slotGetSeriesColl(int bid)
{
    m_bid = bid;
    QNetworkRequest requestInfo;
    qDebug() << "bid :" << m_bid << endl;
    qDebug() << "bid :" << QString::number(m_bid) << endl;
    requestInfo.setUrl(m_serverUrl+"api/v1/cosmetics/user_series/" + QString::number(m_bid) + "/");
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    m_manager->get(requestInfo);
}

void HttpManager::slotGetLipsColl(int sid)
{
    m_sid = sid;
    QNetworkRequest requestInfo;
    qDebug() << "sid :" << m_sid << endl;
    qDebug() << "sid :" << QString::number(m_sid) << endl;
    requestInfo.setUrl(m_serverUrl+"api/v1/cosmetics/user_lipsticks/" + QString::number(m_sid) + "/");
    requestInfo.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/json"));
    m_manager->get(requestInfo);
}
