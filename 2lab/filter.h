#ifndef FILTER_H
#define FILTER_H
#include <QSortFilterProxyModel>


class Filter: public QSortFilterProxyModel
{
    Q_OBJECT
private:
    QString value = " ";
public:    
   explicit Filter(QObject *parent = nullptr);
public slots:
    void updateFilter(QString value);

protected:
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
};

#endif // FILTER_H
