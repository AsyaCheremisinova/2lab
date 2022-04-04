#include "star.h"

Star::Star(QString ID, QString Name, QString Сonstellation, QString ApparentMagnitude, QString DistanceFromEarth, QString Coordinates, QObject *parent): QObject(parent)
{
    id = ID;
    name = Name;
    constellation = Сonstellation;
    apparentMagnitude = ApparentMagnitude;
    distance = DistanceFromEarth;
    coordinates = Coordinates;
}
void Star::SetID(QString ID)
{
    id = ID;
}
void Star::SetName(QString Name)
{
    name = Name;
}
void Star::SetСonstellation(QString Сonstellation)
{
 constellation = Сonstellation;
}
void Star::SetApparentMagnitude(QString ApparentMagnitude)
{
   apparentMagnitude = ApparentMagnitude;
}
void Star::SetDistance(QString DistanceFromEarth)
{
distance = DistanceFromEarth;
}
void Star::SetCoordinates(QString Coordinates)
{
coordinates = Coordinates;
}
QString Star::ID()
{
    return id;
}
QString Star::Name()
{
    return name;
}
QString Star::Сonstellation()
{
    return constellation;
}
QString Star::ApparentMagnitude()
{
    return apparentMagnitude;
}
QString Star::DistanceFromEarth()
{
    return distance;
}
QString Star::Coordinates()
{
    return coordinates;
}
QStringList Star::GetСonstellations()
{
    QStringList value;
    value.append("Андромеда");
    value.append("Близнецы");
    value.append("Большая Медведица");
    value.append("Большой Пёс");
    value.append("Весы");
    value.append("Водолей");
    value.append("Возничий");
    value.append("Волк");
    value.append("Волопас");
    return value;
}

