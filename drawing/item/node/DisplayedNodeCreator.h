#ifndef DISPLAYEDNODECREATOR_H
#define DISPLAYEDNODECREATOR_H

#include "DisplayedNode.h"
#include <QPen>
#include <simulation/node/NodePoint.h>

class DisplayedNodeCreator{
public:
    DisplayedNodeCreator();
    DisplayedNode *ceratePoint(NodePoint *node,QPointF position);

private :
    QPen *defaultPen = new QPen();
    QBrush *defaultBrush = new QBrush(Qt::SolidPattern);
};

#endif // DISPLAYEDNODECREATOR_H
