#include "DisplayedSegmentCreator.h"


DisplayedSegmentCreator::DisplayedSegmentCreator(){
    defaultPen->setWidth(2);
}

DisplayedSegment *DisplayedSegmentCreator::createSegment(DisplayedNode *startPoint, DisplayedNode *endPoint){
    DisplayedSegment *line = new DisplayedSegment(startPoint, endPoint,defaultPen);
    line->parseRealRegment();
    return line;
}
