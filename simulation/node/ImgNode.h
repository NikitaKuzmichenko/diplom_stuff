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

private:
    double  v;    // скорость
    double  azim; // азимут осевой линии
    double  len;   // длина зоны
    double  width; // ширина зоны

    QString path; // абсолютный путь к каталогу с соотв. mvr/mvm/img
};

#endif // IMGNODE_H
