#ifndef DISPLAYEDNODE_H
#define DISPLAYEDNODE_H

#include <drawing/item/DisplayedItem.h>
#include <simulation/node/NodePoint.h>

class DisplayedNode : public DisplayedItem{
public:
    DisplayedNode(QGraphicsItem *displayedItem,NodePoint *node,QPointF position);
    ~DisplayedNode();

    void moveBy(double dx,double dy);
    void moveTo(QPointF position);
    void createDescription();

    NodePoint *getNode();
    void setNode(NodePoint *value);

    QPointF getPosition();
    void setPosition(QPointF value);
private:
    QString formatName();
    QPointF position;
    NodePoint *node = nullptr;
};

#endif // DISPLAYEDNODE_H
