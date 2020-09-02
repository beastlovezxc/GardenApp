#include "RecogModel.h"

RecogModel::RecogModel()
{

}

void RecogModel::setLColor(QString color)
{
    if (m_color != color) {
        m_color = color;
    }
    emit lColorChanged(m_color);
}

void RecogModel::setBrands(QString brands)
{
    if (m_brands != brands) {
        m_brands = brands;
    }
    emit brandsChanged(m_brands);
}

void RecogModel::setSeries(QString series)
{
    if (m_series != series) {
        m_series = series;
    }
    emit seriesChanged(m_series);
}

void RecogModel::setLipsticks(QString lipsticks)
{
    if (m_lipsticks != lipsticks) {
        m_lipsticks = lipsticks;
    }
    emit lipsticksChanged(m_lipsticks);
}
