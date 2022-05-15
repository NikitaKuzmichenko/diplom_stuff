#ifndef PLANESIMULATIONVIEW_H
#define PLANESIMULATIONVIEW_H

#include "SimulationView.h"

class PlaneSimulationView : public SimulationView{
public:
    PlaneSimulationView(Simulation *simulation,LayerManager *layerManager,ViewMapper *mapper);

    bool updateNode(DisplayedNode *selectedNode, QPointF pos);
    bool moveNode(DisplayedNode *selectedNode, QPointF newPos);
    void loadAllFromSimulation();
    void loadPointFromSimulation(long id);
    void loadSegmentFromSimulation(long id);
    void loadWayPointFromSimulation(long id);

protected:
    PhysicalPoint *convertPositionTopoint(QPointF pos);
    QPointF getPositionFromPoint(PhysicalPoint *pos);
};

#endif // PLANESIMULATIONVIEW_H
