#ifndef CLICABLEPLANESCENE_H
#define CLICABLEPLANESCENE_H

#include "ClicableScene.h"



class ClicablePlaneScene: public ClicableScene{
    Q_OBJECT
public:
    ClicablePlaneScene(QObject *parent = 0);
    ClicablePlaneScene(SimulationViewTest *view,LayerManager *layerManager);
protected:
    bool selectItem(QPointF pos);
    bool releaseItem(QPointF pos);
    bool moveItem(QPointF pos);
    bool createItem(QPointF pos, NP::NodePointType type);
    bool createItemOnSegment(QPointF pos, NP::NodePointType type);
    bool deleteItem(QPointF pos);
};

#endif // CLICABLEPLANESCENE_H
