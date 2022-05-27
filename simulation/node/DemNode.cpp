#include "DemNode.h"

DemNode::DemNode() : NodePoint(){
    path = QString();
    type = NP::DEM_NODE;
}

DemNode::DemNode(PhysicalPoint *point) : NodePoint(point){
    path = QString();
    type = NP::DEM_NODE;
}

DemNode::DemNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height) {
    path = QString();
    type = NP::DEM_NODE;
}

DemNode::DemNode(PhysicalPoint *point, double v, double azim, double len, double width,QString path) : NodePoint(point){
    type = NP::DEM_NODE;
    this->v = v;
    this->azim = azim;
    this->len = len;
    this->width = width;
    this->path = path;
}

DemNode::DemNode(double longitude, double latitude, double height, double v, double azim, double len, double width,QString path) : NodePoint(longitude,latitude,height){
    type = NP::DEM_NODE;
    this->v = v;
    this->azim = azim;
    this->len = len;
    this->width = width;
    this->path = path;
}

double DemNode::getV(){
    return v;
}

void DemNode::setV(double value)
{
    v = value;
}

double DemNode::getAzim(){
    return azim;
}

void DemNode::setAzim(double value){
    azim = value;
}

double DemNode::getLen(){
    return len;
}

void DemNode::setLen(double value){
    len = value;
}

double DemNode::getWidth(){
    return width;
}

void DemNode::setWidth(double value){
    width = value;
}

QString DemNode::getPath(){
    return path;
}

void DemNode::setPath(QString value){
    path = value;
}

QString DemNode::toString(){
    return NodePoint::toString()
        .append("V = " + QString::number(v)).append(" ")
        .append("azim = " + QString::number(azim)).append(" ")
        .append("len = " + QString::number(len)).append(" ")
        .append("width = " + QString::number(width)).append(" ")
        .append("path = " + path).append(" ");
}
