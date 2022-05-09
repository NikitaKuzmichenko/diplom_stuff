#include "FinishNode.h"

FinishNode::FinishNode() : NodePoint(){
    type = FINISH_NODE;
}

FinishNode::FinishNode(PhysicalPoint *point) : NodePoint(point){
    type = FINISH_NODE;
}

FinishNode::FinishNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height){
    type = FINISH_NODE;
}
