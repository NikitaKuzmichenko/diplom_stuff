#include "DisplayedSegment.h"

DisplayedSegment::DisplayedSegment(DisplayedNode *startPoint, DisplayedNode *endPoint,QPen *pen){

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

    this->type = ItemType::SEGMENT_ITEM;
}

DisplayedSegment::~DisplayedSegment(){}

void DisplayedSegment::updateCoordinates(){
    ((QGraphicsLineItem*)mainItem)->setLine(startPoint->getPosition().x(),startPoint->getPosition().y(),
                                    endPoint->getPosition().x(),endPoint->getPosition().y());

    center.setX((startPoint->getPosition().x() + endPoint->getPosition().x())/2);
    center.setY((startPoint->getPosition().y() + endPoint->getPosition().y())/2);

}

DisplayedNode *DisplayedSegment::getStartPoint(){
    return startPoint;
}

void DisplayedSegment::setStartPoint(DisplayedNode *value){
    startPoint = value;
}

DisplayedNode *DisplayedSegment::getEndPoint(){
    return endPoint;
}

void DisplayedSegment::setEndPoint(DisplayedNode *value){
    endPoint = value;
}

QPointF DisplayedSegment::getCenter(){
    return center;
}

void DisplayedSegment::setCenter(QPointF value){
    center = value;
}


Segment *DisplayedSegment::getRealSegment(){
    return realSegment;
}

void DisplayedSegment::setRealSegment(Segment *value){
    realSegment = value;
}
