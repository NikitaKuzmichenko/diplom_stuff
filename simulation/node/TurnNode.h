#ifndef TURNNODE_H
#define TURNNODE_H

#include "NodePoint.h"

/*
 * узловая точка разворота
*/
class TurnNode : public NodePoint{
public:

    TurnNode();
    TurnNode(PhysicalPoint *point);
    TurnNode(PhysicalPoint *point, double r, double v, double psi);
    TurnNode(double longitude, double latitude, double height);
    TurnNode(double longitude, double latitude, double height, double r, double v, double psi);

    double getR();
    void setR(double value);

    double getV();
    void setV(double value);

    double getPsi();
    void setPsi(double value);

    void calcualteTurnRadius();
    QString toString();
private:
    double r = 0;    // радиус разворота
    double v = 0;    // скорость прохождения
    double psi = 0; // угол крена
};

#endif // TURNNODE_H
