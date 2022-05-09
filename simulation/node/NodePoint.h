#ifndef NODEPOINT_H
#define NODEPOINT_H

#include <QString>
#include <simulation/map/PhysicalPoint.h>

enum NodePointType {
    UNDEFINED_NODE,
    TAKEOFF_NODE,
    FINISH_NODE,
    TURN_NODE,
    EVENT_NODE,
    CLIMB_NODE,
    DESCENT_NODE,
    CRUISE_NODE,
    MARKER_NODE,
    IMG_NODE,
    DEM_NODE
};

/*
 * узловая точка
*/
class NodePoint{
public:

    NodePoint();
    NodePoint(PhysicalPoint *point);
    NodePoint(double longitude,double latitude,double height);
    ~NodePoint();

    long getId();
    void setId(long value);

    QString* getName();
    void setName(QString *value);

    PhysicalPoint *getPoint();
    void setPoint(PhysicalPoint *value);

    void generateDefaultName();

    NodePointType type = UNDEFINED_NODE; // тип точки

protected:
    long id = 0; // ид точки
    QString *name = nullptr; // отображаемое название точки

    PhysicalPoint *point; // широта, долгота, высота точки

};

#endif // NODEPOINT_H
