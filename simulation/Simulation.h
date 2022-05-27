#ifndef SIMULATION_H
#define SIMULATION_H

#include <QString>
#include <drawing/view/maper/PlaneViewMapper.h>
#include <simulation/node/NodePoint.h>
#include <simulation/node/NodePointReaderWriter.h>
#include <simulation/segment/Segment.h>
#include <simulation/wayPoint/WayPoint.h>
#include "SimulationReaderWriter.h"

class Simulation : public QObject{
    Q_OBJECT
public:
    Simulation();
    ~Simulation();

    NodePoint *createNode(PhysicalPoint *point, NP::NodePointType type);
    NodePoint *createTurnNode(PhysicalPoint *point, NP::NodePointType type);
    NodePoint *createTurnNode(PhysicalPoint *point, NP::NodePointType type,long positionInList);

    NodePoint *createNodeOnSegment(PhysicalPoint *point, NP::NodePointType type,long segmentId);

    Segment *createSegment(NodePoint *start,NodePoint *end);
    Segment *createSegment(NodePoint *start,NodePoint *end,long positionInList);

    void splitSegments(NodePoint *middlePoint,Segment *segment);
    Segment *mergeSegments(Segment *segment1,Segment *segment2);

    void insertSegmentToEnd(Segment *segment);
    void insertSegment(Segment *segment,long position);

    NodePoint *getNode(long id);
    NodePoint *changeNodeType(long id,NP::NodePointType type);
    Segment *getSegment(long id);
    WayPoint *getWayPoint(long id);

    int getTurnNodePositionInCollection(long id);
    int geSegmentPositionInCollection(long id);

    QVector<Segment *> getRelatedSegments(long nodeId);

    void removeNode(long id);
    void removeSegment(long id);

    void updateNode(long id); // сделать что нибудь и сюда сигналы запихать

    /*!
     * запускает flip.exe
    */
    bool simulate();

    bool getNodePoints();

    void display();

    int isReadyForSimulation();

    int validateNodePoints();

    void saveToFile();

    void clear();

    QVector<NodePoint *> *getTurnPoints();
    void setTurnPoints(QVector<NodePoint *> *value);

    QVector<Segment *> *getSegments();
    void setSegments(QVector<Segment *> *value);

    QVector<WayPoint *> *getWayPoints();
    void setWayPoints(QVector<WayPoint *> *value);

    SimulationReaderWriter *getReaderWriter();
    void setReaderWriter(SimulationReaderWriter *value);

    NodePoint *initNode(PhysicalPoint *point, NP::NodePointType type);

private:
    long nodeId = 0;
    long segmentId = 0;
    long wayPointId = 0;

    QVector<NodePoint *> *turnPoints;
    QVector<Segment *> *segments;
    QVector<WayPoint *> *wayPoints;

    SimulationReaderWriter *readerWriter;

    void removeTurnPoint(NodePoint *point);

    QString genarateExecutecommand();

signals:
    void segmentCreated(long segmentId);
    void segmentDeleted(long segmentId);
    void segmentUpdated(long segmentId);

    void nodeDeleted(long nodeId);
    void nodeCreated(long nodeId);
    void nodeUpdated(long nodeId);
    void nodeAddedToSegment(long nodeId,long segmentId);

    void wayPointCreated(long id);
    void wayPointDeleted(long id);
};

#endif // SIMULATION_H
