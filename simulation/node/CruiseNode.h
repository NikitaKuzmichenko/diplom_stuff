#ifndef CRUISENODE_H
#define CRUISENODE_H

#include "NodePoint.h"

/*
 * узловая точка начала ускорения/замедления
*/
class CruiseNode : public NodePoint{
public:

    CruiseNode();
    CruiseNode(PhysicalPoint *point);
    CruiseNode(PhysicalPoint *point,double v);
    CruiseNode(double longitude,double latitude,double height);
    CruiseNode(double longitude,double latitude,double height,double v);

    double getV();
    void setV(double value);

    QString toString();
private:
    double v;
};

#endif // CRUISENODE_H
