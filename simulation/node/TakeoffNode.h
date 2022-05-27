#ifndef TAKEOFFNODE_H
#define TAKEOFFNODE_H

#include "NodePoint.h"


/*
 * узловая точка подъёма
*/
class TakeoffNode : public NodePoint{
public:    
    TakeoffNode();
    TakeoffNode(PhysicalPoint *point);
    TakeoffNode(PhysicalPoint *point,double v);
    TakeoffNode(double longitude,double latitude,double height);
    TakeoffNode(double longitude,double latitude,double height,double v);

    double getV();
    void setV(double value);

    QString toString();
private:
    double  v = 0;    // скорость
};

#endif // TAKEOFFNODE_H
