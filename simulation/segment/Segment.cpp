#include "Segment.h"
#include <QVector>
#include <QDebug>
#include <simulation/node/ClimbNode.h>
#include <simulation/node/DescentNode.h>
#include <utils/GeodesicUtils.h>

Segment::Segment(){
    nodes = new  QVector<NodePoint *>();
}

Segment::Segment(NodePoint *startPoint, NodePoint *endPoint){
    this->startPoint = startPoint;
    this->endPoint = endPoint;

    nodes = new QVector<NodePoint *>();
}

Segment::~Segment(){
    delete nodes;
}

NodePoint *Segment::getStartPoint() {
    return startPoint;
}

void Segment::setStartPoint(NodePoint *value){
    startPoint = value;
}

NodePoint *Segment::getEndPoint(){
    return endPoint;
}

void Segment::setEndPoint(NodePoint *value){
    endPoint = value;
}

long Segment::getId(){
    return id;
}

void Segment::setId(long value){
    id = value;
}

void Segment::addNodePoint(NodePoint *point){
    nodes->append(point);
    point->setSegmentId(id);
}

void Segment::addNodePoint(NodePoint *point, long position){
    nodes->insert(position,point);
    point->setSegmentId(id);
}

bool Segment::removeNodePoint(long pointId){
    for(int i=0;i<nodes->length();i++){
        if(nodes->at(i)->getId() == pointId){
            nodes->removeAt(i);
            return true;
        }
    }
    return  false;
}

bool Segment::containNode(long nodeId){
    if(startPoint->getId() == nodeId){
        return  true;
    }
    if(endPoint->getId() == nodeId){
        return  true;
    }

    return (getNodePoint(nodeId) != nullptr);
}

NodePoint *Segment::getNodePoint(long pointId){
    for(int i=0;i<nodes->length();i++){
        if(nodes->at(i)->getId() == pointId){
            return nodes->at(i);
        }
    }
    return  nullptr;
}

void Segment::sortNodesByDistanceFromStart(){
      std::sort(nodes->begin(),nodes->end(),
                [](NodePoint *node1, NodePoint *node2)->bool
                  {
                      return node1->getDistanceFromSegmentStart() < node2->getDistanceFromSegmentStart();
                  });
}

void Segment::clearSegment(){
    nodes->clear();
}

void Segment::calculateDistance(){
    InversGeoProblemSolution solution = GeodesicUtils::inversGeopoblem(startPoint->getPoint(),endPoint->getPoint());
    lenght = solution.dist;
    startCource = solution.azim1;
    endCource = solution.azim2;
    for(int i=0;i<nodes->length();i++){
        NodePoint *p =nodes->at(i);
        p->setSegmentId(id);
        p->setDistanceFromSegmentStart(GeodesicUtils::getDistanceBetweenPoints(startPoint->getPoint(),p->getPoint()));
    }
}

void Segment::calculateHieghtChane(){
    for(int i=0;i<nodes->length();i++){

        NodePoint *nextNode;
        if(i == nodes->length() - 1){
              nextNode = endPoint;
        }else{
            nextNode = nodes->at(i+1);
        }

        NodePoint *p = nodes->at(i);
        if(p->type == NP::CLIMB_NODE ){
           ((ClimbNode*)p)->setTheta(GeodesicUtils::getPitсh(p->getPoint(),nextNode->getPoint()));
        }
        if(p->type == NP::DESCENT_NODE){
           ((DescentNode*)p)->setTheta(GeodesicUtils::getPitсh(p->getPoint(),nextNode->getPoint()));
        }
    }
}

void Segment::calculateSegment(){
    calculateDistance();
    sortNodesByDistanceFromStart();
    calculateHieghtChane();
}

QString Segment::toString(){
    QString result = QString();
    result.append("Segment :");
    result.append("id = "+ QString::number(id));
    result.append("lenght = " + QString::number(lenght));
    result.append("Start point : " + startPoint->toString());
    result.append("End point : " + endPoint->toString());
    return result;
}

QVector<NodePoint *> *Segment::getNodes(){
    return nodes;
}

void Segment::setNodes(QVector<NodePoint *> *value){
    nodes = value;
}
