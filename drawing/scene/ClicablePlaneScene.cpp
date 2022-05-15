#include "ClicablePlaneScene.h"
#include "QDebug"

ClicablePlaneScene::ClicablePlaneScene(QObject *parent) : ClicableScene(parent){}

ClicablePlaneScene::ClicablePlaneScene(SimulationViewTest *view,LayerManager *layerManager)
    : ClicableScene(view,layerManager){}

bool ClicablePlaneScene::selectItem(QPointF pos){
    QGraphicsItem *i = itemAt(pos,QTransform());

    for(auto layer : *layerManager->getLayers()){
        if(layer->getChangeable() && layer->contain(i)){
            seclectedItem = view->findPointByMainItem(i);
            itemSelected = true;
            mousePos = pos;
            break;
        }
    }
    update(sceneRect());
    return true;
}

bool ClicablePlaneScene::releaseItem(QPointF pos){
    if(seclectedItem != nullptr){

        DisplayedNode *selectedNode = (DisplayedNode*)seclectedItem;

        view->evaluatePoint(pos,selectedNode);
        selectedNode->createDescription();
        view->updateRelatedLines(selectedNode);
        update(sceneRect());

        itemSelected = false;
    }
    return true;
}

bool ClicablePlaneScene::moveItem(QPointF pos){
    if(seclectedItem != nullptr){

        DisplayedNode *selectedNode = (DisplayedNode*)seclectedItem;

        selectedNode->moveBy(pos.x() - mousePos.x(),pos.y() - mousePos.y());
        view->updateRelatedLines(selectedNode);
        mousePos = pos;
    }
    return true;
}

bool ClicablePlaneScene::createItem(QPointF pos, NP::NodePointType type){
    view->addPoint(pos,type);
    view->createLineWithLastPoint();
    return true;
}

bool ClicablePlaneScene::createItemOnSegment(QPointF pos, NP::NodePointType type){
    for(auto line :layerManager->getLayerByName(LayerName::line)->getItemGroupe()->childItems()){
        if(line->contains(pos)){
            DisplayedSegment * selectedLine = view->findLineByMainItem(line);
            if(selectedLine != nullptr){
               view->addPointToLine(selectedLine,pos,type);

            }
        }
    }
    return true;
}

bool ClicablePlaneScene::deleteItem(QPointF pos){
    QGraphicsItem *i = itemAt(pos,QTransform());

    for(auto layer : *layerManager->getLayers()){
        if(layer->getChangeable() && layer->contain(i)){
            DisplayedNode *namedItem = view->findPointByMainItem(i);
            if(namedItem != nullptr){
               view->deletePoint(namedItem);
               break;
            }
        }
    }
    update(sceneRect());
    return true;
}
