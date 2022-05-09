#ifndef NAMEDPOINT_H
#define NAMEDPOINT_H

#include <drawing/item/DisplayedItem.h>

#include <simulation/node/NodePoint.h>

class DisplayedNodePoint : public DisplayedItem{
public:

    DisplayedNodePoint(QGraphicsItem *displayedItem,NodePoint *node,QPointF position);
    ~DisplayedNodePoint();

    void moveBy(double dx,double dy);

    void createDescription();

    bool getRemovable();
    void setRemovable(bool value);

    NodePoint *getNode();
    void setNode(NodePoint *value);

    QPointF getPosition();
    void setPosition(QPointF value);

private:
    QPointF position;
    NodePoint *node = nullptr;
};

#endif // NAMEDPOINT_H
