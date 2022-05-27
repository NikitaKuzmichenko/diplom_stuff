#ifndef NODEPOINT_H
#define NODEPOINT_H

#include <QString>
#include <simulation/map/PhysicalPoint.h>
#include <simulation/node/NodePointType.h>

class NodePoint{
public:

    NodePoint();
    NodePoint(PhysicalPoint *point);
    NodePoint(double longitude,double latitude,double height);
    virtual ~NodePoint();

    long getId();
    void setId(long value);

    QString* getName();
    void setName(QString *value);

    PhysicalPoint *getPoint();
    void setPoint(PhysicalPoint *value);

    QString generateDefaultName();

    NP::NodePointType type = NP::UNDEFINED_NODE; // тип точки

    bool isTurnNode();
    bool isUdefinedNode();

    double getDistanceFromSegmentStart();
    void setDistanceFromSegmentStart(double value);

    virtual QString toString();

    long getSegmentId();
    void setSegmentId(long value);

protected:
    long id = 0;
    long segmentId = -1;
    QString *name = nullptr; // отображаемое название точки
    PhysicalPoint *point; // широта, долгота, высота точки
    double distanceFromSegmentStart = -1; // расстояние от начала сегмета, -1 если не назначено
};

#endif // NODEPOINT_H
