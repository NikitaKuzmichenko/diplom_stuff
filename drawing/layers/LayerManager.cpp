#include "LayerManager.h"

LayerManager::LayerManager(){
    layers = new QMap<LayerName,VisibleLayer*>;
}

LayerManager::~LayerManager(){
    delete layers;
}

void LayerManager::addlayer(LayerName name, VisibleLayer *layer){
    layers->insert(name,layer);
}

void LayerManager::removeLayer(LayerName name){
     layers->remove(name);
}

VisibleLayer *LayerManager::getLayerByName(LayerName name){
    return layers->find(name).value();
}

void LayerManager::addToLayer(LayerName name,QGraphicsItem *item){
    getLayerByName(name)->addItem(item);
}

void LayerManager::removeFromLayer(LayerName name,QGraphicsItem *item){
    getLayerByName(name)->contain(item);
}

void LayerManager::addToFirstLayer(QGraphicsItem *item){
    layers->first()->addItem(item);
}

void LayerManager::removeFromFirstLayer(QGraphicsItem *item){
    layers->first()->contain(item);
}

QMap<LayerName, VisibleLayer *> *LayerManager::getLayers(){
    return layers;
}

void LayerManager::setLayers(QMap<LayerName, VisibleLayer *> *value){
    layers = value;
}
