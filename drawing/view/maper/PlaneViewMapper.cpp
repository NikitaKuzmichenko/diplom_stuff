#include "PlaneViewMapper.h"

PlaneViewMapper::PlaneViewMapper(){}

PlaneViewMapper::PlaneViewMapper(QRect boundingRect){
    this->boundingRect = boundingRect;
}

PlaneViewMapper::~PlaneViewMapper(){
    delete mapImg;
}

void PlaneViewMapper::setImg(QString path){
    mapImg = new QImage(path);
    this->boundingRect = mapImg->rect();
}

void PlaneViewMapper::setImg(QImage *img){
    mapImg = img;
    this->boundingRect = mapImg->rect();
}

QImage *PlaneViewMapper::getImg(){
    return mapImg;
}

void PlaneViewMapper::calculateUnitPerPixeRatio(){
    unitPerPixelY = (elevationMap->getMaxLatDeg() - elevationMap->getMinLatDeg()) / mapImg->height();
    unitPerPixelX = (elevationMap->getMaxLongDeg() - elevationMap->getMinLongDeg()) / mapImg->width();
}
