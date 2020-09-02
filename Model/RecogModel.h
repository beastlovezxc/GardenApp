#ifndef RECOGMODEL_H
#define RECOGMODEL_H

#include <QObject>
#include <QColor>
class RecogModel: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString lColor READ lColor WRITE setLColor NOTIFY lColorChanged)
    Q_PROPERTY(QString brands READ brands WRITE setBrands NOTIFY brandsChanged)
    Q_PROPERTY(QString series READ series WRITE setSeries NOTIFY seriesChanged)
    Q_PROPERTY(QString lipsticks READ lipsticks WRITE setLipsticks NOTIFY lipsticksChanged)
public:
    RecogModel();

    QString lColor() { return m_color;}
    QString brands() { return m_brands;}
    QString series() { return m_series;}
    QString lipsticks() { return m_lipsticks;}

    void setLColor(QString color);
    void setBrands(QString brands);
    void setSeries(QString series);
    void setLipsticks(QString lipsticks);

signals:
    void lColorChanged(QString);
    void brandsChanged(QString);
    void seriesChanged(QString);
    void lipsticksChanged(QString);
private:
    QString m_color;
    QString m_brands;
    QString m_series;
    QString m_lipsticks;
};

#endif // RECOGMODEL_H
