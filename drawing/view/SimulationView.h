#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <drawing/item/segment/DisplayedSegment.h>
#include <drawing/item/segment/DisplayedSegmentCreator.h>
#include <drawing/item/node/DisplayedNodeCreator.h>
#include <simulation/Simulation.h>
#include <drawing/layers/LayerManager.h>
#include <drawing/item/wayPoint/DisplayedWayPoint.h>
#include <drawing/item/wayPoint/DisplayedWayPointCreator.h>

class SimulationView : public QObject{
    Q_OBJECT
public:
    SimulationView(Simulation *simulation,LayerManager *layerManager,ViewMapper *mapper);
    ~SimulationView();

    void createNewTurnPoint(QPointF pos,NP::NodePointType type);
    void addNewNodeToSegment(QPointF pos,NP::NodePointType type,long segmentId);
    void deleteNode(DisplayedNode *nodeItem);

    DisplayedNode *findNodeByMainItem(QGraphicsItem *item);
    DisplayedSegment *findSegmentByMainItem(QGraphicsItem *item);
    DisplayedWayPoint *findWayPointByMainItem(QGraphicsItem *item);

    void updateRelatedSegments(DisplayedNode *point);

    virtual bool updateNode(DisplayedNode *selectedNode,QPointF pos) = 0;
    virtual bool moveNode(DisplayedNode *selectedNode, QPointF newPos) = 0;

    ViewMapper *getMapper();
    void setMapper(ViewMapper *value);

protected:

    DisplayedNode *findNodeById(long id);
    DisplayedSegment *findSegmentById(long id);

    DisplayedSegment *displaySegment(DisplayedNode *startPoint, DisplayedNode *endPoint,long id);
    DisplayedNode *displayPoint(NodePoint *realPoint,QPointF pos);
    DisplayedWayPoint *displayWayPoint(WayPoint *realPoint,QPointF pos);

    QVector<DisplayedSegment *> getRelatedSegments(DisplayedNode *point);

    virtual PhysicalPoint *convertPositionToPoint(QPointF pos) = 0;
    virtual QPointF convertPointToPosition(PhysicalPoint *pos) = 0;

    DisplayedNodeCreator *nodeCreator = new DisplayedNodeCreator();
    DisplayedSegmentCreator *segmentCreator = new DisplayedSegmentCreator();
    DisplayedWayPointCreator *wayPointCreator = new DisplayedWayPointCreator();

    QVector<DisplayedSegment *> *segments;
    QVector<DisplayedNode *> *nodes;
    QVector<DisplayedWayPoint *> *wayPoints;

    Simulation *simulation;
    LayerManager *layerManager;

    ViewMapper *mapper;

public slots:
    virtual void segmentWasCreated(long segmentId) = 0;
    virtual void segmentWasDeleted(long segmentId) = 0;
    virtual void segmentWasUpdated(long segmentId) = 0;

    virtual void nodeWasDeleted(long nodeId) = 0;
    virtual void nodeWasCreated(long nodeId) = 0;
    virtual void nodeWasUpdated(long nodeId) = 0;
    virtual void nodeWasAddedToSegment(long nodeId,long segmentId) = 0;

    virtual void wayPointWasDeleted(long id) = 0;
    virtual void wayPointWasCreated(long id) = 0;
};

#endif // SIMULATIONVIEW_H
