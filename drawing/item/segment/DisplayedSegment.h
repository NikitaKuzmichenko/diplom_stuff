#ifndef NAMEDLINE_H
#define NAMEDLINE_H

#include <drawing/item/DisplayedItem.h>
#include <simulation/segment/Segment.h>
#include <drawing/item/node/DisplayedNode.h>

class DisplayedSegment : public DisplayedItem{
public:
    DisplayedSegment(DisplayedNode *startPoint,DisplayedNode *endPoint,QPen *pen);
    ~DisplayedSegment();

    void updateCoordinates();

    bool contain(QPointF point);

    DisplayedNode *getStartPoint();
    void setStartPoint(DisplayedNode *value);

    DisplayedNode *getEndPoint();
    void setEndPoint(DisplayedNode *value);

    QPointF getCenter();
    void setCenter(QPointF value);

    class Segment *parseRealRegment();

    class Segment *getRealSegment();
    void setRealSegment(class Segment *value);

private:
    QPointF center;
    class Segment *realSegment;
    DisplayedNode *startPoint;
    DisplayedNode *endPoint;
};

#endif // NAMEDLINE_H
