#include "dialogdelegate.h"
#include "QtWidgets"
#include "editstardialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}


bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditStarDialog* editDialog = new EditStarDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Сonstellation = model->data(model->index(index.row(),2,index)).toString();
        QString ApparentMagnitude = model->data(model->index(index.row(),3,index)).toString();
        QString DistanceFromEarth = model->data(model->index(index.row(),4,index)).toString();
        QString Coordinates = model->data(model->index(index.row(),5,index)).toString();


        editDialog->SetUpDialog(ID, Name, Сonstellation, ApparentMagnitude, DistanceFromEarth, Coordinates);
        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->constellation());
            model->setData(model->index(index.row(),3,index),editDialog->apparentMagnitude());
            model->setData(model->index(index.row(),4,index),editDialog->distance());
            model->setData(model->index(index.row(),5,index),editDialog->coordinates());
        }

         editDialog->deleteLater();
    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /* parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
