#include "DisplayedNode.h"
#include <utils/GeodesicUtils.h>
#include <QMetaEnum>

DisplayedNode::DisplayedNode(QGraphicsItem *displayedItem,NodePoint *node,QPointF position)
    : DisplayedItem(displayedItem){

    this->type = ItemType::NODE_ITEM;
    this->node = node;
    this->position = position;
}

DisplayedNode::~DisplayedNode(){}

void DisplayedNode::moveBy(double dx, double dy){
    mainItem->moveBy(dx,dy);
    text->moveBy(dx,dy);

    position.setX(position.x()+dx);
    position.setY(position.y()+dy);
}

void DisplayedNode::moveTo(QPointF position){
    double dx = position.x() - this->position.x();
    double dy = position.y() - this->position.y();
    moveBy(dx,dy);
    this->position = position;
}

void DisplayedNode::createDescription(){
    QString result;
    QString name = QString(QMetaEnum::fromType<NP::NodePointType>().valueToKey((node->type)));
    name=name.left(name.lastIndexOf('_'));
    result.append(name);
    result.append("(");
    result.append(QString::number(GeodesicUtils::toDeg(node->getPoint()->getLongitude()),'f',2));
    result.append(",");
    result.append(QString::number(GeodesicUtils::toDeg(node->getPoint()->getLatitude()),'f',2));
    result.append(",");
    result.append(QString::number(node->getPoint()->getHight(),'f',2));
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

QString DisplayedNode::formatName(){

}
