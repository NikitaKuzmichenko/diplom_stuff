#include "NodePoint.h"

NodePoint::NodePoint(){}

NodePoint::NodePoint(PhysicalPoint *point){
    this->point = point;
}

NodePoint::NodePoint(double longitude, double latitude, double height){
    this->point = new PhysicalPoint(latitude,longitude,height);
}

NodePoint::~NodePoint(){
    if(name!=nullptr){
        delete name;
    }
    delete point;
}

long NodePoint::getId(){
    return id;
}

void NodePoint::setId(long value){
    id = value;
}

QString* NodePoint::getName(){
    return name;
}

void NodePoint::setName(QString *value){
    name = value;
}

PhysicalPoint *NodePoint::getPoint(){
    return point;
}

void NodePoint::setPoint(PhysicalPoint *value){
    point = value;
}

void NodePoint::generateDefaultName(){

}
