#include "ClimbNode.h"

ClimbNode::ClimbNode() : NodePoint(){
    type = NP::CLIMB_NODE;
}

ClimbNode::ClimbNode(PhysicalPoint *point) : NodePoint(point){
    type = NP::CLIMB_NODE;
}

ClimbNode::ClimbNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height){
    type = NP::CLIMB_NODE;
}

ClimbNode::ClimbNode(PhysicalPoint *point, double theta, double v, double newH) : NodePoint(point){
    type = NP::CLIMB_NODE;
    this->theta = theta;
    this->v = v;
    this->newH = newH;
}

ClimbNode::ClimbNode(double longitude, double latitude, double height, double theta, double v, double newH) : NodePoint(longitude,latitude,height){
    type = NP::CLIMB_NODE;
    this->theta = theta;
    this->v = v;
    this->newH = newH;
}

double ClimbNode::getTheta(){
    return theta;
}

void ClimbNode::setTheta(double value){
    theta = value;
}

double ClimbNode::getV(){
    return v;
}

void ClimbNode::setV(double value){
    v = value;
}

double ClimbNode::getNewH(){
    return newH;
}

void ClimbNode::setNewH(double value){
    newH = value;
}

QString ClimbNode::toString(){
    return NodePoint::toString()
        .append("theta = " + QString::number(theta)).append(" ")
        .append("v = " + QString::number(v)).append(" ")
        .append("newH = " + QString::number(newH)).append(" ");
}
