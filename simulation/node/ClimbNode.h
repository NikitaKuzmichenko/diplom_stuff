#ifndef CLIMBNODE_H
#define CLIMBNODE_H

#include "NodePoint.h"

/*
 * узловая точка подъема
*/
class ClimbNode : public NodePoint{
public:
    ClimbNode();
    ClimbNode(PhysicalPoint *point);
    ClimbNode(PhysicalPoint *point, double theta, double v, double newH);
    ClimbNode(double longitude, double latitude, double height);
    ClimbNode(double longitude, double latitude, double height, double theta, double v, double newH);

    double getTheta();
    void setTheta(double value);

    double getV();
    void setV(double value);

    double getNewH();
    void setNewH(double value);

    QString toString();
private:
    double theta; // угол подъема (arctg(Vy/Vx))
    double v; // скорость в точке
    double newH; // высота после манёвра
};

#endif // CLIMBNODE_H
