#ifndef GEOGRAPHICGRIDLAYER_H
#define GEOGRAPHICGRIDLAYER_H

#include "SelfDrawingLayer.h"
#include "VisibleLayer.h"

#include <simulation/map/ElevationMap.h>


class GeographicGridLayer : public SelfDrawingLayer{
public:
    GeographicGridLayer(int zOrder);
    GeographicGridLayer(int zOrder, bool changeble);
    GeographicGridLayer(double wight,double hieght,double xIndent, double yIndent);

    void draw();
};

#endif // GEOGRAPHICGRIDLAYER_H
