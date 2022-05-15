#ifndef VIEWMAPPER_H
#define VIEWMAPPER_H

#include <simulation/map/ElevationMap.h>
#include <QRect>

class ViewMapper{
public:
    ViewMapper();
    virtual ~ViewMapper();
    ElevationMap *getElevationMap();
    void setElevationMap(ElevationMap *value);

    QRect getBoundingRect();
    void setBoundingRect(QRect value);

    virtual void calculateUnitPerPixeRatio() = 0;

    double unitPerPixelY;
    double unitPerPixelX;

    double minXValue;
    double maxXValue;

    double minYValue;
    double maxYValue;

protected:
    QRect boundingRect;
    ElevationMap *elevationMap;
};

#endif // VIEWMAPPER_H
