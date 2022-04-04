#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "model.h"
#include "QGridLayout"
#include "editstardialog.h"
#include "dialogdelegate.h"
#include "filter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tableView = new QTableView();
    model = new Model(this);
    proxyModel = new Filter(this);
    proxyModel->setSourceModel(model);
    tableView->setModel( proxyModel );

      DialogDelegate* ddel = new DialogDelegate(nullptr,this);

      tableView->setItemDelegateForColumn(0,ddel);
      tableView->setItemDelegateForColumn(1,ddel);
      tableView->setItemDelegateForColumn(2,ddel);
      tableView->setItemDelegateForColumn(3,ddel);
      tableView->setItemDelegateForColumn(4,ddel);
      tableView->setItemDelegateForColumn(5,ddel);
      tableView->viewport()->setAttribute(Qt::WA_Hover);
      tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);



    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,5);

    QPushButton* add = new QPushButton("Добавить звезду");
    QPushButton* del = new QPushButton("Удалить звезду");
    QPushButton* pbFil = new QPushButton("Найти");
    QPushButton* resetFil = new QPushButton("Сброс");
    filterBox = new QComboBox();
    QStringList constel = Star::GetСonstellations();
    foreach  (QString c, constel)
    {
        filterBox->addItem(c);
    }

    glay->addWidget(add,2,1);
    glay->addWidget(del,2,2);
    glay->addWidget(filterBox,2,3);
    glay->addWidget(pbFil,2,4);
    glay->addWidget(resetFil,2,5);


    proxyModel->updateFilter("");
    QObject::connect(add,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(del,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));
    connect(pbFil, SIGNAL(clicked(bool)),this,SLOT(filterOut()));
    connect(resetFil, SIGNAL(clicked(bool)),this,SLOT(resetFilter()));


    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);
    proxyModel->updateFilter("");


}
void MainWindow::AddRow()
{
    EditStarDialog* addDialog = new EditStarDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        Star* std = new Star(addDialog->id(),addDialog->name(),addDialog->constellation(),addDialog->apparentMagnitude(),addDialog->distance(),addDialog->coordinates(), this);
        model->AddStar(std);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    model->DeleteStar(selList.row());
}
void MainWindow::filterOut()
{
    proxyModel->updateFilter(filterBox->currentText());
}
void MainWindow::resetFilter()
{
    proxyModel->updateFilter("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

