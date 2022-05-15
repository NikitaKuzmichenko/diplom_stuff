#include "PlaneSimulationView.h"

PlaneSimulationView::PlaneSimulationView(Simulation *simulation, LayerManager *layerManager, ViewMapper *mapper)
    : SimulationView(simulation,layerManager,mapper){}

bool PlaneSimulationView::updateNode(DisplayedNode *selectedNode, QPointF pos){

}

bool PlaneSimulationView::moveNode(DisplayedNode *selectedNode, QPointF newPos){

}

void PlaneSimulationView::loadAllFromSimulation(){

}

void PlaneSimulationView::loadPointFromSimulation(long id){

}

void PlaneSimulationView::loadSegmentFromSimulation(long id){

}

void PlaneSimulationView::loadWayPointFromSimulation(long id){

}

PhysicalPoint *PlaneSimulationView::convertPositionTopoint(QPointF pos){

}

QPointF PlaneSimulationView::getPositionFromPoint(PhysicalPoint *pos){

}
