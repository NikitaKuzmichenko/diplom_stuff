#ifndef SIMULATION_H
#define SIMULATION_H

#include <QString>
#include <drawing/view/maper/PlaneViewMapper.h>
#include <simulation/node/NodePoint.h>
#include <simulation/node/NodePointReaderWriter.h>
#include <simulation/segment/Segment.h>
#include <simulation/wayPoint/WayPoint.h>
#include "SimulationReaderWriter.h"

class Simulation{
public:
    Simulation();
    ~Simulation();

    NodePoint *createTurnNode(PhysicalPoint *point, NP::NodePointType type);
    NodePoint *createTurnNode(PhysicalPoint *point, NP::NodePointType type,long positionInList);

    NodePoint *createNodeOnSegment(PhysicalPoint *point, NP::NodePointType type,long segmentId);

    Segment *createSegment(NodePoint *start,NodePoint *end);
    Segment *createSegment(NodePoint *start,NodePoint *end,long positionInList);

    void insertSegmentToEnd(Segment *segment);
    void insertSegment(Segment *segment,long position);

    NodePoint *getNode(long id);
    Segment *getSegment(long id);
    WayPoint *getWayPoint(long id);

    int getTurnNodePositionInCollection(long id);
    int geSegmentPositionInCollection(long id);

    QVector<Segment *> getRelatedSegments(long nodeId);

    void removeNode(long id);
    void removeSegment(long id);

    void updateNode(); // сделать что нибудь и сюда сигналы запихать

    /*!
     * запускает flip.exe
    */
    bool simulate();
    /*!
        возвраящает коды ошибок
        0-всё впорядке
        1-нет exe файла
        2-нет файла с маршрутом
    */
    int isReadyForSimulation();
    /*!
        возвраящает коды ошибок
        0-всё впорядке
        1-нет точки всзлёта
        2-нет точки посадки
        3-недостаточно узловых точек
        4-приусдвуют неизвесные точки
    */
    int validateNodePoints();

    void saveToFile();
    /*!
     рассчитает углы поворота и радус поворота, если возможно.
    */
    void updateTurnPoints();

    QVector<NodePoint *> *getTurnPoints();
    void setTurnPoints(QVector<NodePoint *> *value);

    QVector<Segment *> *getSegments();
    void setSegments(QVector<Segment *> *value);

    QVector<WayPoint *> *getWayPoints();
    void setWayPoints(QVector<WayPoint *> *value);
private:
    long nodeId = 0;
    long segmentId = 0;
    long wayPointId = 0;

    QVector<NodePoint *> *turnPoints;
    QVector<Segment *> *segments;
    QVector<WayPoint *> *wayPoints;

    SimulationReaderWriter *readerWriter;
    NodePoint *initNode(PhysicalPoint *point, NP::NodePointType type);
    QString genarateExecutecommand();
};

#endif // SIMULATION_H
