#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <drawing/item/segment/DisplayedSegment.h>
#include <drawing/item/segment/DisplayedSegmentCreator.h>
#include <drawing/item/node/DisplayedNodeCreator.h>
#include <simulation/Simulation.h>
#include <drawing/layers/LayerManager.h>
#include <drawing/item/wayPoint/DisplayedWayPoint.h>
#include <drawing/item/wayPoint/DisplayedWayPointCreator.h>

class SimulationView{
public:
    SimulationView(Simulation *simulation,LayerManager *layerManager,ViewMapper *mapper);
    ~SimulationView();

    DisplayedNode *createTurnPoint(QPointF pos,NP::NodePointType type);
    DisplayedNode *createTurnPoint(QPointF pos,NP::NodePointType type,long positioInList);

    DisplayedNode *addPointToSegment(QPointF pos,NP::NodePointType type,long segmentId);
    DisplayedNode *addTurnPointToSegment(QPointF pos,NP::NodePointType type,long segmentId);
    
    DisplayedNode *findNodeByMainItem(QGraphicsItem *item);
    DisplayedSegment *findSegmentByMainItem(QGraphicsItem *item);
    DisplayedWayPoint *findWayPointByMainItem(QGraphicsItem *item);

    void deleteNode(DisplayedNode *nodeItem);
    virtual bool updateNode(DisplayedNode *selectedNode,QPointF pos) = 0;
    
    virtual bool moveNode(DisplayedNode *selectedNode, QPointF newPos) = 0;

    virtual void loadAllFromSimulation() = 0;
    virtual void loadPointFromSimulation(long id) = 0;
    virtual void loadSegmentFromSimulation(long id) = 0;
    virtual void loadWayPointFromSimulation(long id) = 0;

protected:

    DisplayedSegment *createSegment(DisplayedNode *startPoint, DisplayedNode *endPoint);
    DisplayedSegment *createSegment(DisplayedNode *startPoint, DisplayedNode *endPoint,long positioInList);

    DisplayedNode *createPoint(NodePoint *realPoint);
    DisplayedNode *createPoint(NodePoint *realPoint,QPointF pos);
    DisplayedWayPoint *createWayPoint(WayPoint *realPoint);

    void updateRelatedSegments(DisplayedNode *point);
    QVector<DisplayedSegment *> getRelatedSegments(DisplayedNode *point);

    virtual PhysicalPoint *convertPositionTopoint(QPointF pos) = 0;
    virtual QPointF getPositionFromPoint(PhysicalPoint *pos) = 0;

    DisplayedNodeCreator *nodeCreator = new DisplayedNodeCreator();
    DisplayedSegmentCreator *segmentCreator = new DisplayedSegmentCreator();
    DisplayedWayPointCreator *wayPointCreator = new DisplayedWayPointCreator();

    QVector<DisplayedSegment *> *segments;
    QVector<DisplayedNode *> *nodes;
    QVector<DisplayedWayPoint *> *wayPoints;

    Simulation *simulation;
    LayerManager *layerManager;

    ViewMapper *mapper;
};

#endif // SIMULATIONVIEW_H
