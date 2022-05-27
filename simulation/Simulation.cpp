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
    delete turnPoints;
    delete segments;
    delete readerWriter;
}

// ====================================================================================
//                                getters setters
// ====================================================================================
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

SimulationReaderWriter *Simulation::getReaderWriter(){
    return readerWriter;
}

void Simulation::setReaderWriter(SimulationReaderWriter *value){
    readerWriter = value;
}
// ====================================================================================
//                                 create elements
// ====================================================================================
NodePoint *Simulation::createNode(PhysicalPoint *point, NP::NodePointType type){
    NodePoint * result = initNode(point,type);
    turnPoints->append(result);
    emit nodeCreated(result->getId());
    return result;
}

NodePoint *Simulation::createTurnNode(PhysicalPoint *point, NP::NodePointType type){
    NodePoint * result = initNode(point,type);
    turnPoints->append(result);
    emit nodeCreated(result->getId());

    if(turnPoints->length() >= 2){
        NodePoint *prevNode = turnPoints->at(turnPoints->indexOf(result)-1);
        createSegment(prevNode,result)->getId();
    }

    return result;
}

NodePoint *Simulation::createTurnNode(PhysicalPoint *point, NP::NodePointType type, long positionInList){
    NodePoint * result = initNode(point,type);
    turnPoints->insert(positionInList,result);

    emit nodeCreated(result->getId());
    return result;
}

NodePoint *Simulation::createNodeOnSegment(PhysicalPoint *point, NP::NodePointType type, long segmentId){
    if(type == NP::TURN_NODE){
        splitSegments(createNode(point,type),getSegment(segmentId));
    }
    else{
        getSegment(segmentId)->addNodePoint(createNode(point,type));
    }
}

Segment *Simulation::createSegment(NodePoint *start, NodePoint *end){
    Segment *segment = new Segment(start,end);
    segment->setId(segmentId);
    segments->append(segment);
    segment->calculateSegment();
    emit segmentCreated(segmentId);

    segmentId++;
    return segment;
}

