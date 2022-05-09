#ifndef LAYERMANAGER_H
#define LAYERMANAGER_H

#include "VisibleLayer.h"

#include <QMap>

enum LayerName{backgroud,grid,text,lines,node_point};

class LayerManager{
public:
    LayerManager();
    ~LayerManager();

    void addlayer(LayerName name,VisibleLayer* layer);
    void removeLayer(LayerName name);

    VisibleLayer *getLayerByName(LayerName name);

    void addToLayer(LayerName name,QGraphicsItem *item);
    void removeFromLayer(LayerName name,QGraphicsItem *item);

    void addToFirstLayer(QGraphicsItem *item);
    void removeFromFirstLayer(QGraphicsItem *item);

    QMap<LayerName, VisibleLayer *> *getLayers();
    void setLayers(QMap<LayerName, VisibleLayer *> *value);

private:
    QMap<LayerName, VisibleLayer *> *layers;
};

#endif // LAYERMANAGER_H
