#include "DisplayedItem.h"

DisplayedItem::DisplayedItem(){}

DisplayedItem::DisplayedItem(QGraphicsItem *item){
    this->mainItem = item;
}

DisplayedItem::~DisplayedItem(){
    delete mainItem;
    delete text;
}

QGraphicsItem *DisplayedItem::getMainItem() {
    return mainItem;
}

void DisplayedItem::setMainItem(QGraphicsItem *value){
    mainItem = value;
}

QGraphicsTextItem *DisplayedItem::getText() {
    return text;
}

void DisplayedItem::setText(QGraphicsTextItem *value){
    text = value;
}

QString DisplayedItem::getName() {
    return name;
}

void DisplayedItem::setName(QString &value){
    name = value;
}
