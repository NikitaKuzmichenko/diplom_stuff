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

ViewMapper *SimulationView::getMapper(){
    return mapper;
}

void SimulationView::setMapper(ViewMapper *value){
    mapper = value;
}

DisplayedNode *SimulationView::findNodeById(long id){
    for(auto result: *nodes){
        if(result->getId()== id){
            return result;
        }
    }
    return nullptr;
}

DisplayedSegment *SimulationView::findSegmentById(long id){
    for(auto result: *segments){
        if(result->getId()== id){
            return result;
        }
    }
    return nullptr;
}

//=============================================================================
void SimulationView::createNewTurnPoint(QPointF pos, NP::NodePointType type){
    simulation->createTurnNode(convertPositionToPoint(pos),type);
}

void SimulationView::addNewNodeToSegment(QPointF pos, NP::NodePointType type, long segmentId){
    simulation->createNodeOnSegment(convertPositionToPoint(pos),type,segmentId);
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
}


DisplayedSegment *SimulationView::displaySegment(DisplayedNode *startPoint, DisplayedNode *endPoint,long id){
    DisplayedSegment *segment = segmentCreator->createSegment(startPoint,endPoint,id);
    layerManager->getLayerByName(LayerName::line)->addItem(segment->getMainItem());

    segments->append(segment);

    return segment;
}

DisplayedNode *SimulationView::displayPoint(NodePoint *realPoint, QPointF pos){
    DisplayedNode *displayedNode = nodeCreator->ceratePoint(realPoint,pos);
    displayedNode->createDescription();
    nodes->append(displayedNode);

    layerManager->getLayerByName(LayerName::node_point)->addItem(displayedNode->getMainItem());
    layerManager->getLayerByName(LayerName::text)->addItem(displayedNode->getText());

    return displayedNode;
}

DisplayedWayPoint *SimulationView::displayWayPoint(WayPoint *realPoint,QPointF pos){
    DisplayedWayPoint *displayedWayPoint = wayPointCreator->ceratePoint(realPoint,pos);
    displayedWayPoint->createDescription();
    wayPoints->append(displayedWayPoint);

    layerManager->getLayerByName(LayerName::way_point)->addItem(displayedWayPoint->getMainItem());
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
