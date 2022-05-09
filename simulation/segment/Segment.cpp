#include "Segment.h"

Segment::Segment(){}

Segment::Segment(NodePoint *startPoint, NodePoint *endPoint){
    this->startPoint = startPoint;
    this->endPoint = endPoint;
}

NodePoint *Segment::getStartPoint() {
    return startPoint;
}

void Segment::setStartPoint(NodePoint *value){
    startPoint = value;
}

NodePoint *Segment::getEndPoint(){
    return endPoint;
}

void Segment::setEndPoint(NodePoint *value){
    endPoint = value;
}

long Segment::getId(){
    return id;
}

void Segment::setId(long value){
    id = value;
}
