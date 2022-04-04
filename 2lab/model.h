#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include <QString>
#include "star.h"
class Model: public QAbstractTableModel
{
    Q_OBJECT
public:
    Model(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const ;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex & index) const ;

    void AddStar(Star* star);
    void DeleteStar(int row);

private:
    QList<Star*> stars;   
};

#endif // MODEL_H
