#include "SeriesModel.h"

SeriesList::SeriesList(const int sid, const QString &name)
    :m_name(name), m_sid(sid)
{

}

int SeriesList::sid() const
{
    return m_sid;
}

QString SeriesList::name() const
{
    return m_name;
}

SeriesModel::SeriesModel()
{

}

QString SeriesModel::getName(int index)
{
    if(index < 0 || index >= m_abstractList.count()) {
        return	"";
    }
    return	m_abstractList.at(index).name();
}

int SeriesModel::getIndex(int index)
{
    if(index < 0 || index >= m_abstractList.count()) {
        return	0;
    }
    return	m_abstractList.at(index).sid();
}

void SeriesModel::addList(int sid, QString name)
{
    SeriesList mlist(sid,name);
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_abstractList.append(mlist);
    endInsertRows();
}

int SeriesModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_abstractList.count();
}

QVariant SeriesModel::data(const QModelIndex &index, int role) const
{
    if(index.row()<0||index.row()>=m_abstractList.count())
        return QVariant();
    const SeriesList &abstractList=m_abstractList[index.row()];
    if(role==AbstractListRoles::NameRole)
        return abstractList.name();
    else if(role==AbstractListRoles::IDRole)
        return abstractList.sid();
    return QVariant();
}

bool SeriesModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();

    emit dataChanged(index, index, QVector<int>() << role);
    return true;
}

Qt::ItemFlags SeriesModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

void SeriesModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, m_abstractList.size());
    //清空动态数组
    m_abstractList.clear();
    endRemoveRows();
}

QHash<int, QByteArray> SeriesModel::roleNames() const
{
    QHash<int,QByteArray> roles;

    roles.insert(AbstractListRoles::NameRole,"name");
    roles.insert(AbstractListRoles::IDRole,"s_id");
    return roles;
}
