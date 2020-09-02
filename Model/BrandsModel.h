#ifndef BRANDSMODEL_H
#define BRANDSMODEL_H

#include <QAbstractListModel>
class  BrandsList   //抽象数据列表类
{
public:
    BrandsList(const int bid,const QString &name);
    int bid() const;
    QString name() const;
private:
    int m_bid;
    QString m_name;

};
class BrandsModel:public QAbstractListModel
{
    Q_OBJECT
public:
    enum AbstractListRoles{
        IDRole=Qt::UserRole+1,
        NameRole,
    };
    BrandsModel();
//    void addList(BrandsList &list);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;  //返回给定父项行数
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;//返回索引所在项给定角色的存储数据
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
//    void update();

public slots:
    void addList(int bid, QString name);
    void clear();
protected:
    QHash<int,QByteArray> roleNames() const;  //返回模型的角色名
private:
    QList<BrandsList> m_abstractList;     //抽象列表类容器
};

#endif // BRANDSMODEL_H
