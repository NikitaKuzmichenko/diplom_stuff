#ifndef LINECREATOR_H
#define LINECREATOR_H

#include "DisplayedSegment.h"

#include <QPen>


class DisplayedSegmentCreator{

public:
    DisplayedSegmentCreator();
    DisplayedSegment *createSegment(DisplayedNode *startPoint,DisplayedNode *endPoint,long segmentId);

private:

    QPen *defaultPen = new QPen();
};

#endif // LINECREATOR_H
