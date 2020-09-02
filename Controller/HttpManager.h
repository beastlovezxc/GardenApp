#ifndef HTTPMANAGER_H
#define HTTPMANAGER_H

#include <QObject>
#include <QThread>
#include <QNetworkAccessManager>
#include <QHttpPart>
#include "Common/GSingleton.h"
#include "Model/BrandsModel.h"
#include "Model/SeriesModel.h"
#include "Model/LipsticksModel.h"
#include "Model/RecogModel.h"

#define gHttpManager HttpManager::instance()
class HttpManager: public QObject, public GSingleton<HttpManager>
{
    friend class GSingleton<HttpManager>;
    Q_OBJECT
public:
    HttpManager();
    ~HttpManager();
    void setBrandsList(BrandsModel *brandsList);
    void setSeriesList(SeriesModel *seriesList);
    void setLipsticksList(LipsticksModel *lipsticksList);
    void setBrandsCollectionList(BrandsModel *brandsList);
    void setSeriesCollectionList(SeriesModel *seriesList);
    void setLipsticksCollectionList(LipsticksModel *lipsticksList);
    void setRecogModel(RecogModel* recogModel);
    void setRecomModel(RecogModel* recomModel);

private:
    void recognizeImg();
    void recommendImg();
signals:
    void newBrands(int,QString);
    void newLipsticks(LipsticksList_t);
    void newSeries(int,QString);
    void clearBrands();
    void clearLipsticks();
    void clearSeries();
    void uploadFinish();
    void signalRecognizeFinished();
    void signalRecommendFinished();
    void newBrandColl(int, QString);
    void newSeriesColl(int, QString);
    void newLipsColl(LipsticksList_t);
    void clearBrandsColl();
    void clearSeriesColl();
    void clearLipsColl();
private slots:
    void HttpManagerProcess();
    void replyFinished(QNetworkReply *reply);
    void postImageFile(QString imagePath);
    void postRecImageFile(QString recImagePath, int type);
    void loadProgress(qint64, qint64);
    void slotGetBrands();
    void slotGetSeries(int bid);
    void slotGetLipsticks(int sid);
    void slotInsertCollection(int lid);
    void slotGetBrandsColl();
    void slotGetSeriesColl(int bid);
    void slotGetLipsColl(int sid);

private:

    QThread m_workthread;
    QString m_serverUrl;
    QNetworkAccessManager *m_manager;
    QNetworkReply *m_reply;
//    QHttpMultiPart *m_multiPart;
//    QHttpPart m_imagePart;
    QString m_imagePath;
    QString m_recImagePath;
    int m_recType;
    int m_flagType;
    QString m_uploadPath;

    BrandsModel *m_brandsList;
    SeriesModel *m_seriesList;
    LipsticksModel *m_lipsticksList;
    BrandsModel *m_brandsCollectionList;
    SeriesModel *m_seriesCollectionList;
    LipsticksModel *m_lipsticksCollectionList;
    RecogModel* m_recogModel;
    RecogModel* m_recomModel;
    int m_bid;
    int m_sid;
};

#endif // HTTPMANAGER_H
