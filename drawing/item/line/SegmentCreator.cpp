#include "SegmentCreator.h"

SegmentCreator::SegmentCreator(){
    defaultPen->setWidth(2);
}

DisplayedSegment *SegmentCreator::createSegment(DisplayedNodePoint *startPoint, DisplayedNodePoint *endPoint){
    DisplayedSegment *line = new DisplayedSegment(startPoint, endPoint,defaultPen);
    line->parseRealRegment();
    return line;
}
