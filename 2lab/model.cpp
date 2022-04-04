#include "model.h"

Model::Model(QObject *parent)
    :QAbstractTableModel(parent)
{
    //stars = new QList<Star*>();
    Star* std1 = new Star("1","Альферац","Андромеда","2,07","96,87 световых лет","+29‪°5′26″", this);
    Star* std2 = new Star("2","Поллукс","Близнецы","1,15","33,78 световых лет","+28‪°1′34″", this);
    Star* std3 = new Star("3","Алиот","Большая Медведица","1,76","82,52 световых лет","+55°57", this);
    AddStar(std1);
    AddStar(std2);
    AddStar(std3);
}
int Model::rowCount(const QModelIndex &) const
{
   return stars.count();
}

int Model::columnCount(const QModelIndex &) const
{
    return 6;
}
void Model::AddStar(Star* star)
{
    beginInsertRows(QModelIndex(),stars.size(),stars.size());
    stars.append(star);
    endInsertRows();
}
void Model::DeleteStar(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    stars.removeAt(row);
    endRemoveRows();

}
QVariant Model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        Star* str = stars.at(index.row());
        if (index.column() == 0)
        {
            Value = str->ID();
        }
        else if (index.column() == 1)
        {
            Value = str->Name();
        }
        else if (index.column() == 2)
        {
            Value = str->Сonstellation();
        }
        else if (index.column() == 3)
        {
            Value = str->ApparentMagnitude();
        }
        else if (index.column() == 4)
        {
            Value = str->DistanceFromEarth();
        }
        else if (index.column() == 5)
        {
            Value = str->Coordinates();
        }
        else
        {
            Value = "";
        };
       return Value;
    }
    return QVariant();
}
QVariant Model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("ID");
            case 1:
                return QString("Название");
            case 2:
                return QString("Созвездие");
            case 3:
                return QString("Видимая звездная величина");
            case 4:
                return QString("Расстояние от Земли");
            case 5:
                return QString("Координаты");
            }
        }
    }
    return QVariant();
}
bool Model::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        Star* str = stars.at(index.row());
        if (index.column() == 0)
        {
            str->SetID(value.toString());
        }
        else if (index.column() == 1)
        {
            str->SetName(value.toString());
        }
        else if (index.column() == 2)
        {
            str->SetСonstellation(value.toString());
        }
        else if (index.column() == 3)
        {
            str->SetApparentMagnitude(value.toString());
        }
        else if (index.column() == 4)
        {
            str->SetDistance(value.toString());
        }
        else if (index.column() == 5)
        {
            str->SetCoordinates(value.toString());
        }
    }
    //QAbstractTableModel::setData(index,value,  role);
    return true;
}
Qt::ItemFlags Model::flags(const QModelIndex & /*index*/) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}
