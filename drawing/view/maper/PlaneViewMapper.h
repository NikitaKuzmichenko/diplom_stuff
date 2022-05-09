#ifndef SIMULATIONMAP_H
#define SIMULATIONMAP_H


#include "ViewMapper.h"

#include <QImage>
#include <qstring.h>
#include <simulation/map/ElevationMap.h>

class PlaneViewMapper : public ViewMapper{
public:
    PlaneViewMapper();
    PlaneViewMapper(QRect boundingRect);
    ~PlaneViewMapper();

    void setImg(QString path);
    void setImg(QImage *img);
    QImage* getImg();

    void calculateUnitPerPixeRatio();
private:
    QImage *mapImg;
};


#endif // SIMULATIONMAP_H
