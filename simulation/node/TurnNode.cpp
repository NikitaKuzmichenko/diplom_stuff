#include "TurnNode.h"

TurnNode::TurnNode() : NodePoint(){
    type = TURN_NODE;
}

TurnNode::TurnNode(PhysicalPoint *point) : NodePoint(point){
    type = TURN_NODE;
}

TurnNode::TurnNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height) {
    type = TURN_NODE;
}

TurnNode::TurnNode(PhysicalPoint *point, double r, double v, double psi) : NodePoint(point){
    type = TURN_NODE;
    this->v = v;
    this->r = r;
    this->psi = psi;;
}

TurnNode::TurnNode(double longitude, double latitude, double height, double r, double v, double psi) : NodePoint(longitude,latitude,height){
    type = TURN_NODE;
    this->v = v;
    this->r = r;
    this->psi = psi;
}

double TurnNode::getR() {
    return r;
}

void TurnNode::setR(double value){
    r = value;
}

double TurnNode::getV(){
    return v;
}

void TurnNode::setV(double value){
    v = value;
}

double TurnNode::getPsi(){
    return psi;
}

void TurnNode::setPsi(double value){
    psi = value;
}
