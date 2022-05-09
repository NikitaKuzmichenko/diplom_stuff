#include "DisplayedNodePoint.h"


DisplayedNodePoint::DisplayedNodePoint(QGraphicsItem *displayedItem,NodePoint *node,QPointF position) : DisplayedItem(displayedItem){
    this->node = node;
    this->position = position;
}

DisplayedNodePoint::~DisplayedNodePoint(){
    delete node;
}

void DisplayedNodePoint::moveBy(double dx, double dy){

    mainItem->moveBy(dx,dy);
    text->moveBy(dx,dy);

    position.setX(position.x()+dx);
    position.setY(position.y()+dy);

}

void DisplayedNodePoint::createDescription(){

    QString result;
    result.append(name);
    result.append("->");
    result.append(" H=");
    result.append(QString::number(node->getPoint()->getHight()));
    result.append(" Long=");
    result.append(QString::number(node->getPoint()->getLongitude()));
    result.append(" Lat=");
    result.append(QString::number(node->getPoint()->getLatitude()));

    if(this->text == nullptr){
        QGraphicsTextItem *newText = new QGraphicsTextItem(result);
        newText->setPos(position.x() + 2,position.y() + 2);
        this->text = newText;
    }else{
        text->setPlainText(result);
    }
}

NodePoint *DisplayedNodePoint::getNode(){
    return node;
}

void DisplayedNodePoint::setNode(NodePoint *value){
    node = value;
}

QPointF DisplayedNodePoint::getPosition(){
    return position;
}

void DisplayedNodePoint::setPosition(QPointF value){
    position = value;
}
