#ifndef PLANESIMULATIONVIEW_H
#define PLANESIMULATIONVIEW_H

#include "SimulationView.h"

class PlaneSimulationView : public SimulationView{
public:
    PlaneSimulationView(Simulation *simulation,LayerManager *layerManager,ViewMapper *mapper);

    bool updateNode(DisplayedNode *selectedNode, QPointF pos);
    bool moveNode(DisplayedNode *selectedNode, QPointF newPos);

protected:
    PhysicalPoint *convertPositionToPoint(QPointF pos);
    QPointF convertPointToPosition(PhysicalPoint *pos);

    // SimulationView interface
public slots:
    void segmentWasCreated(long segmentId);
    void segmentWasDeleted(long segmentId);
    void segmentWasUpdated(long segmentId);
    void nodeWasUpdated(long nodeId);
    void nodeWasAddedToSegment(long nodeId, long segmentId);
    void nodeWasCreated(long nodeId);
    void nodeWasDeleted(long nodeId);

    void wayPointWasDeleted(long id);
    void wayPointWasCreated(long id);
};

#endif // PLANESIMULATIONVIEW_H
