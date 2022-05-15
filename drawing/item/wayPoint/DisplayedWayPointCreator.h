#ifndef DISPLAYEDWAYPOINTCREATOR_H
#define DISPLAYEDWAYPOINTCREATOR_H

#include "DisplayedWayPoint.h"
#include <QPen>

class DisplayedWayPointCreator{
public:
    DisplayedWayPointCreator();
    DisplayedWayPoint *ceratePoint(WayPoint *node,QPointF position);
private :
    QPen *defaultPen = new QPen();
    QBrush *defaultBrush = new QBrush(Qt::SolidPattern);
};

#endif // DISPLAYEDWAYPOINTCREATOR_H
