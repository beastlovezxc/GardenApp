#include "BrandsModel.h"
#include <QDebug>

BrandsList::BrandsList(const int bid, const QString &name)
    :m_name(name), m_bid(bid)
{
    qDebug() << "bid is :" << m_bid << endl;
}

int BrandsList::bid() const
{
    return m_bid;
}

QString BrandsList::name() const
{
    return m_name;
}

BrandsModel::BrandsModel()
{

}

void BrandsModel::addList(int bid, QString name)
{
    qDebug() << "add bid is: " << bid << endl;
    qDebug() << "add name is: " << name << endl;
    BrandsList mList(bid, name);
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_abstractList.append(mList);
    endInsertRows();
}

int BrandsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_abstractList.count();
}

QVariant BrandsModel::data(const QModelIndex &index, int role) const
{
    if(index.row()<0||index.row()>=m_abstractList.count())
        return QVariant();
    const BrandsList &abstractList=m_abstractList[index.row()];
    if(role==AbstractListRoles::NameRole)
        return abstractList.name();
    else if(role==AbstractListRoles::IDRole)
        return abstractList.bid();

    return QVariant();
}

bool BrandsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();

    emit dataChanged(index, index, QVector<int>() << role);
    return true;
}

Qt::ItemFlags BrandsModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

//void BrandsModel::update()
//{
//    start_index = createIndex(0, 0);
//    end_index = createIndex((m_abstractList.count() - 1), 0);
//    emit dataChanged(start_index, end_index, QVector<int>() << IDRole << NameRole);
//}

void BrandsModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, m_abstractList.size());
    //清空动态数组
    m_abstractList.clear();
    endRemoveRows();
}

QHash<int, QByteArray> BrandsModel::roleNames() const
{
    QHash<int,QByteArray> roles;

    roles.insert(AbstractListRoles::NameRole,"name");
    roles.insert(AbstractListRoles::IDRole,"bid");
    return roles;
}
