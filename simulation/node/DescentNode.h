#ifndef DESCENTNODE_H
#define DESCENTNODE_H

#include "NodePoint.h"

/*
 * узловая точка снижения
*/
class DescentNode : public NodePoint{
public:

    DescentNode();
    DescentNode(PhysicalPoint *point);
    DescentNode(PhysicalPoint *point, double theta, double v, double newH);
    DescentNode(double longitude, double latitude, double height);
    DescentNode(double longitude, double latitude, double height, double theta, double v, double newH);

    double getTheta();
    void setTheta(double value);

    double getV();
    void setV(double value);

    double getNewH();
    void setNewH(double value);

    QString toString();
private:
    double theta = 0; // угол спуска (arctg(Vy/Vx))
    double v = 0; // скорость в точке
    double newH = 0; // высота после манёвра
};

#endif // DESCENTNODE_H
