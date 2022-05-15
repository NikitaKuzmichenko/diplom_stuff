#include "DisplayedWayPointCreator.h"

DisplayedWayPointCreator::DisplayedWayPointCreator(){}

DisplayedWayPoint *DisplayedWayPointCreator::ceratePoint(WayPoint *node,QPointF position){

    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(position.x() - 3,position.y() - 3,6,6);
    circle->setPen(*defaultPen);
    circle->setBrush(*defaultBrush);

    DisplayedWayPoint *displayedNode = new DisplayedWayPoint(circle,node,position);

    QString name;
    name.append("P");
    displayedNode->setName(name);

    return displayedNode;
}
