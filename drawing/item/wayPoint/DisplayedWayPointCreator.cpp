#include "DisplayedWayPointCreator.h"
#include <QMetaEnum>

DisplayedWayPointCreator::DisplayedWayPointCreator(){}

DisplayedWayPoint *DisplayedWayPointCreator::ceratePoint(WayPoint *node,QPointF position){

    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(position.x() - 1.5,position.y() - 1.5,3,3);
    defaultPen->setColor("Red");
    defaultBrush->setColor("Red");
    circle->setPen(*defaultPen);
    circle->setBrush(*defaultBrush);

    DisplayedWayPoint *displayedNode = new DisplayedWayPoint(circle,node,position);

    QString name = QString(QMetaEnum::fromType<WP::WayPointType>().valueToKey((node->type)));
    displayedNode->setName(name);
    displayedNode->setId(node->id);

    return displayedNode;
}
