#ifndef HTTPVIEW_H
#define HTTPVIEW_H

#include <QObject>

#include "Common/GSingleton.h"
#include "Controller/HttpManager.h"

#define gHttpView HttpView::instance()
class HttpView: public QObject, public GSingleton<HttpView>
{
    friend class GSingleton<HttpView>;
    Q_OBJECT
    Q_PROPERTY(QString imagePath READ imagePath WRITE setImagePath NOTIFY imagePathChanged)
    Q_PROPERTY(QString brands READ brands WRITE setBrands NOTIFY brandsChanged)
//    Q_PROPERTY(QString recImagePath READ recImagePath WRITE setRecImagePath recImagePathChanged)
//    Q_PROPERTY(QString brandsList READ brandsList WRITE setBrandsList NOTIFY brandsListChanged)
//    Q_PROPERTY(QString lipsticksList READ lipsticksList WRITE setLipsticksList NOTIFY lipsticksListChanged)
//    Q_PROPERTY(QString seriesList READ seriesList WRITE setSeriesList NOTIFY seriesListChanged)
//    Q_PROPERTY(QString collectList READ collectList WRITE setCollectList NOTIFY collectListChanged)

public:
    HttpView();
    ~HttpView();

    Q_INVOKABLE void getImgsPath();
    Q_INVOKABLE void getBrands();
    Q_INVOKABLE void getLipsticks(int sid);
    Q_INVOKABLE void getSeries(int bid);
    Q_INVOKABLE void getBrandsColl();
    Q_INVOKABLE void getSeriesColl(int bid);
    Q_INVOKABLE void getLipsColl(int sid);
    Q_INVOKABLE void recImage(QString recImagePath, int type);
    Q_INVOKABLE void insertCollection(int lid);
//    Q_INVOKABLE void deleteCollect();
//    Q_INVOKABLE void getCollect();
//    Q_INVOKABLE void addCollect();
//    Q_INVOKABLE void makeupRecommand();
//    Q_INVOKABLE void lipstickRecognition();

    QString imagePath() { return m_imagePath;}
    QString brands() { return m_brands;}
    void setBrands(QString brands);
//    QString recImagePath() { return m_recImagePath;}

public slots:
    void setImagePath(QString imagePath);
//    void setRecImagePath(QString recImagePath);
    void handleData(QString imgPath);
    void slotRecognizeFinished();
    void slotRecommendFinished();

signals:
    void imagePathChanged(QString imagePath);
    void recImagePathChanged(QString recImagePath, int type);
    void signalGetBrands();
    void signalGetSeries(int bid);
    void signalGetLipsticks(int sid);
    void signalGetBrandsColl();
    void signalGetSeriesColl(int bid);
    void signalGetLipsColl(int sid);
    void signalRecognizeFinished();
    void signalRecommendFinished();
    void brandsChanged(QString brands);
    void signalInsertCollection(int lid);

private:
    QString m_imagePath;
    QString m_recImagePath;
    QString m_brands;
    int m_insertCollectionLid;
    int m_recType;
    int m_bid;
    int m_sid;
};

#endif // HTTPVIEW_H
