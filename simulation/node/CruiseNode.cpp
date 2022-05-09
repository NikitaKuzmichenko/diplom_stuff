#include "CruiseNode.h"

CruiseNode::CruiseNode() : NodePoint(){
    type = CRUISE_NODE;
}

CruiseNode::CruiseNode(PhysicalPoint *point) : NodePoint(point){
    type = CRUISE_NODE;
}

CruiseNode::CruiseNode(double longitude, double latitude, double height) : NodePoint(longitude, latitude, height){
    type = CRUISE_NODE;
}

CruiseNode::CruiseNode(PhysicalPoint *point, double v) : NodePoint(point){
    type = CRUISE_NODE;
    this->v = v;
}

CruiseNode::CruiseNode(double longitude, double latitude, double height, double v) : NodePoint(longitude, latitude, height){
    type = CRUISE_NODE;
    this->v = v;
}

double CruiseNode::getV(){
    return v;
}

void CruiseNode::setV(double value){
    v = value;
}
