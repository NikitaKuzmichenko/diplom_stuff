#ifndef LINECREATOR_H
#define LINECREATOR_H

#include "DisplayedSegment.h"

#include <QPen>


class SegmentCreator{

public:
    SegmentCreator();
    DisplayedSegment *createSegment(DisplayedNodePoint *startPoint,DisplayedNodePoint *endPoint);

private:

    QPen *defaultPen = new QPen();
};

#endif // LINECREATOR_H
