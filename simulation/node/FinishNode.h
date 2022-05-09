#ifndef FINISHNODE_H
#define FINISHNODE_H

#include "NodePoint.h"

/*
 * узловая точка конца пути
*/
class FinishNode : public NodePoint{
public:
    FinishNode();
    FinishNode(PhysicalPoint *point);
    FinishNode(double longitude,double latitude,double height);
};

#endif // FINISHNODE_H
