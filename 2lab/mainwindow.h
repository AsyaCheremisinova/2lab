#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "model.h"
#include "QTableView"
#include "filter.h"
#include <QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void AddRow();
    void DeleteRow();
    void filterOut();
    void resetFilter();
private:
    Ui::MainWindow *ui;
    Model* model;
    QTableView* tableView;
    Filter* proxyModel;
    QComboBox* filterBox;
};
#endif // MAINWINDOW_H
