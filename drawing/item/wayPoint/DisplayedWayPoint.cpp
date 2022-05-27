#include "DisplayedWayPoint.h"


DisplayedWayPoint::DisplayedWayPoint(QGraphicsItem *displayedItem,WayPoint *wayPoint,QPointF position)
    : DisplayedItem(displayedItem){

    this->type = ItemType::WAY_POINT_ITEM;
    this->wayPoint = wayPoint;
    this->position = position;
}

DisplayedWayPoint::~DisplayedWayPoint(){

}

void DisplayedWayPoint::createDescription(){
    if(this->text == nullptr){
        QGraphicsTextItem *newText = new QGraphicsTextItem(name);
        newText->setPos(position.x() + 2,position.y() + 2);
        this->text = newText;
    }else{
        text->setPlainText(name);
    }
}

QPointF DisplayedWayPoint::getPosition(){
    return QPointF();
}

void DisplayedWayPoint::setPosition(QPointF value){
    position = value;
}

WayPoint *DisplayedWayPoint::getWayPoint(){
    return wayPoint;
}

void DisplayedWayPoint::setWayPoint(WayPoint *value){
    wayPoint = value;
}
