#include "DisplayedSegment.h"

DisplayedSegment::DisplayedSegment(DisplayedNodePoint *startPoint, DisplayedNodePoint *endPoint,QPen *pen){

    QGraphicsLineItem * line = new QGraphicsLineItem(startPoint->getPosition().x(),startPoint->getPosition().y(),
                                     endPoint->getPosition().x(),endPoint->getPosition().y());
    line->setPen(*pen);
    this->mainItem = line;
    name = startPoint->getName() + "-" + endPoint->getName();

    this->startPoint = startPoint;
    this->endPoint = endPoint;
    this->center = QPointF(
                (startPoint->getPosition().x() + endPoint->getPosition().x())/2,
                (startPoint->getPosition().y() + endPoint->getPosition().y())/2);
}

DisplayedSegment::~DisplayedSegment(){
    delete realSegment;
}

void DisplayedSegment::updateCoordinates(){
    ((QGraphicsLineItem*)mainItem)->setLine(startPoint->getPosition().x(),startPoint->getPosition().y(),
                                    endPoint->getPosition().x(),endPoint->getPosition().y());

    center.setX((startPoint->getPosition().x() + endPoint->getPosition().x())/2);
    center.setY((startPoint->getPosition().y() + endPoint->getPosition().y())/2);

}

DisplayedNodePoint *DisplayedSegment::getStartPoint(){
    return startPoint;
}

void DisplayedSegment::setStartPoint(DisplayedNodePoint *value){
    startPoint = value;
}

DisplayedNodePoint *DisplayedSegment::getEndPoint(){
    return endPoint;
}

void DisplayedSegment::setEndPoint(DisplayedNodePoint *value){
    endPoint = value;
}

QPointF DisplayedSegment::getCenter(){
    return center;
}

void DisplayedSegment::setCenter(QPointF value){
    center = value;
}

Segment *DisplayedSegment::parseRealRegment(){
    Segment *segment = new Segment(startPoint->getNode(),endPoint->getNode());
    this->realSegment = segment;
    return segment;
}

Segment *DisplayedSegment::getRealSegment(){
    return realSegment;
}

void DisplayedSegment::setRealSegment(Segment *value){
    realSegment = value;
}
