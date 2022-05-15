#include "ClicableScene.h"
#include <QGraphicsSceneMouseEvent>

DisplayedItem *ClicableScene::seclectedItem = nullptr;
bool ClicableScene::itemSelected = false;
Actions::ActionType ClicableScene::action = Actions::noAction;

ClicableScene::ClicableScene(QObject *parent): QGraphicsScene(parent){}

ClicableScene::ClicableScene(SimulationViewTest *view, LayerManager *layerManager): QGraphicsScene(nullptr){
    this->view = view;
    this->layerManager = layerManager;
}

QPointF ClicableScene::getMousePos(){
    return mousePos;
}

void ClicableScene::setMousePos(QPointF &value){
    mousePos = value;
}

SimulationViewTest *ClicableScene::getView(){
    return view;
}

void ClicableScene::setView(SimulationViewTest *value){
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

LayerManager *ClicableScene::getLayerManager()
{
    return layerManager;
}

void ClicableScene::setLayerManager(LayerManager *value)
{
    layerManager = value;
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
            case Actions::addItemToSegment :
             createItemOnSegment(point,NP::TURN_NODE);
             break;
            case Actions::addItem :
             createItem(point,NP::TURN_NODE);
             break;
            case Actions::removeItem :
             deleteItem(point);
             break;
            case Actions::moveItem :
             selectItem(point);
             break;
            default: break;
         }
    }
}

void ClicableScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(contain(event->scenePos()) && itemSelected && action == Actions::moveItem){
        moveItem(event->scenePos());
    }
}

void ClicableScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(itemSelected && contain(event->scenePos()) && action == Actions::moveItem){
        releaseItem(event->scenePos());
    }
}
