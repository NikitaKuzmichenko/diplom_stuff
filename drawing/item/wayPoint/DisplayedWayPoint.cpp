#include "DisplayedWayPoint.h"


DisplayedWayPoint::DisplayedWayPoint(QGraphicsItem *displayedItem,WayPoint *wayPoint,QPointF position)
    : DisplayedItem(displayedItem){

    this->type = ItemType::WayPointItem;
    this->wayPoint = wayPoint;
    this->position = position;
}

void DisplayedWayPoint::createDescription(){

}

QPointF DisplayedWayPoint::getPosition(){
    return QPointF();
}

void DisplayedWayPoint::setPosition(QPointF value){

}

WayPoint *DisplayedWayPoint::getWayPoint(){
    return wayPoint;
}

void DisplayedWayPoint::setWayPoint(WayPoint *value){
    wayPoint = value;
}
