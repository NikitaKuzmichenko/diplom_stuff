#ifndef SEGMENT_H
#define SEGMENT_H

#include <simulation/node/NodePoint.h>


class Segment{
public:
    Segment();
    Segment(NodePoint *startPoint,NodePoint *endPoint);

    NodePoint *getStartPoint();
    void setStartPoint(NodePoint *value);

    NodePoint *getEndPoint();
    void setEndPoint(NodePoint *value);

    long getId();
    void setId(long value);

private:
    long id;
    double lenght = -1;
    NodePoint *startPoint;
    NodePoint *endPoint;

    QVector<NodePoint *> *points;
};

#endif // SEGMENT_H
