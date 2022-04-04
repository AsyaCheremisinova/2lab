#ifndef EDITSTARDIALOG_H
#define EDITSTARDIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include "star.h"
#include <QLineEdit>
#include <QComboBox>

class EditStarDialog: public QDialog
{
  Q_OBJECT
private:
    QLineEdit* editID;
    QLineEdit* editName;
    QComboBox* editСonstellation;
    QLineEdit* editApparentMagnitude;
    QLineEdit* editDistance;
    QLineEdit* editCoordinates;

public:
    EditStarDialog(QWidget* pwgt = nullptr);
    QString id() const;
    QString name() const;
    QString constellation() const;
    QString apparentMagnitude() const;
    QString distance() const;
    QString coordinates() const;


    void SetUpDialog(QString id, QString name,QString constellation,QString apparentMagnitude, QString distance,QString coordinates);
};

#endif // EDITSTARDIALOG_H
