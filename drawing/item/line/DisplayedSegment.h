#ifndef NAMEDLINE_H
#define NAMEDLINE_H

#include <drawing/item/DisplayedItem.h>

#include <drawing/item/point/DisplayedNodePoint.h>

#include <simulation/segment/Segment.h>

class DisplayedSegment : public DisplayedItem{
public:
    DisplayedSegment(DisplayedNodePoint *startPoint,DisplayedNodePoint *endPoint,QPen *pen);
    ~DisplayedSegment();

    void updateCoordinates();

    DisplayedNodePoint *getStartPoint();
    void setStartPoint(DisplayedNodePoint *value);

    DisplayedNodePoint *getEndPoint();
    void setEndPoint(DisplayedNodePoint *value);

    QPointF getCenter();
    void setCenter(QPointF value);

    Segment *parseRealRegment();

    Segment *getRealSegment();
    void setRealSegment(Segment *value);

private:
    QPointF center;
    Segment *realSegment;
    DisplayedNodePoint *startPoint;
    DisplayedNodePoint *endPoint;
};

#endif // NAMEDLINE_H
