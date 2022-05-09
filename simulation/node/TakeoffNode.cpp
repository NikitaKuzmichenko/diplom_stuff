#include "TakeoffNode.h"

TakeoffNode::TakeoffNode() : NodePoint(){
    type = TAKEOFF_NODE;
}

TakeoffNode::TakeoffNode(PhysicalPoint *point) : NodePoint(point){
    type = TAKEOFF_NODE;
}

TakeoffNode::TakeoffNode(double longitude, double latitude, double height) : NodePoint(longitude, latitude, height){
     type = TAKEOFF_NODE;
}

TakeoffNode::TakeoffNode(PhysicalPoint *point, double v) : NodePoint(point){
    type = TAKEOFF_NODE;
    this->v = v;
}

TakeoffNode::TakeoffNode(double longitude, double latitude, double height, double v) : NodePoint(longitude, latitude, height){
    type = TAKEOFF_NODE;
    this->v = v;
}

double TakeoffNode::getV(){
    return v;
}

void TakeoffNode::setV(double value){
    v = value;
}
