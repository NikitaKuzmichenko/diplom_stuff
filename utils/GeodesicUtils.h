#ifndef GEODESICUTILS_H
#define GEODESICUTILS_H

#include <simulation/map/PhysicalPoint.h>

const double Ra_WGS84    = 6378137.0;           // Большая полуось (экваториальный радиус)
const double f_WGS84     = 1.0/298.257223563;   // Полярное сжатие (отношение разницы полуосей к большой полуоси)
const double Rc_WGS84    = 6356752.3142;        // Малая полуось (полярный радиус)
const double GM_WGS84    = 3.986004418;         // Гравитационная постоянная
const double J2_WGS84    = 1.08263;
const double Omega_WGS84 = 7.292115;            // Угловая скорость вращения Земли

const double Ra_PZ_90    = 6378136.0;           // Большая полуось (экваториальный радиус)
const double f_PZ_90     = 1.0/298.257839303;   // Полярное сжатие (отношение разницы полуосей к большой полуоси)
const double Rc_PZ_90    = Ra_PZ_90 * (1.0 - f_PZ_90); // Малая полуось (полярный радиус)
const double GM_PZ_90    = 3.9860044;           // Гравитационная постоянная
const double J2_PZ_90    = 1.0826257;
const double Omega_PZ_90 = 7.292115;            // Угловая скорость вращения Земли

// Размеры земного эллипсоида по Красовскому
const double Ra_KRASS    = 6378245.000; // Большая полуось (экваториальный радиус)
const double Rc_KRASS    = 6356863.019; // Малая полуось (полярный радиус)
const double Rs_KRASS    = 6371100;     // Средний радиус Земли, принимаемой за шар
const double f_KRASS     = (Ra_KRASS-Rc_KRASS)/Ra_KRASS; // Полярное сжатие (отношение разницы полуосей к большой полуоси)

const double Rs_KAVR     = 6371100;     // Средний радиус Земли, принимаемой за шар согласно Каврайскому

const double Rs          = Rs_KAVR;     // этот радиус используется
const double g           = 9.80665;

class InversGeoProblemSolution{
public:
    double dist;    // в расстояние между двумя точками метрах
    double azim1;   // это начальный курс в десятичных градусах
    double azim2;   // это конечный курс в десятичных градусах
};

class GeodesicUtils{
public:
    static double getDistanceBetweenPoints(PhysicalPoint * p1,PhysicalPoint * p2);
    static double getTurnAngle(PhysicalPoint * start,PhysicalPoint * turn,PhysicalPoint * end);
    static double getAzimuth(PhysicalPoint * start,PhysicalPoint * end);
    static double getPitсh(PhysicalPoint * start,PhysicalPoint * end);
    static bool isPointOnOrthodromy(PhysicalPoint *start,PhysicalPoint *end,PhysicalPoint *point);

    static double toDeg(double rad);
    static double toRad(double deg);
private:
    static InversGeoProblemSolution inversGeopoblem(PhysicalPoint * start,PhysicalPoint * end);
    static double _reduce(double angle);
};

#endif // GEODESICUTILS_H
