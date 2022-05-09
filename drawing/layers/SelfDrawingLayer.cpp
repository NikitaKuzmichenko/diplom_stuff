#include "SelfDrawingLayer.h"

SelfDrawingLayer::SelfDrawingLayer(): VisibleLayer(){}

SelfDrawingLayer::SelfDrawingLayer(int zOrder) : VisibleLayer(zOrder){}

SelfDrawingLayer::SelfDrawingLayer(int zOrder, bool changeble) : VisibleLayer(zOrder,changeble){}

SelfDrawingLayer::SelfDrawingLayer(double wight, double hieght, double xIndent, double yIndent) : VisibleLayer() {
    zOrder = 0;
    this->changeable = false;

    this->wight = wight;
    this->hieght = hieght;
    this->xIndent = xIndent;
    this->yIndent = yIndent;
}

double SelfDrawingLayer::getXIndent(){
    return xIndent;
}

void SelfDrawingLayer::setXIndent(double value){
    xIndent = value;
}

double SelfDrawingLayer::getYIndent(){
    return yIndent;
}

void SelfDrawingLayer::setYIndent(double value){
    yIndent = value;
}

double SelfDrawingLayer::getHieght(){
    return hieght;
}

void SelfDrawingLayer::setHieght(double value){
    hieght = value;
}

double SelfDrawingLayer::getWight(){
    return wight;
}

void SelfDrawingLayer::setWight(double value){
    wight = value;
}

int SelfDrawingLayer::getLinesPerYAxis(){
    return linesPerYAxis;
}

void SelfDrawingLayer::setLinesPerYAxis(int value){
    linesPerYAxis = value;
}

int SelfDrawingLayer::getLinesPerXAxis(){
    return linesPerXAxis;
}

void SelfDrawingLayer::setLinesPerXAxis(int value){
    linesPerXAxis = value;
}

QPen SelfDrawingLayer::getPen(){
    return pen;
}

void SelfDrawingLayer::setPen(QPen value){
    pen = value;
}

double SelfDrawingLayer::getMinYValue(){
    return minYValue;
}

void SelfDrawingLayer::setMinYValue(double value){
    minYValue = value;
}

double SelfDrawingLayer::getMaxYValue(){
    return maxYValue;
}

void SelfDrawingLayer::setMaxYValue(double value){
    maxYValue = value;
}

double SelfDrawingLayer::getMinXValue(){
    return minXValue;
}

void SelfDrawingLayer::setMinXValue(double value){
    minXValue = value;
}

double SelfDrawingLayer::getMaxXValue(){
    return maxXValue;
}

void SelfDrawingLayer::setMaxXValue(double value){
    maxXValue = value;
}

void SelfDrawingLayer::redraw(){
    clear();
    draw();
}
