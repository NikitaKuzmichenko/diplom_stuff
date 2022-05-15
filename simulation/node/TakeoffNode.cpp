#include "TakeoffNode.h"

TakeoffNode::TakeoffNode() : NodePoint(){
    type = NP::TAKEOFF_NODE;
}

TakeoffNode::TakeoffNode(PhysicalPoint *point) : NodePoint(point){
    type = NP::TAKEOFF_NODE;
}

TakeoffNode::TakeoffNode(double longitude, double latitude, double height) : NodePoint(longitude, latitude, height){
     type = NP::TAKEOFF_NODE;
}

TakeoffNode::TakeoffNode(PhysicalPoint *point, double v) : NodePoint(point){
    type = NP::TAKEOFF_NODE;
    this->v = v;
}

TakeoffNode::TakeoffNode(double longitude, double latitude, double height, double v) : NodePoint(longitude, latitude, height){
    type = NP::TAKEOFF_NODE;
    this->v = v;
}

double TakeoffNode::getV(){
    return v;
}

void TakeoffNode::setV(double value){
    v = value;
}

QString TakeoffNode::toString(){
    return NodePoint::toString()
        .append("v = " + QString::number(v)).append(" ");
}
