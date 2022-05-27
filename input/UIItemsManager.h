#ifndef UIITEMSMANAGET_H
#define UIITEMSMANAGET_H

#include "UINodeInfo.h"
#include "UISegmentInfo.h"
#include "UIWayPointInfo.h"

#include <QObject>
#include <drawing/item/DisplayedItem.h>
#include <simulation/Simulation.h>

class UIItemsManager : public QObject{
    Q_OBJECT
public:
    UIItemsManager(QGraphicsView *container,Simulation *simulation);

public slots :
    void nodeWasUpdated(long nodeId);
    void segmentWasUpdated(long segmentId);
    void itemSelected(ItemType type,long itemId);
private:
    ItemType lastType = ItemType::UNDEFINED;
    long lastItemId = -1;

    Simulation *simulation;
    UINodeInfo *nodeInfo;
    UISegmentInfo *segmentInfo;
    UIWayPointInfo *wayPointInfo;
};

#endif // UIITEMSMANAGET_H
