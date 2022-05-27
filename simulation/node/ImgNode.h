#ifndef IMGNODE_H
#define IMGNODE_H

#include "NodePoint.h"
#include <QString>

/*
 * узловая точка зоны коррекциии по изображению
*/
class ImgNode : public NodePoint{
public:
    ImgNode();
    ImgNode(PhysicalPoint *point);
    ImgNode(PhysicalPoint *point, double v, double azim, double len,double width,QString path);
    ImgNode(double longitude, double latitude, double height);
    ImgNode(double longitude, double latitude, double height, double v, double azim, double len,double width,QString path);

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

    QString path; // абсолютный путь к каталогу с соотв. mvr/mvm/img
};

#endif // IMGNODE_H
