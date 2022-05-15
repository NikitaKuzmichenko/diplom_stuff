#ifndef DISPLAYEDWAYPOINT_H
#define DISPLAYEDWAYPOINT_H

#include <drawing/item/DisplayedItem.h>

#include <simulation/wayPoint/WayPoint.h>

class DisplayedWayPoint : public DisplayedItem{
public:
    DisplayedWayPoint(QGraphicsItem *displayedItem,WayPoint *wayPoint,QPointF position);
    ~DisplayedWayPoint();

    void createDescription();

    QPointF getPosition();
    void setPosition(QPointF value);

    WayPoint *getWayPoint();
    void setWayPoint(WayPoint *value);

private:
    QPointF position;
    WayPoint *wayPoint = nullptr;
};

#endif // DISPLAYEDWAYPOINT_H
