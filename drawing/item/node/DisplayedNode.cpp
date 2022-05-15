#include "DisplayedNode.h"
#include <utils/GeodesicUtils.h>

DisplayedNode::DisplayedNode(QGraphicsItem *displayedItem,NodePoint *node,QPointF position)
    : DisplayedItem(displayedItem){

    this->type = ItemType::NodeItem;
    this->node = node;
    this->position = position;
}

DisplayedNode::~DisplayedNode(){
}

void DisplayedNode::moveBy(double dx, double dy){
    mainItem->moveBy(dx,dy);
    text->moveBy(dx,dy);

    position.setX(position.x()+dx);
    position.setY(position.y()+dy);
}

void DisplayedNode::createDescription(){

    QString result;
    result.append(name);
    result.append("(");

    result.append(QString::number(GeodesicUtils::toDeg(node->getPoint()->getLongitude())));
    result.append(",");
    result.append(QString::number(GeodesicUtils::toDeg(node->getPoint()->getLatitude())));
    result.append(",");
    result.append(QString::number(node->getPoint()->getHight()));
    result.append(")");

    if(this->text == nullptr){
        QGraphicsTextItem *newText = new QGraphicsTextItem(result);
        newText->setPos(position.x() + 2,position.y() + 2);
        this->text = newText;
    }else{
        text->setPlainText(result);
    }
}

NodePoint *DisplayedNode::getNode(){
    return node;
}

void DisplayedNode::setNode(NodePoint *value){
    node = value;
}

QPointF DisplayedNode::getPosition(){
    return position;
}

void DisplayedNode::setPosition(QPointF value){
    position = value;
}
