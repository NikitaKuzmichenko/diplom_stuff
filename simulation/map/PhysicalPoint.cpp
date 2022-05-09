#include "PhysicalPoint.h"

PhysicalPoint::PhysicalPoint(){}

PhysicalPoint::PhysicalPoint(double latitude,double longitude){
    this->latitude = latitude;
    this->longitude = longitude;
}

PhysicalPoint::PhysicalPoint(double latitude,double longitude,double hight){
    this->latitude = latitude;
    this->longitude = longitude;
    this->hight = hight;
}

double PhysicalPoint::getLongitude(){
    return this->longitude;
}

double PhysicalPoint::getLatitude(){
    return this->latitude;
}

double PhysicalPoint::getHight(){
    return this->hight;
}

void PhysicalPoint::setLongitude(double longitude){
    this->longitude = longitude;
}

void PhysicalPoint::setLatitude(double latitude){
    this->latitude = latitude;
}

void PhysicalPoint::setHight(double hight){
    this->hight = hight;
}
