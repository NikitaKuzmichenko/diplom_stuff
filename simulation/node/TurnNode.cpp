#include "TurnNode.h"
#include <math.h>

#define G 9.80665

TurnNode::TurnNode() : NodePoint(){
    type = NP::TURN_NODE;
}

TurnNode::TurnNode(PhysicalPoint *point) : NodePoint(point){
    type = NP::TURN_NODE;
}

TurnNode::TurnNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height) {
    type = NP::TURN_NODE;
}

TurnNode::TurnNode(PhysicalPoint *point, double r, double v, double psi) : NodePoint(point){
    type = NP::TURN_NODE;
    this->v = v;
    this->r = r;
    this->psi = psi;;
}

TurnNode::TurnNode(double longitude, double latitude, double height, double r, double v, double psi) : NodePoint(longitude,latitude,height){
    type = NP::TURN_NODE;
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

void TurnNode::calcualteTurnRadius(){
    if(std::isnan(v) != 0 || std::isnan(psi) != 0){
        r = NAN;
        return;
    }
    r = v*v/(G * tan(psi));
}

QString TurnNode::toString(){
    return NodePoint::toString()
        .append("psi = " + QString::number(psi)).append(" ")
        .append("v = " + QString::number(v)).append(" ")
        .append("r = " + QString::number(r)).append(" ");
}
