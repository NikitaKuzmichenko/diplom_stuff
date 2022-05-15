#include "ViewMapper.h"

ViewMapper::ViewMapper(){}
ViewMapper::~ViewMapper(){}

ElevationMap *ViewMapper::getElevationMap(){
    return elevationMap;
}

void ViewMapper::setElevationMap(ElevationMap *value){
    elevationMap = value;
}

QRect ViewMapper::getBoundingRect(){
    return boundingRect;
}

void ViewMapper::setBoundingRect(QRect value){
    boundingRect = value;
}
