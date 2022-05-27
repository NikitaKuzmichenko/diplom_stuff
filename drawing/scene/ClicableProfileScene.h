#ifndef CLICABLEPROFILESCENE_H
#define CLICABLEPROFILESCENE_H

#include "ClicableScene.h"



class ClicableProfileScene : public ClicableScene{
        Q_OBJECT
public:
    ClicableProfileScene(QObject *parent = 0);
    ClicableProfileScene(SimulationView *view,LayerManager *layerManager);

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

#endif // CLICABLEPROFILESCENE_H
