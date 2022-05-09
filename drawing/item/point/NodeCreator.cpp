#include "NodeCreator.h"


NodeCreator::NodeCreator(){}

DisplayedNodePoint *NodeCreator::ceratePoint(NodePoint *node,QPointF position){

    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(position.x() - 3,position.y() - 3,6,6);
    circle->setPen(*defaultPen);
    circle->setBrush(*defaultBrush);

    DisplayedNodePoint *displayedNode = new DisplayedNodePoint(circle,node,position);

    QString name;
    name.append("P");
    displayedNode->setName(name);

    return displayedNode;
}


