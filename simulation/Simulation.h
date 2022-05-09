#ifndef SIMULATION_H
#define SIMULATION_H

#include <QString>
#include <drawing/view/maper/PlaneViewMapper.h>
#include <simulation/node/NodePoint.h>
#include <simulation/node/NodePointReaderWriter.h>
#include <simulation/segment/Segment.h>

class Simulation{
public:
    Simulation();
    ~Simulation();

    NodePoint *addNodePoint(PhysicalPoint *point, NodePointType type);
    NodePoint *addNodePoint(PhysicalPoint *point, NodePointType type,long positionInList);

    void removeNode(NodePoint *point);
    void removeNode(long positionInList);

    Segment *addSegment(NodePoint *start,NodePoint *end);
    Segment *addSegment(NodePoint *start,NodePoint *end,long positionInList);

    void insertSegmentToEnd(Segment *segment);
    void insertSegment(Segment *segment,long position);

    void removeSegment(Segment *segment);
    void removeSegment(long positionInList);

    QVector<NodePoint *> *getNodePoints();
    void setNodePoints(QVector<NodePoint *> *value);

    QVector<Segment *> *getSegments();
    void setSegments(QVector<Segment *> *value);

private:
    long nodeId = 0;
    long segmentId = 0;
    long wayPointId = 0;

    QVector<NodePoint *> *turnPoints;
    QVector<Segment *> *segments;

    NodePoint *createNode(PhysicalPoint *point, NodePointType type);
};

#endif // SIMULATION_H
