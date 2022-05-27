#ifndef CLICABLEPLANESCENE_H
#define CLICABLEPLANESCENE_H

#include "ClicableScene.h"

class ClicablePlaneScene : public ClicableScene{
    Q_OBJECT
public:
    ClicablePlaneScene(QObject *parent = 0);
    ClicablePlaneScene(SimulationView *view,LayerManager *layerManager);

    void displayBackgound();
    void updateBackgound();
    void initVisiblaLayers();
protected:
    bool selectAnyItem(QPointF pos);
    bool selectItem(QPointF pos);
    bool releaseItem(QPointF pos);
    bool moveItem(QPointF pos);
    bool createItem(QPointF pos, NP::NodePointType type);
    bool createItemOnSegment(QPointF pos, NP::NodePointType type);
    bool deleteItem(QPointF pos);

private:
    void initGrlidLayer(QImage img);

};

#endif // CLICABLEPLANESCENE_H
