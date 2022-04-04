#include "editstardialog.h"
#include "star.h"
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>

EditStarDialog::EditStarDialog(QWidget* pwgt): QDialog(pwgt)
{
    editID = new QLineEdit();
    editName = new QLineEdit();
    editСonstellation = new QComboBox();
    editApparentMagnitude = new QLineEdit();
    editDistance = new QLineEdit();
    editCoordinates = new QLineEdit();

    QStringList constel = Star::GetСonstellations();
    foreach  (QString c, constel)
    {
        editСonstellation->addItem(c);
    }

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("ID"),1,1);
    mainLayout->addWidget(editID,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Созвездие"),3,1);
    mainLayout->addWidget(editСonstellation,3,2);
    mainLayout->addWidget(new QLabel("Видимая звездная величина"),4,1);
    mainLayout->addWidget(editApparentMagnitude,4,2);
    mainLayout->addWidget(new QLabel("Расстояние от Земли"),5,1);
    mainLayout->addWidget(editDistance,5,2);
    mainLayout->addWidget(new QLabel("Координаты на небосклоне"),6,1);
    mainLayout->addWidget(editCoordinates,6,2);


    QPushButton* btnOk = new QPushButton("&ОК");

     mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о звезде");


    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);

}
QString EditStarDialog::id() const
{
    return editID->text();
}
QString EditStarDialog::name() const
{
    return editName->text();
}
QString EditStarDialog::constellation() const
{
    return editСonstellation->currentText();
}
QString EditStarDialog::apparentMagnitude() const
{
    return editApparentMagnitude->text();
}
QString EditStarDialog::distance() const
{
    return editDistance->text();
}
QString EditStarDialog::coordinates() const
{
    return editCoordinates->text();
}

void EditStarDialog::SetUpDialog(QString id, QString name,QString constellation,QString apparentMagnitude, QString distance, QString coordinates)
{
    editID->setText(id);
    editName->setText(name);
    editApparentMagnitude->setText(apparentMagnitude);
    editDistance->setText(distance);
    editCoordinates->setText(coordinates);

    int ind = editСonstellation->findText(constellation);
    if (ind>=0)
    {
        editСonstellation->setCurrentIndex(ind);
    }
}
