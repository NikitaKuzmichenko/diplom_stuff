#include "ClickablePlane.h"

#include <QCursor>
#include <QGraphicsPixmapItem>
#include <QThread>
#include <drawing/item/point/DisplayedNodePoint.h>

const int ClickablePlane::roundSceneIndent;

ClickablePlane::ClickablePlane(QObject *parent) : QGraphicsScene(parent){}

ClickablePlane::ClickablePlane(LayerManager *layerManager, SimulationView *view) : QGraphicsScene(0){
    this->layerManager = layerManager;
    this->view = view;
}

void ClickablePlane::mousePressEvent(QGraphicsSceneMouseEvent *e){

    QPointF pt = e->scenePos();

    if(contain(pt) && e->button() == Qt::MouseButton::LeftButton){
        switch (action) {

            case Actions::ActionType::addItemToLine : {
                 QPointF pt = e->scenePos();
                 for(auto line :layerManager->getLayerByName(LayerName::lines)->getItemGroupe()->childItems()){
                     if(line->contains(pt)){
                         DisplayedSegment * selectedLine = view->findLineByMainItem(line);
                         if(selectedLine != nullptr){
                            view->addPointToLine(selectedLine,pt,NodePointType::TAKEOFF_NODE);

                         }
                     }
                 }
                break;
            }

            case Actions::ActionType::addItem : {
                view->addPoint(pt,NodePointType::TAKEOFF_NODE);
                view->createLineWithLastPoint();
                break;
            }

            case Actions::ActionType::removeItem :{
                QGraphicsItem *i = itemAt(pt,QTransform());

                for(auto layer : *layerManager->getLayers())
                    if(layer->getChangeable() && layer->contain(i)){
                        DisplayedNodePoint *namedItem = view->findPointByMainItem(i);
                        if(namedItem != nullptr){
                           view->deletePoint(namedItem);
                           break;
                        }
                    }
                update(sceneRect());
                break;
            }

            case Actions::ActionType::moveItem :{
                QGraphicsItem *i = itemAt(pt,QTransform());
                for(auto layer : *layerManager->getLayers())
                    if(layer->getChangeable() && layer->contain(i)){
                        selectedItem = view->findPointByMainItem(i);
                        itemSelected = true;
                        mousePos = e->scenePos();
                        break;
                    }
                update(sceneRect());
                break;
            }

            default: break;
        }
    }
}

void ClickablePlane::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
     QPointF pt = event->scenePos();
     if(this->sceneRect().contains(pt) && contain(pt) && itemSelected){
        if(this->action == Actions::ActionType::moveItem){
            selectedItem->moveBy(pt.x() - mousePos.x(),pt.y() - mousePos.y());
            view->updateRelatedLines(selectedItem);
            mousePos = event->scenePos();
        }
     }
}

void ClickablePlane::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(itemSelected && contain(event->scenePos()) && action == Actions::ActionType::moveItem){
           view->evaluatePoint(event->scenePos(),selectedItem);
           selectedItem->createDescription();
           view->updateRelatedLines(selectedItem);
           update(sceneRect());
           itemSelected = false;
    }
}


bool ClickablePlane::contain(QPointF point){
    if(sceneRect().x() + roundSceneIndent > point.x() || sceneRect().width() - 2 * roundSceneIndent < point.x()) return false;
    if(sceneRect().y() + roundSceneIndent > point.y() || sceneRect().height() - 2 * roundSceneIndent < point.y()) return false;
    return true;
}

bool ClickablePlane::getItemSelected()
{
    return itemSelected;
}

void ClickablePlane::setItemSelected(bool value)
{
    itemSelected = value;
}

Actions::ActionType ClickablePlane::getAction(){
    return action;
}

void ClickablePlane::setAction(Actions::ActionType value){
    action = value;
}
