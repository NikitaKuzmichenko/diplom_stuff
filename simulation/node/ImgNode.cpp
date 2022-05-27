#include "ImgNode.h"

ImgNode::ImgNode() : NodePoint(){
    path = QString();
    type = NP::IMG_NODE;
}

ImgNode::ImgNode(PhysicalPoint *point) : NodePoint(point){
    path = QString();
    type = NP::IMG_NODE;
}

ImgNode::ImgNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height) {
    path = QString();
    type = NP::IMG_NODE;
}

ImgNode::ImgNode(PhysicalPoint *point, double v, double azim, double len, double width,QString path) : NodePoint(point){
    type = NP::IMG_NODE;
    this->v = v;
    this->azim = azim;
    this->len = len;
    this->width = width;
    this->path = path;
}

ImgNode::ImgNode(double longitude, double latitude, double height, double v, double azim, double len, double width,QString path) : NodePoint(longitude,latitude,height){
    type = NP::IMG_NODE;
    this->v = v;
    this->azim = azim;
    this->len = len;
    this->width = width;
    this->path = path;
}

double ImgNode::getV(){
    return v;
}

void ImgNode::setV(double value){
    v = value;
}

double ImgNode::getAzim(){
    return azim;
}

void ImgNode::setAzim(double value)
{
    azim = value;
}

double ImgNode::getLen(){
    return len;
}

void ImgNode::setLen(double value){
    len = value;
}

double ImgNode::getWidth(){
    return width;
}

void ImgNode::setWidth(double value){
    width = value;
}

QString ImgNode::getPath(){
    return path;
}

void ImgNode::setPath(QString value){
    path = value;
}

QString ImgNode::toString(){
    return NodePoint::toString()
        .append("V = " + QString::number(v)).append(" ")
        .append("azim = " + QString::number(azim)).append(" ")
        .append("len = " + QString::number(len)).append(" ")
        .append("width = " + QString::number(width)).append(" ")
        .append("path = " + path).append(" ");
}
