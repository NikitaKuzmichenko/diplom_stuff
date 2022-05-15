#ifndef WAYPOINTREADERWRITER_H
#define WAYPOINTREADERWRITER_H

#include "WayPoint.h"

#include <qstring.h>

class WayPointReaderWriter{
public:
    WayPointReaderWriter();
    ~WayPointReaderWriter();

    QString convertPointToString(const WayPoint *point);
    WayPoint *getPointFromString(const QString string);

private:
    QMap<QString, WP::WayPointType> *pointNames;
};

#endif // WAYPOINTREADERWRITER_H
