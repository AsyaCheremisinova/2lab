#include "filter.h"

Filter::Filter(QObject *parent):QSortFilterProxyModel(parent)
{
}

void Filter::updateFilter(QString value)
{
    this->value = value;
    invalidateFilter();
}

bool Filter::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex index = sourceModel()->index(source_row, 2,source_parent);
    QString res = sourceModel()->data(index).toString();
    QVariant v = sourceModel()->data(index, Qt::DisplayRole );
    if(v.isValid())
    {
        if(value == "")
        {
          return true;
        }
        return res == value;

    }
}
