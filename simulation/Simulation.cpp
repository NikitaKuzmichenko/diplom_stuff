#include "Simulation.h"

#include <QVector>

#include <simulation/node/ClimbNode.h>
#include <simulation/node/CruiseNode.h>
#include <simulation/node/DemNode.h>
#include <simulation/node/DescentNode.h>
#include <simulation/node/FinishNode.h>
#include <simulation/node/ImgNode.h>
#include <simulation/node/MarkerNode.h>
#include <simulation/node/TakeoffNode.h>
#include <simulation/node/TurnNode.h>

Simulation::Simulation(){
    turnPoints = new QVector<NodePoint *>;
    segments = new QVector<Segment *>;
}

Simulation::~Simulation(){
    delete [] turnPoints;
    delete [] segments;
}

NodePoint *Simulation::addNodePoint(PhysicalPoint *point, NodePointType type){
    NodePoint * result= createNode(point,type);
    turnPoints->append(result);
    return result;
}

NodePoint *Simulation::addNodePoint(PhysicalPoint *point, NodePointType type, long positionInList){
    NodePoint * result= createNode(point,type);
    turnPoints->insert(positionInList,result);
    return result;
}

void Simulation::removeNode(NodePoint *point){
    turnPoints->removeOne(point);
}

void Simulation::removeNode(long positionInList){
    turnPoints->removeAt(positionInList);
}

Segment *Simulation::addSegment(NodePoint *start, NodePoint *end){
    Segment *segment = new Segment(start,end);
    segment->setId(segmentId);
    segmentId++;

    segments->append(segment);
    return segment;
}

Segment *Simulation::addSegment(NodePoint *start, NodePoint *end, long positionInList){
    Segment *segment = new Segment(start,end);
    segment->setId(segmentId);
    segmentId++;

    segments->insert(positionInList,segment);
    return segment;
}

void Simulation::insertSegmentToEnd(Segment *segment){
    segment->setId(segmentId);
    segmentId++;
    segments->append(segment);
}

void Simulation::insertSegment(Segment *segment, long position){
    segment->setId(segmentId);
    segmentId++;
    segments->insert(position,segment);
}

void Simulation::removeSegment(Segment *segment){
    segments->removeOne(segment);
}

void Simulation::removeSegment(long positionInList){
    segments->removeAt(positionInList);
}

QVector<NodePoint *> *Simulation::getNodePoints(){
    return turnPoints;
}

void Simulation::setNodePoints(QVector<NodePoint *> *value){
    turnPoints = value;
}

QVector<Segment *> *Simulation::getSegments() {
    return segments;
}

void Simulation::setSegments(QVector<Segment *> *value){
    segments = value;
}

NodePoint *Simulation::createNode(PhysicalPoint *point, NodePointType type){
    NodePoint *node;
    switch (type) {
    case CLIMB_NODE : {
        node = new ClimbNode(point);
            break;
        }
        case CRUISE_NODE : {
            node = new CruiseNode(point);
            break;
        }
        case DEM_NODE : {
            node = new DemNode(point);
            break;
        }
        case DESCENT_NODE : {
            node = new DescentNode(point);
            break;
        }
        case FINISH_NODE : {
            node = new FinishNode(point);
            break;
        }
        case IMG_NODE : {
            node = new ImgNode(point);
            break;
        }
        case MARKER_NODE : {
            node = new MarkerNode(point);
            break;
        }
        case TAKEOFF_NODE : {
            node = new TakeoffNode(point);
            break;
        }
        case TURN_NODE : {
            node = new TurnNode(point);
            break;
        }
        default:{
            node = new NodePoint(point);
            break;
        }
    }

    node->setId(nodeId);
    nodeId++;
    return node;
}
