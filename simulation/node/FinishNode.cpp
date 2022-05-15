#include "FinishNode.h"

FinishNode::FinishNode() : NodePoint(){
    type = NP::FINISH_NODE;
}

FinishNode::FinishNode(PhysicalPoint *point) : NodePoint(point){
    type = NP::FINISH_NODE;
}

FinishNode::FinishNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height){
    type = NP::FINISH_NODE;
}
