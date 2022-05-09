#include "MarkerNode.h"

MarkerNode::MarkerNode() : NodePoint(){
    type = MARKER_NODE;
}

MarkerNode::MarkerNode(PhysicalPoint *point) : NodePoint(point){
    type = MARKER_NODE;
}

MarkerNode::MarkerNode(double longitude, double latitude, double height) : NodePoint(longitude,latitude,height){
    type = MARKER_NODE;
}
