#include "LipsticksModel.h"
#include <QDebug>
//LipsticksList::LipsticksList(const int lid, const QString &color)
//    :m_color(color), m_lid(lid)
//{

//}

//int LipsticksList::lid() const
//{
//    return m_lid;
//}

//QColor LipsticksList::color() const
//{
//    return m_color;
//}

LipsticksModel::LipsticksModel()
{
    m_roleNames[LIDRole] = "lid";
    m_roleNames[LColorRole] = "lcolor";
    m_roleNames[IDRole] = "id";
    m_roleNames[NameRole] = "name";
    m_roleNames[ColorGamutRole] = "color_gamut";
    m_roleNames[SIDRole] = "sid";
    m_roleNames[SNameRole] = "sname";
    m_roleNames[BIDRole] = "bid";
    m_roleNames[BNameRole] = "bname";
}

//QColor LipsticksModel::getColor(int index)
//{
//    if(index < 0 || index >= m_abstractList.count()) {
//        return	"";
//    }
//    return	m_abstractList.at(index).color();
//}

void LipsticksModel::addList(LipsticksList_t lipsticksList)
{
    qDebug() << "add lipsticks list " << endl;
    LipsticksList_t ll = lipsticksList;
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_data.append(ll);
    endInsertRows();
    qDebug() << "Now Lipsticks counts are:"<< m_data.count() << endl;
}

int LipsticksModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_data.count();
}

QVariant LipsticksModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();

    if(row < 0 || row >= m_data.count()) {
        return QVariant();
    }
    switch (role) {

    case LIDRole:
        return m_data.value(row).lid;
    case LColorRole:
        return m_data.value(row).color;
    case IDRole:
        return m_data.value(row).id;
    case NameRole:
        return m_data.value(row).name;
    case ColorGamutRole:
        return m_data.value(row).colorGamut;
    case SIDRole:
        return m_data.value(row).sid;
    case SNameRole:
        return m_data.value(row).sname;
    case BIDRole:
        return m_data.value(row).bid;
    case BNameRole:
        return m_data.value(row).bname;
    }

    return QVariant();
}

bool LipsticksModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    int row = index.row();

    emit dataChanged(index, index, QVector<int>() << role);
    return true;
}

Qt::ItemFlags LipsticksModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

void LipsticksModel::clear()
{
    beginRemoveRows(QModelIndex(), 0, m_data.size());
    //清空动态数组
    m_data.clear();
    endRemoveRows();
}

QHash<int, QByteArray> LipsticksModel::roleNames() const
{
    return m_roleNames;
}
