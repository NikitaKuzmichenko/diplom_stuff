#include "ClicablePlaneScene.h"
#include "QDebug"
#include <drawing/layers/GeographicGridLayer.h>
#include <drawing/layers/GeographicGridLayer.h>
#include <settings/SettingsManager.h>

ClicablePlaneScene::ClicablePlaneScene(QObject *parent) : ClicableScene(parent){}

ClicablePlaneScene::ClicablePlaneScene(SimulationView *view,LayerManager *layerManager)
    : ClicableScene(view,layerManager){}

void ClicablePlaneScene::displayBackgound(){

    GeographicGridLayer *background = new GeographicGridLayer(LayerName::backgroud,false);
    QList<QGraphicsItem *> background_items;
    background->setItemGroupe(createItemGroup(background_items));

    QGraphicsPixmapItem *pixMap = new QGraphicsPixmapItem(QPixmap::fromImage(backgroundImg));
    addItem(pixMap);
    background->addItem(pixMap);
    layerManager->addlayer(LayerName::backgroud,background);

    initGrlidLayer(backgroundImg);
}

void ClicablePlaneScene::updateBackgound(){
    bacgroundlayer->redraw();
}

void ClicablePlaneScene::initVisiblaLayers(){
    QList<QGraphicsItem *> node_items;
    VisibleLayer *nodePointsLayer = new VisibleLayer(LayerName::node_point,true);
    nodePointsLayer->setItemGroupe(createItemGroup(node_items));
    layerManager->addlayer(LayerName::node_point,nodePointsLayer);

    QList<QGraphicsItem *> text_items;
    VisibleLayer *text_layer = new VisibleLayer(LayerName::text,false);
    text_layer->setItemGroupe(createItemGroup(text_items));
    layerManager->addlayer(LayerName::text,text_layer);

    QList<QGraphicsItem *> lines_items;
    VisibleLayer *lines_layer = new VisibleLayer(LayerName::line,true);
    lines_layer->setItemGroupe(createItemGroup(text_items));
    layerManager->addlayer(LayerName::line,lines_layer);

    QList<QGraphicsItem *> height_change_items;
    VisibleLayer *height_change_layer = new VisibleLayer(LayerName::height_chande_point,true);
    height_change_layer->setItemGroupe(createItemGroup(height_change_items));
    layerManager->addlayer(LayerName::height_chande_point,height_change_layer);

    QList<QGraphicsItem *> way_point_items;
    VisibleLayer *way_point_layer = new VisibleLayer(LayerName::way_point,false);
    way_point_layer->setItemGroupe(createItemGroup(way_point_items));
    layerManager->addlayer(LayerName::way_point,way_point_layer);
}

bool ClicablePlaneScene::selectAnyItem(QPointF pos){
    QGraphicsItem *i = itemAt(pos,QTransform());

    for(auto layer : *layerManager->getLayers()){
        if(layer->contain(i)){
            if(view->findNodeByMainItem(i) != nullptr){
                seclectedItem = view->findNodeByMainItem(i);
                itemSelected = true;
                emit itemSelectedEvent(seclectedItem->type,seclectedItem->getId());
                break;
            }
            if(view->findWayPointByMainItem(i) != nullptr){
                seclectedItem = view->findWayPointByMainItem(i);
                itemSelected = true;
                emit itemSelectedEvent(seclectedItem->type,seclectedItem->getId());
                break;
            }

        }
    }

    for(auto line : layerManager->getLayerByName(LayerName::line)->getItemGroupe()->childItems()){
        if(line->contains(pos)){
            seclectedItem = view->findSegmentByMainItem(line);
            itemSelected = true;
            emit itemSelectedEvent(seclectedItem->type,seclectedItem->getId());
            return true;
        }
    }

    return false;
}

void ClicablePlaneScene::initGrlidLayer(QImage img){
    Settings *settings = SettingsManager::getSettings();

    GeographicGridLayer *gridLayer = new GeographicGridLayer(LayerName::grid,false);
    QList<QGraphicsItem *> grid_items;
    gridLayer->setItemGroupe(createItemGroup(grid_items));

    gridLayer->setLinesPerXAxis(settings->lines_in_grid);
    gridLayer->setLinesPerYAxis(settings->lines_in_grid);
    gridLayer->setMaxYValue(view->getMapper()->getElevationMap()->getMaxLatDeg());
    gridLayer->setMinYValue(view->getMapper()->getElevationMap()->getMinLatDeg());
    gridLayer->setMaxXValue(view->getMapper()->getElevationMap()->getMaxLongDeg());
    gridLayer->setMinXValue(view->getMapper()->getElevationMap()->getMinLongDeg());
    gridLayer->setWight(img.width());
    gridLayer->setHieght(img.height());
    gridLayer->setXIndent(30);
    gridLayer->setYIndent(30);
    gridLayer->setPen(SettingsManager::getGrid_pen());
    gridLayer->draw();

    layerManager->addlayer(LayerName::grid,gridLayer);
    bacgroundlayer = gridLayer;
}

//===================================================================================================================

bool ClicablePlaneScene::selectItem(QPointF pos){
    QGraphicsItem *i = itemAt(pos,QTransform());

    for(auto layer : *layerManager->getLayers()){
        if(layer->getChangeable() && layer->contain(i)){
            movedItem = view->findNodeByMainItem(i);
            itemSelected = true;
            break;
        }
    }
    return true;
}

bool ClicablePlaneScene::releaseItem(QPointF pos){
    if(movedItem != nullptr){
        DisplayedNode *selectedNode = (DisplayedNode*)movedItem;
        view->updateNode(selectedNode,pos);
        update(sceneRect());
        itemSelected = false;
    }
    return true;
}

bool ClicablePlaneScene::moveItem(QPointF pos){
    if(movedItem != nullptr){
        DisplayedNode *selectedNode = (DisplayedNode*)movedItem;
        view->updateNode(selectedNode,pos);
        update(sceneRect());
    }
    return true;
}

bool ClicablePlaneScene::createItem(QPointF pos, NP::NodePointType type){
    view->createNewTurnPoint(pos,type);
    return true;
}

bool ClicablePlaneScene::createItemOnSegment(QPointF pos, NP::NodePointType type){
    for(auto line : layerManager->getLayerByName(LayerName::line)->getItemGroupe()->childItems()){
        if(line->contains(pos)){
            DisplayedSegment * selectedLine = view->findSegmentByMainItem(line);
            if(selectedLine != nullptr){
               view->addNewNodeToSegment(pos,type,selectedLine->getId());
            }
        }
    }
    return true;
}

bool ClicablePlaneScene::deleteItem(QPointF pos){
    QGraphicsItem *i = itemAt(pos,QTransform());
    for(auto layer : *layerManager->getLayers()){
        if(layer->getChangeable() && layer->contain(i)){
            view->deleteNode(view->findNodeByMainItem(i));
            break;
        }
    }
    update(sceneRect());
    return true;
}

