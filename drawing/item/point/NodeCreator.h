#ifndef POINTCREATOR_H
#define POINTCREATOR_H

#include "DisplayedNodePoint.h"

#include <QPen>



class NodeCreator{
public:
    NodeCreator();
    DisplayedNodePoint *ceratePoint(NodePoint *node,QPointF position);

private :
    QPen *defaultPen = new QPen();
    QBrush *defaultBrush = new QBrush(Qt::SolidPattern);
};

#endif // POINTCREATOR_H
