#include "SimulationView.h"

SimulationView::SimulationView(Simulation *simulation, LayerManager *layerManager, ViewMapper *mapper){
    this->simulation = simulation;
    this->mapper = mapper;
    mapper->calculateUnitPerPixeRatio();
    this->layerManager = layerManager;

    nodes = new QVector<DisplayedNode *>;
    segments = new QVector<DisplayedSegment *>;
    wayPoints = new QVector<DisplayedWayPoint *>;
}

SimulationView::~SimulationView(){
    delete [] nodes;
    delete [] segments;
    delete [] wayPoints;
    delete mapper;
}

DisplayedNode *SimulationView::createTurnPoint(QPointF pos, NP::NodePointType type){
    return createTurnPoint(pos,type,simulation->getTurnPoints()->length());
}

DisplayedNode *SimulationView::createTurnPoint(QPointF pos, NP::NodePointType type, long positioInList){
    NodePoint *node = simulation->createTurnNode(convertPositionTopoint(pos),type,positioInList);
    return createPoint(node,pos);
}

DisplayedNode *SimulationView::addPointToSegment(QPointF pos, NP::NodePointType type, long segmentId){
    NodePoint *node = simulation->createNodeOnSegment(convertPositionTopoint(pos),type,segmentId);
    return createPoint(node,pos);
}

DisplayedNode *SimulationView::addTurnPointToSegment(QPointF pos, NP::NodePointType type, long segmentId){

}

DisplayedNode *SimulationView::findNodeByMainItem(QGraphicsItem *item){
    for(auto result: *nodes){
        if(result->getMainItem() == item){
            return result;
        }
    }
    return nullptr;
}

DisplayedWayPoint *SimulationView::findWayPointByMainItem(QGraphicsItem *item){
    for(auto result: *wayPoints){
        if(result->getMainItem() == item){
            return result;
        }
    }
    return nullptr;
}

DisplayedSegment *SimulationView::findSegmentByMainItem(QGraphicsItem *item){
    for(auto result: *segments){
        if(result->getMainItem() == item){
            return result;
        }
    }
    return nullptr;
}

void SimulationView::deleteNode(DisplayedNode *nodeItem){
    simulation->removeNode(nodeItem->getNode()->getId());
    nodes->removeOne(nodeItem);
}


DisplayedSegment *SimulationView::createSegment(DisplayedNode *startPoint, DisplayedNode *endPoint){
    return createSegment(startPoint,endPoint,segments->length());
}

DisplayedSegment *SimulationView::createSegment(DisplayedNode *startPoint, DisplayedNode *endPoint, long positioInList){
    DisplayedSegment *segment = segmentCreator->createSegment(startPoint,endPoint);
    layerManager->getLayerByName(LayerName::line)->addItem(segment->getMainItem());

    simulation->insertSegmentToEnd(segment->getRealSegment());
    segments->insert(positioInList,segment);

    return segment;
}

DisplayedNode *SimulationView::createPoint(NodePoint *realPoint){
    return createPoint(realPoint,getPositionFromPoint(realPoint->getPoint()));
}

DisplayedNode *SimulationView::createPoint(NodePoint *realPoint, QPointF pos){
    DisplayedNode *displayedNode = nodeCreator->ceratePoint(realPoint,pos);
    displayedNode->createDescription();
    nodes->append(displayedNode);

    layerManager->getLayerByName(LayerName::node_point)->addItem(displayedNode->getMainItem());
    layerManager->getLayerByName(LayerName::text)->addItem(displayedNode->getText());

    return displayedNode;
}

DisplayedWayPoint *SimulationView::createWayPoint(WayPoint *realPoint){
    DisplayedWayPoint *displayedWayPoint = wayPointCreator->ceratePoint(realPoint,getPositionFromPoint(realPoint->point));
    displayedWayPoint->createDescription();
    wayPoints->append(displayedWayPoint);

    // добавлять в нужный слой
    layerManager->getLayerByName(LayerName::node_point)->addItem(displayedWayPoint->getMainItem());
    layerManager->getLayerByName(LayerName::text)->addItem(displayedWayPoint->getText());

    return displayedWayPoint;
}

void SimulationView::updateRelatedSegments(DisplayedNode *point){
    for(auto segment: *segments){
        if(segment->getEndPoint() == point || segment->getStartPoint() == point){
           segment->updateCoordinates();
        }
    }
}

QVector<DisplayedSegment *> SimulationView::getRelatedSegments(DisplayedNode *point){
    QVector<DisplayedSegment *> result;

    for(auto segment: *segments){
        if(segment->getEndPoint() == point || segment->getStartPoint() == point){
             result.push_back(segment);
        }
    }
    return result;
}

//bool SimulationView::updateNode(DisplayedNode *selectedNode,QPointF pos){
//    if(selectedNode->getNode() == nullptr){
//        return false;
//    }

//    selectedNode->getNode()->getPoint()->setLongitude(map->minXValue + map->unitPerPixelX * pos.x());
//    selectedNode->getNode()->getPoint()->setLatitude(map->maxYValue - map->unitPerPixelY * pos.y());
//    //map->getElevationMap()->addHeightToSinglePoint(item->getNode()->getPoint());

//    selectedNode->setPosition(pos);

//    return true;
//}
//PhysicalPoint *SimulationView::convertPositionTopoint(QPointF pos){
//    PhysicalPoint *result = new PhysicalPoint();
//    result->setLongitude(mapper->minXValue + mapper->unitPerPixelX * pos.x());
//    result->setLatitude(mapper->maxYValue - mapper->unitPerPixelY * pos.y());
//    result->setHeight(0);
//}
