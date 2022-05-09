#include "VisibleLayer.h"
#include <QGraphicsScene>

VisibleLayer::VisibleLayer(){}

VisibleLayer::VisibleLayer(int zOrder){
    this->zOrder = zOrder;
}

VisibleLayer::VisibleLayer(int zOrder, bool changeable){
     this->zOrder = zOrder;
     this->changeable = changeable;
}

VisibleLayer::~VisibleLayer(){
    this->itemGroupe->~QGraphicsItemGroup();
}

void VisibleLayer::addItem(QGraphicsItem *item){
    this->itemGroupe->addToGroup(item);
}

bool VisibleLayer::contain(QGraphicsItem *item){
    return itemGroupe->childItems().contains(item);
}

void VisibleLayer::clear(){
    QList<QGraphicsItem *> items = itemGroupe->childItems();
    for(int i=0;i<items.size();i++){
        delete items.at(i);
    }
}

int VisibleLayer::getZOrder(){
    return zOrder;
}

void VisibleLayer::setZOrder(int value){
    zOrder = value;
}

bool VisibleLayer::getChangeable(){
    return changeable;
}

void VisibleLayer::setChangeable(bool value){
    changeable = value;
}

QGraphicsItemGroup *VisibleLayer::getItemGroupe(){
    return this->itemGroupe;
}

void VisibleLayer::setItemGroupe(QGraphicsItemGroup *value){
    value->setZValue(zOrder);
    this->itemGroupe = value;
}

void VisibleLayer::hideGroupe(){
    this->itemGroupe->hide();
}

void VisibleLayer::displayGrouope(){
    this->itemGroupe->show();
}
