#include "UIItemsManager.h"

UIItemsManager::UIItemsManager(QGraphicsView *container,Simulation *simulation){
    this->simulation = simulation;
    nodeInfo = new UINodeInfo(container,simulation);
    segmentInfo = new UISegmentInfo(container,simulation);
    wayPointInfo = new UIWayPointInfo(container,simulation);

    wayPointInfo->hide();
    nodeInfo->hide();
    segmentInfo->hide();
}

void UIItemsManager::nodeWasUpdated(long nodeId){
    if(lastItemId == nodeId && lastType == NODE_ITEM){
        segmentInfo->hide();
        wayPointInfo->hide();
        nodeInfo->show();
        NodePoint * node = simulation->getNode(nodeId);
        nodeInfo->displayNode(node,node->type);
    }
}

void UIItemsManager::segmentWasUpdated(long segmentId){
    if(lastItemId == segmentId && lastType == SEGMENT_ITEM){
        nodeInfo->hide();
        wayPointInfo->hide();
        segmentInfo->show();
        Segment * segment  = simulation->getSegment(segmentId);
        segmentInfo->displayItem(segment);
    }
}

void UIItemsManager::itemSelected(ItemType type, long itemId){
    lastItemId = itemId;
    lastType = type;
    switch (type) {
        case ItemType::NODE_ITEM :{
            segmentInfo->hide();
            wayPointInfo->hide();
            nodeInfo->show();
            NodePoint * node = simulation->getNode(itemId);
            nodeInfo->displayNode(node,node->type);
            break;
        }
        case ItemType::SEGMENT_ITEM :{
            nodeInfo->hide();
            wayPointInfo->hide();
            segmentInfo->show();
            Segment * segment  = simulation->getSegment(itemId);
            segmentInfo->displayItem(segment);
            break;
        }

        case ItemType::WAY_POINT_ITEM :{
            nodeInfo->hide();
            wayPointInfo->show();
            segmentInfo->hide();
            WayPoint *point  = simulation->getWayPoint(itemId);
            wayPointInfo->displayWayPoint(point);
            break;
        }

        default: break;
    }

}
