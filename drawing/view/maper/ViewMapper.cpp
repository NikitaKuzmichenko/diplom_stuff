#include "ViewMapper.h"

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

double ViewMapper::getUnitPerPixelY(){
    return unitPerPixelY;
}

void ViewMapper::setUnitPerPixelY(double value){
    unitPerPixelY = value;
}

double ViewMapper::getUnitPerPixelX(){
    return unitPerPixelX;
}

void ViewMapper::setUnitPerPixelX(double value){
    unitPerPixelX = value;
}
