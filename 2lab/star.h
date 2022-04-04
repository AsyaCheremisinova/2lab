#ifndef STAR_H
#define STAR_H

#include <QObject>
#include <QWidget>

class Star: public QObject
{
    Q_OBJECT

public:
    Star(QString ID, QString Name, QString Value, QString ApparentMagnitude, QString DistanceFromEarth, QString Coordinates, QObject *parent = nullptr );
    //virtual ~Star();

    QString ID();
    QString Name();
    QString Сonstellation();
    QString ApparentMagnitude();
    QString DistanceFromEarth();
    QString Coordinates();

    void SetID(QString ID);
    void SetName(QString Name);
    void SetСonstellation(QString Value);
    void SetApparentMagnitude(QString ApparentMagnitude);
    void SetDistance(QString DistanceFromEarth);
    void SetCoordinates(QString Coordinates);

    static QStringList GetСonstellations();

private:
    QString id;
    QString name;
    QString constellation;
    QString apparentMagnitude;
    QString distance;
    QString coordinates;

};

#endif // STAR_H
