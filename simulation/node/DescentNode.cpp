#include "DescentNode.h"

DescentNode::DescentNode() : NodePoint(){
    type = NP::DESCENT_NODE;
}

DescentNode::DescentNode(PhysicalPoint *point) : NodePoint(point){
    type = NP::DESCENT_NODE;
}

DescentNode::DescentNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height) {
    type = NP::DESCENT_NODE;
}

DescentNode::DescentNode(PhysicalPoint *point, double theta, double v, double newH) : NodePoint(point){
    type = NP::DESCENT_NODE;
    this->theta = theta;
    this->v = v;
    this->newH = newH;
}

DescentNode::DescentNode(double longitude, double latitude, double height, double theta, double v, double newH) : NodePoint(longitude,latitude,height){
    type = NP::DESCENT_NODE;
    this->theta = theta;
    this->v = v;
    this->newH = newH;
}

double DescentNode::getTheta(){
    return theta;
}

void DescentNode::setTheta(double value){
    theta = value;
}

double DescentNode::getV(){
    return v;
}

void DescentNode::setV(double value){
    v = value;
}

double DescentNode::getNewH(){
    return newH;
}

void DescentNode::setNewH(double value){
    newH = value;
}

QString DescentNode::toString(){
    return NodePoint::toString()
        .append("theta = " + QString::number(theta)).append(" ")
        .append("v = " + QString::number(v)).append(" ")
        .append("newH = " + QString::number(newH)).append(" ");
}
