#include "NodePoint.h"
#include <QMetaEnum>

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

double NodePoint::getDistanceFromSegmentStart(){
    return distanceFromSegmentStart;
}

void NodePoint::setDistanceFromSegmentStart(double value){
    distanceFromSegmentStart = value;
}

bool NodePoint::isTurnNode(){
    return this->type == NP::FINISH_NODE
            || this->type == NP::TAKEOFF_NODE
            || this->type == NP::TURN_NODE;
}

bool NodePoint::isUdefinedNode(){
    return this->type == NP::UNDEFINED_NODE;
}

QString NodePoint::toString(){
    QMetaEnum m = QMetaEnum :: fromType <NP ::NodePointType>();
    QString result = QString();
    result.append("id = " + QString::number(id)).append(" ");
    result.append("segment id = " + QString::number(segmentId)).append(" ");
    result.append("type = " + m.valueToKeys(type)).append(" ");
    result.append("lat = "+ QString::number(point->getLatitude())).append(" ");
    result.append("long = "+ QString::number(point->getLongitude())).append(" ");
    result.append("hieght = "+ QString::number(point->getHight())).append(" ");
    result.append("distance = "+ QString::number(distanceFromSegmentStart)).append(" ");
    return result;
}

long NodePoint::getSegmentId(){
    return segmentId;
}

void NodePoint::setSegmentId(long value){
    segmentId = value;
}
