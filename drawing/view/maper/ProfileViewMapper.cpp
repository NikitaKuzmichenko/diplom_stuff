#include "ProfileViewMapper.h"

ProfileViewMapper::ProfileViewMapper(){}

void ProfileViewMapper::calculateUnitPerPixeRatio(){
    minXValue = 0;
    maxXValue = distance;

    minYValue = minHeight;
    maxYValue = maxHeight;

    unitPerPixelY = (maxHeight - minHeight) / boundingRect.height();
    unitPerPixelX = (maxXValue - minXValue) / boundingRect.width();
}
