#ifndef DEMNODE_H
#define DEMNODE_H

#include "NodePoint.h"

#include <QString>

/*
 * узловая точка зоны коррекциии по рельефу
*/
class DemNode : public NodePoint{
public:
    DemNode();
    DemNode(PhysicalPoint *point);
    DemNode(PhysicalPoint *point, double v, double azim, double len,double width,QString path);
    DemNode(double longitude, double latitude, double height);
    DemNode(double longitude, double latitude, double height, double v, double azim, double len, double width,QString path);

    double getV();
    void setV(double value);

    double getAzim();
    void setAzim(double value);

    double getLen();
    void setLen(double value);

    double getWidth();
    void setWidth(double value);

    QString getPath();
    void setPath(QString value);

    QString toString();
private:

    double  v = 0;    // скорость
    double  azim = 0; // азимут осевой линии
    double  len = 0;   // длина зоны
    double  width = 0; // ширина зоны

    QString path; // абсолютный путь к каталогу с соотв. mvr/mvm
};

#endif // DEMNODE_H
