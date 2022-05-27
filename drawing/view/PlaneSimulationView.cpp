#include "PlaneSimulationView.h"

PlaneSimulationView::PlaneSimulationView(Simulation *simulation, LayerManager *layerManager, ViewMapper *mapper)
    : SimulationView(simulation,layerManager,mapper){

    QObject::connect(simulation,&Simulation::segmentCreated,this,&SimulationView::segmentWasCreated);
    QObject::connect(simulation,&Simulation::segmentDeleted,this,&SimulationView::segmentWasDeleted);
    QObject::connect(simulation,&Simulation::segmentUpdated,this,&SimulationView::segmentWasUpdated);

    QObject::connect(simulation,&Simulation::nodeUpdated,this,&SimulationView::nodeWasUpdated);
    QObject::connect(simulation,&Simulation::nodeAddedToSegment,this,&SimulationView::nodeWasAddedToSegment);
    QObject::connect(simulation,&Simulation::nodeCreated,this,&SimulationView::nodeWasCreated);
    QObject::connect(simulation,&Simulation::nodeDeleted,this,&SimulationView::nodeWasDeleted);

    QObject::connect(simulation,&Simulation::wayPointDeleted,this,&SimulationView::wayPointWasDeleted);
    QObject::connect(simulation,&Simulation::wayPointCreated,this,&SimulationView::wayPointWasCreated);
}

bool PlaneSimulationView::updateNode(DisplayedNode *selectedNode, QPointF pos){
    if(selectedNode->getNode() == nullptr){
        return false;
    }
    selectedNode->getNode()->getPoint()->setLongitude(mapper->minXValue + mapper->unitPerPixelX * pos.x());
    selectedNode->getNode()->getPoint()->setLatitude(mapper->maxYValue - mapper->unitPerPixelY * pos.y());
    simulation->updateNode(selectedNode->getNode()->getId());
    return true;
}

PhysicalPoint *PlaneSimulationView::convertPositionToPoint(QPointF pos){
    PhysicalPoint *result = new PhysicalPoint();
    result->setLongitude(mapper->minXValue + mapper->unitPerPixelX * pos.x());
    result->setLatitude(mapper->maxYValue - mapper->unitPerPixelY * pos.y());
    return result;
}

QPointF PlaneSimulationView::convertPointToPosition(PhysicalPoint *pos){
    QPointF point = QPointF();
    double xPos = (pos->getLongitude() - mapper->minXValue) / mapper->unitPerPixelX;
    double yPos = (mapper->maxYValue - pos->getLatitude()) / mapper->unitPerPixelY;
    point.setX(xPos);
    point.setY(yPos);
    return point;
}

//=============================================================================

void PlaneSimulationView::segmentWasCreated(long segmentId){
    Segment * segment = simulation->getSegment(segmentId);
    DisplayedNode *startNode = findNodeById(segment->getStartPoint()->getId());
    DisplayedNode *finishNode = findNodeById(segment->getEndPoint()->getId());
    displaySegment(startNode,finishNode,segmentId);
}

void PlaneSimulationView::segmentWasDeleted(long segmentId){
    DisplayedSegment * segment = findSegmentById(segmentId);
    segments->removeOne(segment);
    delete segment;
}

void PlaneSimulationView::segmentWasUpdated(long segmentId){
    findSegmentById(segmentId)->updateCoordinates();
}

void PlaneSimulationView::nodeWasUpdated(long nodeId){
    DisplayedNode *node = findNodeById(nodeId);
    node->moveTo(convertPointToPosition(node->getNode()->getPoint()));
    node->createDescription();

}

void PlaneSimulationView::nodeWasAddedToSegment(long nodeId, long segmentId){
    NodePoint *node = simulation->getNode(nodeId);
    displayPoint(node,convertPointToPosition(node->getPoint()));
}

void PlaneSimulationView::nodeWasCreated(long nodeId){
    NodePoint *node = simulation->getNode(nodeId);
    displayPoint(node,convertPointToPosition(node->getPoint()));
}

void PlaneSimulationView::nodeWasDeleted(long nodeId){
    for(int i=0;i<nodes->length();i++){
        if(nodes->at(i)->getId() == nodeId){
            DisplayedNode *node = nodes->at(i);
             nodes->removeAt(i);
             delete node;
        }
    }
}

void PlaneSimulationView::wayPointWasDeleted(long id){
    for(int i=0;i<wayPoints->length();i++){
        if(wayPoints->at(i)->getId() == id){
            DisplayedWayPoint *point = wayPoints->at(i);
             wayPoints->removeAt(i);
             delete point;
        }
    }
}

void PlaneSimulationView::wayPointWasCreated(long id){
    WayPoint * point  = simulation->getWayPoint(id);
    displayWayPoint(point,convertPointToPosition(point->point));
}

//=============================================================================
bool PlaneSimulationView::moveNode(DisplayedNode *selectedNode, QPointF newPos){
    selectedNode->moveTo(newPos);
    updateRelatedSegments(selectedNode);
}

