#include "DisplayedSegmentCreator.h"


DisplayedSegmentCreator::DisplayedSegmentCreator(){
    defaultPen->setWidth(2);
}

DisplayedSegment *DisplayedSegmentCreator::createSegment(DisplayedNode *startPoint, DisplayedNode *endPoint,long segmentId){
    DisplayedSegment *segment = new DisplayedSegment(startPoint, endPoint,defaultPen);
    segment->setId(segmentId);
    return segment;
}
