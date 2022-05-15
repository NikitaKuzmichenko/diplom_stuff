#include "Simulation.h"

#include <QVector>
#include <QDebug>
#include <windows.h>
#include <simulation/node/ClimbNode.h>
#include <simulation/node/CruiseNode.h>
#include <simulation/node/DemNode.h>
#include <simulation/node/DescentNode.h>
#include <simulation/node/FinishNode.h>
#include <simulation/node/ImgNode.h>
#include <simulation/node/MarkerNode.h>
#include <simulation/node/TakeoffNode.h>
#include <simulation/node/TurnNode.h>
#include <utils/GeodesicUtils.h>

Simulation::Simulation(){
    turnPoints = new QVector<NodePoint *>;
    segments = new QVector<Segment *>;
    wayPoints = new QVector<WayPoint *>;
    readerWriter = new SimulationReaderWriter();
}

Simulation::~Simulation(){
    delete [] turnPoints;
    delete [] segments;
    delete readerWriter;
}

NodePoint *Simulation::createTurnNode(PhysicalPoint *point, NP::NodePointType type){
    NodePoint * result = initNode(point,type);
    turnPoints->append(result);
    return result;
}

NodePoint *Simulation::createTurnNode(PhysicalPoint *point, NP::NodePointType type, long positionInList){
    NodePoint * result = initNode(point,type);
    turnPoints->insert(positionInList,result);
    return result;
}

NodePoint *Simulation::createNodeOnSegment(PhysicalPoint *point, NP::NodePointType type, long segmentId){
     NodePoint * result = initNode(point,type);
    getSegment(segmentId)->addNodePoint(result);
    return result;
}

void Simulation::removeNode(long positionInList){
    turnPoints->removeAt(positionInList);
}

Segment *Simulation::createSegment(NodePoint *start, NodePoint *end){
    Segment *segment = new Segment(start,end);
    segment->setId(segmentId);
    segmentId++;

    segments->append(segment);
    return segment;
}

