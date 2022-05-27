#include "ClicableScene.h"
#include <QGraphicsSceneMouseEvent>

DisplayedItem *ClicableScene::seclectedItem = nullptr;
DisplayedItem *ClicableScene::movedItem = nullptr;
bool ClicableScene::itemSelected = false;
Actions::ActionType ClicableScene::action = Actions::noAction;

ClicableScene::ClicableScene(QObject *parent): QGraphicsScene(parent){}

ClicableScene::ClicableScene(SimulationView *view, LayerManager *layerManager): QGraphicsScene(nullptr){
    this->view = view;
    this->layerManager = layerManager;
}

QPointF ClicableScene::getMousePos(){
    return mousePos;
}

void ClicableScene::setMousePos(QPointF &value){
    mousePos = value;
}

SimulationView *ClicableScene::getView(){
    return view;
}

void ClicableScene::setView(SimulationView *value){
    view = value;
}

void ClicableScene::setRightAdjustmet(double value){
    rightAdjustmet = value;
}

void ClicableScene::setLetfAdjustmet(double value){
    letfAdjustmet = value;
}

void ClicableScene::setBotAdjustmet(double value){
    botAdjustmet = value;
}

void ClicableScene::setTopAdjustmet(double value){
    topAdjustmet = value;
}

LayerManager *ClicableScene::getLayerManager(){
    return layerManager;
}

void ClicableScene::setLayerManager(LayerManager *value){
    layerManager = value;
}

QImage ClicableScene::getBackground(){
    return backgroundImg;
}

void ClicableScene::setBackground(QImage value){
    backgroundImg = value;
}

SelfDrawingLayer *ClicableScene::getBacgroundlayer(){
    return bacgroundlayer;
}

void ClicableScene::setBacgroundlayer(SelfDrawingLayer *value){
    bacgroundlayer = value;
}

bool ClicableScene::contain(QPointF mousePos){
    if(sceneRect().x() + letfAdjustmet > mousePos.x() || sceneRect().width() - rightAdjustmet < mousePos.x()) return false;
    if(sceneRect().y() + topAdjustmet > mousePos.y() || sceneRect().height() - botAdjustmet < mousePos.y()) return false;
    return true;
}

bool ClicableScene::contain(){
    return  contain(mousePos);
}

void ClicableScene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QPointF point = event->scenePos();
    if(contain(point) && event->button() == Qt::MouseButton::LeftButton){
         switch (action){
            case Actions::addNodeToSegment :
             createItemOnSegment(point,NP::UNDEFINED_NODE);
             break;
            case Actions::addTurnNode :
             createItem(point,NP::TURN_NODE);
             break;
            case Actions::removeNode :
             deleteItem(point);
             break;
            case Actions::moveNode :
             selectItem(point);
             break;
            case Actions::selectItem :
              selectAnyItem(point);
              break;
            default: break;
         }
    }
}

void ClicableScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(contain(event->scenePos()) && itemSelected && action == Actions::moveNode){
        moveItem(event->scenePos());
    }
}

void ClicableScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(itemSelected && contain(event->scenePos()) && action == Actions::moveNode){
        releaseItem(event->scenePos());
    }
}
