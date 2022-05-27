#ifndef HEIGHTGRIDLAYER_H
#define HEIGHTGRIDLAYER_H

#include "SelfDrawingLayer.h"

class HeightGridLayer : public SelfDrawingLayer{
public:
    HeightGridLayer(int zOrder);
    HeightGridLayer(int zOrder, bool changeble);
    HeightGridLayer(double wight,double hieght,double xIndent, double yIndent);

    void draw();
};

#endif // HEIGHTGRIDLAYER_H
