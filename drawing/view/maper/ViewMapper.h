#ifndef VIEWMAPPER_H
#define VIEWMAPPER_H

#include <simulation/map/ElevationMap.h>
#include <QRect>

class ViewMapper{
public:
    ElevationMap *getElevationMap();
    void setElevationMap(ElevationMap *value);

    QRect getBoundingRect();
    void setBoundingRect(QRect value);

    double getUnitPerPixelY();
    void setUnitPerPixelY(double value);

    double getUnitPerPixelX();
    void setUnitPerPixelX(double value);

    virtual void calculateUnitPerPixeRatio() = 0;
protected:

    double unitPerPixelY;
    double unitPerPixelX;

    QRect boundingRect;
    ElevationMap *elevationMap;
};

#endif // VIEWMAPPER_H
