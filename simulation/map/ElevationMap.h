#ifndef ELEVATIONMAP_H
#define ELEVATIONMAP_H

#include "PhysicalPoint.h"

#include <QString>

class ElevationMap{
public:
    ElevationMap();
    ~ElevationMap();
    ElevationMap(QString mapPath);

    bool loadMap();

    void setMapPath(QString path);
    QString getMapPath();

    bool addHeightToSinglePoint(PhysicalPoint * point);

    int getRowNumber();
    int getColumnNumer();

    int getUndefinedValue();

    double getMinLongDeg();
    double getMaxLongDeg();

    double getMinLatDeg();
    double getMaxLatDeg();

    double getStepToDegRatio();

private:

    QString mapPath;

    int rowNumber;
    int columnNumber;

    int undefinedValue;

    double minLongDeg;
    double maxLongDeg;

    double minLatDeg;
    double maxLatDeg;

    double stepToDegRatio;

    int **map = nullptr;

    static const int paramsNumber = 6;
};

#endif // ELEVATIONMAP_H
