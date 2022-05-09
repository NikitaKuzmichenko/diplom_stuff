#ifndef NODEPOINTREADERWRITER_H
#define NODEPOINTREADERWRITER_H

#include <QString>
#include "NodePoint.h"

const QString climmbNode = "CLMB";
const QString cruiseNode = "CRUS";
const QString demNode = "DEM";
const QString descendNode = "DESC";
const QString finishNode = "FIN";
const QString imgNode = "IMG";
const QString markerNode = "MARK";
const QString takeoffNode = "TKOF";
const QString turnNode = "TURN";

const QString comment = "#";

const int name = 0;
const int longitude = 1;
const int latitide = 2;
const int height = 3;
const int speed = 4;
const int heightOrRadius = 5;
const int azimut = 5;
const int len = 6;
const int thetaOrPsi = 6;
const int with = 7;
const int filePath = 8;

class NodePointReaderWriter{
public:
    NodePointReaderWriter();
    ~NodePointReaderWriter();

    QString convertPointToString(const NodePoint *point);
    NodePoint *getPointFromString(const QString string);

private:
    QMap<QString,NodePointType> *nodeNames;
};

#endif // NODEPOINTREADERWRITER_H
