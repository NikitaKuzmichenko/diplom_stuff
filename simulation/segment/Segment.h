#ifndef SEGMENT_H
#define SEGMENT_H

#include <simulation/node/NodePoint.h>


class Segment{
public:
    Segment();
    Segment(NodePoint *startPoint,NodePoint *endPoint);
    ~Segment();

    long getId();
    void setId(long value);

    void addNodePoint(NodePoint *point);
    void addNodePoint(NodePoint *point,long position);

    NodePoint *getNodePoint(long pointId);
    bool removeNodePoint(long pointId);

    bool containNode(long nodeId);

    /*! сортирует узловые точки по расстоянию от начала сегмента*/
    void sortNodesByDistanceFromStart();
    /*! вычисляет расстояние каждой узловой точки от начала сегмента*/
    void calculateDistance();
    /*! вычисляет трангаж  у всех узловых точек в сегменте*/
    void calculateHieghtChane();
    /*! вычисляет долготу пересечения экватора и диреркционный угол*/
    void calculateL0();

    /*! удаляет все узловые точки из сегмента*/
    void clearSegment();

    QString toString();

    NodePoint *getStartPoint();
    void setStartPoint(NodePoint *value);

    NodePoint *getEndPoint();
    void setEndPoint(NodePoint *value);

    QVector<NodePoint *> *getNodes();
    void setNodes(QVector<NodePoint *> *value);

private:
    long id;
    double lenght = -1;

    double L0 =-1; // долгота пересечения экватора
    double K0 = -1; // диррекционный угол

    NodePoint *startPoint;
    NodePoint *endPoint;
    QVector<NodePoint *> *nodes;
};
#endif // SEGMENT_H
