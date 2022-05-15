#include "MarkerNode.h"

MarkerNode::MarkerNode() : NodePoint(){
    type = NP::MARKER_NODE;
}

MarkerNode::MarkerNode(PhysicalPoint *point) : NodePoint(point){
    type = NP::MARKER_NODE;
}

MarkerNode::MarkerNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height){
    type = NP::MARKER_NODE;
}
