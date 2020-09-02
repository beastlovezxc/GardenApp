#ifndef LIPSTICKSMODEL_H
#define LIPSTICKSMODEL_H


#include <QAbstractListModel>
#include <QColor>
typedef struct LipsticksList {
    int lid;
    QString color;
    int id;
    QString name;
    QString colorGamut;
    int sid;
    QString sname;
    int bid;
    QString bname;
}LipsticksList_t;
//class  LipsticksList   //抽象数据列表类
//{
//public:
//    LipsticksList(const int lid,const QString &name);
//    int lid() const;
//    QColor color() const;
//private:
//    int m_lid;
//    QColor m_color;

//};
class LipsticksModel:public QAbstractListModel
{
    Q_OBJECT
public:
    enum AbstractListRoles{
        LIDRole = Qt::UserRole+1,
        LColorRole,
        IDRole,
        NameRole,
        ColorGamutRole,
        SIDRole,
        SNameRole,
        BIDRole,
        BNameRole,
    };
    LipsticksModel();
//    Q_INVOKABLE QColor getColor(int index);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;  //返回给定父项行数
    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;//返回索引所在项给定角色的存储数据
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;
public slots:
    void addList(LipsticksList_t lipsticksList);
    void clear();
protected:
    QHash<int,QByteArray> roleNames() const;  //返回模型的角色名
private:
    QList<LipsticksList_t> m_data;     //抽象列表类容器
    QHash<int,QByteArray> m_roleNames;
};
#endif // LIPSTICKSMODEL_H
