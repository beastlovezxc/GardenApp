#ifndef SERIESMODEL_H
#define SERIESMODEL_H

#include <QAbstractListModel>
class  SeriesList   //抽象数据列表类
{
public:
    SeriesList(const int sid,const QString &name);
    int sid() const;
    QString name() const;
private:
    int m_sid;
    QString m_name;

};
class SeriesModel:public QAbstractListModel
{
    Q_OBJECT
public:
    enum AbstractListRoles{
        IDRole=Qt::UserRole+1,
        NameRole,
    };
    SeriesModel();
    Q_INVOKABLE QString getName(int index);
    Q_INVOKABLE int getIndex(int index);
    void addList(SeriesList &list);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;  //返回给定父项行数
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;//返回索引所在项给定角色的存储数据
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;

public slots:
    void addList(int,QString);
    void clear();
protected:
    QHash<int,QByteArray> roleNames() const;  //返回模型的角色名
private:
    QList<SeriesList> m_abstractList;     //抽象列表类容器
};
#endif // SERIESMODEL_H
