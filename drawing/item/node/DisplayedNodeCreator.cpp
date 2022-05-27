#include "DisplayedNodeCreator.h"
#include <QGraphicsPixmapItem>
#include <QMetaEnum>

DisplayedNodeCreator::DisplayedNodeCreator(){}

DisplayedNode *DisplayedNodeCreator::ceratePoint(NodePoint *node,QPointF position){

    QGraphicsEllipseItem *circle = new QGraphicsEllipseItem(position.x() - 3,position.y() - 3,6,6);
    circle->setPen(*defaultPen);
    circle->setBrush(*defaultBrush);

    DisplayedNode *displayedNode = new DisplayedNode(circle,node,position);

    QString name = QString(QMetaEnum::fromType<NP::NodePointType>().valueToKey((node->type)));
    name=name.left(name.lastIndexOf('_'));
    displayedNode->setName(name);
    displayedNode->setId(node->getId());
    displayedNode->setNode(node);

    return displayedNode;
}
