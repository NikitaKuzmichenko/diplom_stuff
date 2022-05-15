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

    void setBoundingRect(QImage value);
    void calculateUnitPerPixeRatio();
};


#endif // SIMULATIONMAP_H