Segment *Simulation::createSegment(NodePoint *start, NodePoint *end, long positionInList){
    Segment *segment = new Segment(start,end);
    segment->setId(segmentId);
    segments->insert(positionInList,segment);
    segment->calculateSegment();
    emit segmentCreated(segmentId);

    segmentId++;
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

// ====================================================================================
//                                 segments manipulations
// ====================================================================================
void Simulation::splitSegments(NodePoint *middlePoint,Segment *segment){
    long segmentPosition = geSegmentPositionInCollection(segment->getId());
    NodePoint *start = segment->getStartPoint();
    NodePoint *end = segment->getEndPoint();

    double splitDistance = GeodesicUtils::getDistanceBetweenPoints(start->getPoint(),middlePoint->getPoint());

    Segment * s1 = createSegment(start,middlePoint,segmentPosition);
    Segment * s2 = createSegment(middlePoint,end,segmentPosition + 1);

    for(int i=0;i< segment->getNodes()->length();i++){
        if(segment->getNodes()->at(i)->getDistanceFromSegmentStart() <= splitDistance){
            s1->addNodePoint(segment->getNodes()->at(i));
        }else{
            s2->addNodePoint(segment->getNodes()->at(i));
        }
    }
    segment->clearSegment();
    removeSegment(segment->getId());
}

Segment * Simulation::mergeSegments(Segment *segment1, Segment *segment2){
    NodePoint *newStart = segment1->getStartPoint();
    NodePoint *newEnd = segment2->getEndPoint();
    long position = geSegmentPositionInCollection(segment1->getId());

    Segment *merge = createSegment(newStart,newEnd,position);
    merge->getNodes()->append(segment1->getNodes()->toList());
    merge->getNodes()->append(segment2->getNodes()->toList());
    merge->calculateSegment();

    segment1->clearSegment();
    segment2->clearSegment();

    removeSegment(segment1->getId());
    removeSegment(segment2->getId());

    return merge;
}
// ====================================================================================
//                                 remove elements
// ====================================================================================
void Simulation::removeTurnPoint(NodePoint *point){
    QVector<Segment*> relatedSegments = getRelatedSegments(point->getId());
    if(relatedSegments.length() == 0){ // нет связанный сегметов
        turnPoints->removeOne(point);
        emit nodeDeleted(point->getId());
        delete point;
        return;
    }
    if(relatedSegments.length() == 1){ // есть один связанный сегмент - точка начала или конца
        removeSegment(relatedSegments.at(0)->getId());
        turnPoints->removeOne(point);
        emit nodeDeleted(point->getId());
        delete point;
        return;
    }
    if(relatedSegments.length() == 2){// есть два связанных сегмена
        mergeSegments(relatedSegments.at(0),relatedSegments.at(1));
        turnPoints->removeOne(point);
        emit nodeDeleted(point->getId());
        delete point;
        return;
    }
}

void Simulation::removeSegment(long id){
    Segment * s = getSegment(id);
    if(segments->removeOne(s)){
        for(int i=0;i<s->getNodes()->length();i++){
            emit nodeDeleted(s->getNodes()->at(i)->getId());
        }
        s->clearSegment();
        delete s;
    }
    emit segmentDeleted(id);
}

void Simulation::removeNode(long id){
    for(int i=0;i<turnPoints->length();i++){
        if(turnPoints->at(i)->getId() == id){
            removeTurnPoint(turnPoints->at(i));
            return;
        }
    }

    for(int i=0;i<segments->length();i++){
        Segment * seg = segments->at(i);
        for(int j=0;j<seg->getNodes()->length();j++){
            if(seg->getNodes()->at(j)->getId() == id){
                seg->getNodes()->removeAt(j);
                emit nodeDeleted(id);
                return;
            }
        }
    }
}
// ====================================================================================
//                                 get by id
// ====================================================================================
NodePoint *Simulation::getNode(long id){
    for(int i=0;i<turnPoints->length();i++){
        if(turnPoints->at(i)->getId() == id){
            return turnPoints->at(i);
        }
    }

    for(int i=0;i<segments->length();i++){
        Segment * seg = segments->at(i);
        for(int j=0;j<seg->getNodes()->length();j++){
            if(seg->getNodes()->at(j)->getId() == id){
                return seg->getNodes()->at(j);
            }
        }
    }

    return nullptr;
}

NodePoint *Simulation::changeNodeType(long id, NP::NodePointType type){
    NodePoint *oldNode = getNode(id);
    NodePoint *newNode = initNode(oldNode->getPoint(),type);
    newNode->setId(id);

    if(oldNode->isTurnNode() && !newNode->isTurnNode()){ // был точкой поврота , но стал не точной поврота
        QVector<Segment *> segments = getRelatedSegments(oldNode->getId());
        if(segments.length() == 2){
            Segment* newSemgent = mergeSegments(segments.at(0),segments.at(1));
            newSemgent->addNodePoint(newNode);
            oldNode = newNode;
        }
        if(segments.length() == 1){
            return oldNode;
        }
    }

    if(!oldNode->isTurnNode() && newNode->isTurnNode()){ // стал точкой поврота
        Segment *s = getSegment(oldNode->getSegmentId());
        s->getNodes()->removeOne(oldNode);

        long previusNodePos = getTurnNodePositionInCollection(s->getStartPoint()->getId());
        turnPoints->insert(previusNodePos+1,oldNode);

        splitSegments(oldNode,s);
        oldNode = newNode;
        emit updateNode(newNode->getId());
    }

    return newNode;
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
// ====================================================================================
//                                 get posiition in collection by id
// ====================================================================================
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

void Simulation::updateNode(long id){
    emit nodeUpdated(id);
    QVector<Segment *> relatedSegments = getRelatedSegments(id);
    for(int i=0;i< relatedSegments.length();i++){
        relatedSegments.at(i)->calculateSegment();
        emit segmentUpdated(relatedSegments.at(i)->getId());
    }
}
// ====================================================================================
//                                 validation
// ====================================================================================
int Simulation::isReadyForSimulation(){
    if(readerWriter->isFileExists(readerWriter->exePath)){
        return 1;
    }
    if(readerWriter->isFileExists(readerWriter->routePath)){
        return 2;
    }

    return 0;
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
// ====================================================================================
//                                 work with files
// ====================================================================================
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

void Simulation::clear(){
    for(int i=0;i< segments->length();i++){
        Segment *s = segments->at(i);
        for(int j=0;j<s->getNodes()->length();i++){
            emit nodeDeleted(s->getNodes()->at(j)->getId());
            delete s->getNodes();
        }
        emit segmentDeleted(s->getId());
        delete s;
    }

    for(int i=0;i<turnPoints->length();i++){
        emit nodeDeleted(turnPoints->at(i)->getId());
        delete turnPoints->at(i);
    }

    for(int i=0;i<wayPoints->length();i++){
        emit wayPointDeleted(wayPoints->at(i)->id);
        delete turnPoints->at(i);
    }

    wayPoints->clear();
    turnPoints->clear();
    segments->clear();
}

bool Simulation::simulate(){

    WinExec(genarateExecutecommand().toStdString().c_str(),SW_HIDE);
    QList<WayPoint *> *waypoints = readerWriter->getWayPoints(wayPointId);

    if(waypoints != nullptr){
        this->wayPoints = waypoints;
    }
    else{
        return false;
    }

    for(int i=0;i< waypoints->length();i++){
        emit wayPointCreated(waypoints->at(i)->id);
    }

    delete waypoints;

    return true;
}

bool Simulation::getNodePoints(){

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
                newSgement->calculateSegment();
                segments->append(newSgement);
                continue;
            }

            newSgement->setEndPoint(nodes->at(i));
            newSgement->calculateSegment();
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

    this->segmentId = segmentCounter;
    delete nodes;
}

void Simulation::display(){

    for(int i=0;i<turnPoints->length();i++){
        emit nodeCreated(turnPoints->at(i)->getId());
    }

    for(int i=0;i<segments->length();i++){
        emit segmentCreated(segments->at(i)->getId());
        Segment * seg = segments->at(i);
        for(int j=0;j<seg->getNodes()->length();j++){
            emit nodeCreated(seg->getNodes()->at(j)->getId());
        }
    }
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
// ====================================================================================
//                                 init node
// ====================================================================================
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
        case NP::UNDEFINED_NODE : {
            node = new NodePoint(point);
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