Segment *Simulation::createSegment(NodePoint *start, NodePoint *end, long positionInList){
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

NodePoint *Simulation::getNode(long id){
    for(int i=0;i<turnPoints->length();i++){
        if(turnPoints->at(i)->getId() == id){
            return turnPoints->at(i);
        }
    }

    for(int i=0;i<segments->length();i++){
        Segment * seg = segments->at(i);
        for(int j=0;j<seg->getNodes()->length();i++){
            if(seg->getNodes()->at(j)->getId() == id){
                return seg->getNodes()->at(j);
            }
        }
    }

    return nullptr;
}

Segment *Simulation::getSegment(long id){
    for(int i=0;i<segments->length();i++){
        if(segments->at(i)->getId() == id){
            return segments->at(i);
        }
    }

    return nullptr;
}

WayPoint *Simulation::getWayPoint(long id){
    for(int i=0;i<wayPoints->length();i++){
        if(wayPoints->at(i)->id == id){
            return wayPoints->at(i);
        }
    }

    return nullptr;
}

int Simulation::getTurnNodePositionInCollection(long id){
    for(int i=0;i<turnPoints->length();i++){
        if(turnPoints->at(i)->getId() == id){
           return i;
        }
    }
    return -1;
}

int Simulation::geSegmentPositionInCollection(long id){
    for(int i=0;i<segments->length();i++){
        if(segments->at(i)->getId() == id){
           return i;
        }
    }
    return -1;
}

QVector<Segment *> Simulation::getRelatedSegments(long nodeId){
    QVector<Segment *> result = QVector<Segment *>();
    int counter = 0;
    for(int i=0;i<segments->length() && counter < 2;i++){
        if(segments->at(i)->containNode(nodeId)){
            counter++;
            result.append(segments->at(i));
        }
    }

    return result;
}


void Simulation::removeSegment(long positionInList){
    segments->removeAt(positionInList);
}

void Simulation::updateNode(){
    qInfo() << "mhetod updateNode in Simulation calss - do nothing";
}

void Simulation::updateTurnPoints(){
    for(int i=1;i<turnPoints->length() - 1;i++){
       ((TurnNode*)turnPoints->at(i))->calcualteTurnRadius();
    }
}

bool Simulation::simulate(){
    WinExec(genarateExecutecommand().toStdString().c_str(),SW_HIDE);
    QVector<NodePoint *> *nodes = readerWriter->getNodePoints(nodeId);
    if(nodes == nullptr){
        return false;
    }
    if(!nodes->at(0)->isTurnNode() || !nodes->at(nodes->length() - 1)->isTurnNode()){
        return false;
    }

    int segmentCounter = 0;
    Segment *newSgement;
    for(int i=0;i<nodes->length();i++){

        if(nodes->at(i)->isTurnNode()){
            turnPoints->append(nodes->at(i));
            if(i==0){// первый узел поврота (start)
                newSgement = new Segment();
                newSgement->setId(segmentCounter);
                newSgement->setStartPoint(nodes->at(i));
                continue;
            }
            if(i==nodes->length() - 1){// последний узел поврота (finish)
                newSgement->setEndPoint(nodes->at(i));
                newSgement->calculateDistance();
                segments->append(newSgement);
                continue;
            }

            newSgement->setEndPoint(nodes->at(i));
            newSgement->calculateDistance();
            segments->append(newSgement);

            segmentCounter++;
            newSgement = new Segment();
            newSgement->setId(segmentCounter);
            newSgement->setStartPoint(nodes->at(i));

        }else{
            nodes->at(i)->setSegmentId(segmentCounter);
            newSgement->addNodePoint(nodes->at(i));
        }
    }

    QList<WayPoint *> *waypoints = readerWriter->getWayPoints(wayPointId);

    if(waypoints != nullptr){
        this->wayPoints = waypoints;
    }

    delete waypoints;
    delete nodes;
    return true;
}

int Simulation::isReadyForSimulation(){
    if(readerWriter->isFileExists(readerWriter->exePath)){
        return 1;
    }
    if(readerWriter->isFileExists(readerWriter->routePath)){
        return 2;
    }

    return 0;
}

QString Simulation::genarateExecutecommand(){
    QString result = QString();
    result.append(readerWriter->exePath).append(" ");
    result.append("--config ").append(readerWriter->configPath).append(" ");
    result.append("--nodelist ").append(readerWriter->routePath).append(" ");
    result.append("--detail_log ").append(readerWriter->detailsPath).append(" ");
    result.append("--flight-program ").append(readerWriter->programPath).append(" ");
    result.append("--stderr ").append(readerWriter->errorPath).append(" ");
    result.append("--stdout ").append(readerWriter->logPath);
    return result;
}

int Simulation::validateNodePoints(){
    if(turnPoints->length() < 2){
        return 3;
    }
    if(turnPoints->at(0)->type != NP::TAKEOFF_NODE){
        return 1;
    }
    if(turnPoints->at(turnPoints->length()-1)->type != NP::FINISH_NODE){
        return 2;
    }
    for(int i=0;i<turnPoints->length();i++){
        if(turnPoints->at(i)->type == NP::UNDEFINED_NODE){
            return 4;
        }
    }

    return 0;
}

NodePoint *Simulation::initNode(PhysicalPoint *point, NP::NodePointType type){
    NodePoint *node;
    switch (type) {
    case NP::CLIMB_NODE : {
            node = new ClimbNode(point);
            break;
        }
        case NP::CRUISE_NODE : {
            node = new CruiseNode(point);
            break;
        }
        case NP::DEM_NODE : {
            node = new DemNode(point);
            break;
        }
        case NP::DESCENT_NODE : {
            node = new DescentNode(point);
            break;
        }
        case NP::FINISH_NODE : {
            node = new FinishNode(point);
            break;
        }
        case NP::IMG_NODE : {
            node = new ImgNode(point);
            break;
        }
        case NP::MARKER_NODE : {
            node = new MarkerNode(point);
            break;
        }
        case NP::TAKEOFF_NODE : {
            node = new TakeoffNode(point);
            break;
        }
        case NP::TURN_NODE : {
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

void Simulation::saveToFile(){
    QVector<NodePoint *> *nodes = new QVector<NodePoint *>();
    for(int i=0;i<turnPoints->length();i++){
        nodes->append(turnPoints->at(i));
        if(i < turnPoints->length() - 1){
            nodes->append(*segments->at(i)->getNodes());
        }
    }
    readerWriter->writeNodePointsToFile(nodes);
    delete nodes;
}

QVector<NodePoint *> *Simulation::getTurnPoints(){
    return turnPoints;
}

void Simulation::setTurnPoints(QVector<NodePoint *> *value){
    turnPoints = value;
}

QVector<Segment *> *Simulation::getSegments() {
    return segments;
}

void Simulation::setSegments(QVector<Segment *> *value){
    segments = value;
}

QVector<WayPoint *> *Simulation::getWayPoints(){
    return wayPoints;
}

void Simulation::setWayPoints(QVector<WayPoint *> *value){
    wayPoints = value;
}
