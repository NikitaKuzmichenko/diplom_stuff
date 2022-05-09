#ifndef MARKERNODE_H
#define MARKERNODE_H

#include "NodePoint.h"

/*
 * маркирующая узловая точка
*/
class MarkerNode : public NodePoint{
public:
    MarkerNode();
    MarkerNode(PhysicalPoint *point);
    MarkerNode(double longitude,double latitude,double height);

};

#endif // MARKERNODE_H
