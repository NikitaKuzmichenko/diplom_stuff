#include "PlaneViewMapper.h"
#include "QDebug"
#include <utils/GeodesicUtils.h>
PlaneViewMapper::PlaneViewMapper(){}

PlaneViewMapper::PlaneViewMapper(QRect boundingRect){
    this->boundingRect = boundingRect;
}

void PlaneViewMapper::setBoundingRect(QImage value){
    this->boundingRect = value.rect();
}

void PlaneViewMapper::calculateUnitPerPixeRatio(){
    unitPerPixelY = GeodesicUtils::toRad(elevationMap->getMaxLatDeg() - elevationMap->getMinLatDeg()) / boundingRect.height();
    unitPerPixelX = GeodesicUtils::toRad(elevationMap->getMaxLongDeg() - elevationMap->getMinLongDeg()) / boundingRect.width();

    minXValue = GeodesicUtils::toRad(elevationMap->getMinLongDeg());
    maxXValue = GeodesicUtils::toRad(elevationMap->getMaxLongDeg());

    minYValue = GeodesicUtils::toRad(elevationMap->getMinLatDeg());
    maxYValue = GeodesicUtils::toRad(elevationMap->getMaxLatDeg());
}
