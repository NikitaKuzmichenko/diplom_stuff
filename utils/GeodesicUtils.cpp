#include "GeodesicUtils.h"
#include <math.h>
#include "QDebug"

// возвращает значение в радианах
double GeodesicUtils::getDistanceBetweenPoints(PhysicalPoint *p1, PhysicalPoint *p2){
    double distance = inversGeopoblem(p1,p2).dist;
    if(distance < 0){
        distance*=-1;
    }
    return distance;
}

// возвращает значение в радианах
double GeodesicUtils::getTurnAngle(PhysicalPoint *start, PhysicalPoint *turn, PhysicalPoint *end){
    double inAngle = inversGeopoblem(start,turn).azim2;
    double outAngle = inversGeopoblem(turn,end).azim1;
    return outAngle - inAngle;
}

// возвращает значение в радианах
double GeodesicUtils::getAzimuth(PhysicalPoint *start, PhysicalPoint *end){
    return inversGeopoblem(start,end).azim1;
}

// возвращает значение в радианах
double GeodesicUtils::getPitсh(PhysicalPoint *start, PhysicalPoint *end){
    double distance = getDistanceBetweenPoints(start,end);
    double hieghtDiff = end->getHight() - start->getHight();
    if(hieghtDiff < 0){
        hieghtDiff*=-1;
        return atan2(hieghtDiff,distance)*-1;
    }else{
        return atan2(hieghtDiff,distance);
    }
}

// tg($lat) = sin($long - L0)*tg(p/2 - A0)
// tg(A0) = tg(p/2 - start_lat)*sin(start_lat - L0)
// L0 = D_L - atan(tg(D_L)*sin(start_lat + end_lat)/sin(end_lat - start_lat))
// D_L = (end_long - start_logn)/2
bool GeodesicUtils::isPointOnOrthodromy(PhysicalPoint *start, PhysicalPoint *end, PhysicalPoint *point){
    double startlLong = start->getLongitude();
    double startlLat = start->getLatitude();
    double endlLong = end->getLongitude();
    double endLat = end->getLatitude();

    double D_L = (endlLong - startlLong)/2;
    double f = tan(D_L);
    double f1 = sin(startlLat + endLat);
    double f2 = sin(endLat - startlLat);
    double L0;

    if(f2 == 0){
         L0 = D_L - M_PI_2;
    }else{
         L0 = D_L - atan(f*f1/f2);
    }

    double A0 = atan(tan(M_PI_2 - startlLat)*sin(startlLong - L0));
    double difference = atan(sin(point->getLongitude() - L0) * tan(M_PI_2 - A0)) - point->getLatitude();
    return difference < maxDelta && difference > maxDelta*(-1);
            
//    qInfo() << tan(point->getLatitude());
//    qInfo() << sin(point->getLongitude() - L0) * tan(M_PI_2 - A0);
}

InversGeoProblemSolution GeodesicUtils::inversGeopoblem(PhysicalPoint *start, PhysicalPoint *end){
    double lat1 = start->getLatitude();
    double lat2 = end->getLatitude();
    double delta_lon = _reduce(start->getLongitude() - end->getLongitude());

    InversGeoProblemSolution sol = InversGeoProblemSolution();
    // разные частные случаи
    // -----------------------------------------
    // если точки на одном меридиане
    // -----------------------------------------
    if (delta_lon == 0) {
        if (lat1 < lat2) {          // на север
            sol.azim2 = sol.azim1 = 0.0;
            sol.dist  = Rs*(lat2 - lat1);
        } else if (lat1 > lat2) {   // на юг
            sol.azim2 = sol.azim1 = M_PI;
            sol.dist  = Rs*(lat1 - lat2);
        } else { // точки совпали
            sol.azim1 = NAN;
            sol.azim2 = NAN;
            sol.dist  = 0.0;
        }
        return sol;
    }

    // -----------------------------------------
    // меридианы различны
    // -----------------------------------------
    double sinlon  = sin(delta_lon);
    double coslon  = cos(delta_lon);

    double p     = 0.0;
    double q     = 0.0;
    double sigma = 0.0;
    // -----------------------------------------
    // точки на одной параллели
    // -----------------------------------------
    if (lat1 == lat2) {
        double lat    = lat1;
        double sinlat = sin(lat);
        double coslat = cos(lat);
        // если на экваторе
        if (lat == 0) {
            if (delta_lon > 0.0) {  // на восток
                sol.azim2 = sol.azim1 = M_PI_2;
            } else {                // на запад
                sol.azim2 = sol.azim1 = M_PI + M_PI_2;
            }
            sol.dist = fabs(Rs*delta_lon);
            return sol;
        }
        double azim = atan2(sinlon, sinlat*(1 - coslon));
        double sinazim = sin(azim);
        double cosazim = cos(azim);
        p = coslat*(sinazim*sinlon + cosazim*sinlat*(1.0 - coslon));
        q = sinlat*sinlat + coslat*coslat*coslon; // это косинус сигмы
        sigma = atan2(p, q);
        sol.azim1 = _reduce(azim);
        sol.azim2 = _reduce(M_PI - azim);
        sol.dist  = Rs*sigma;
        return sol;
    }

    // -----------------------------------------
    // случай общего положения
    // -----------------------------------------
    double coslat1 = cos(lat1);
    double coslat2 = cos(lat2);
    double sinlat1 = sin(lat1);
    double sinlat2 = sin(lat2);
    double p1 = 0.0;
    double q1 = 0.0;
    double p2 = 0.0;
    double q2 = 0.0;
    p1 = sinlon*coslat2;
    q1 = coslat1*sinlat2 - sinlat1*coslat2*coslon;
    p2 = sinlon*coslat1;
    q2 = coslat2*sinlat1 - coslat1*sinlat2*coslon;

    double azim1 = atan2(p1, q1);           // по направлению сегмента, а не ортодромии
    double azim2 = atan2(-p2, q2) + M_PI;   // по направлению сегмента, а не ортодромии
    double cossigma = sinlat1*sinlat2 + coslat1*coslat2*coslon;
    double sinsigma = p1*sin(azim1) + q1*cos(azim1);
    sol.dist  = Rs*atan2(sinsigma, cossigma);
    sol.azim1 = _reduce(azim1); // в радианах
    sol.azim2 = _reduce(azim2); // в радианах

    return sol;
}

PhysicalPoint* GeodesicUtils::directGeopoblem(PhysicalPoint *start, double azim, double dist){
    double lat = start->getLatitude();
    azim = _reduce(azim);       // должен лежать в диапазоне [0.0 -- 360.0)
    dist = _reduce(dist/Rs);    // приведем дистанцию вдоль ортодромии к углу \sigma [0.0 -- 360.0)

    PhysicalPoint *result = new PhysicalPoint();
    result->setHight(start->getHight());
    result->setLatitude(start->getLatitude());
    result->setLongitude(start->getLongitude());

    // Если расстояние равно нулю, возвращаем копию исходной точки
    if (dist == 0.0) {
        return result;
    }

    // частные случаи
    if (azim == 0) {
        // вдоль меридиана на север
        result->setLatitude(_reduce(start->getLatitude() + dist));
        return result;
    }
    if (M_PI == azim) {
        // вдоль меридиана на юг
        result->setLatitude(_reduce(start->getLatitude() - dist));
        return result;
    }

    // случай общего положения
    double coslat = cos(lat);
    double sinlat = sin(lat);

    double sindist = sin(dist);
    double cosdist = cos(dist);

    double sinazim = sin(azim);
    double cosazim = cos(azim);

    // Вычисляем разность долгот
    double p = sindist*sinazim;
    double q = coslat*cosdist - sinlat*sindist*cosazim;
    double lambda = _reduce(atan2(p, q));
    // Вычисляем обратный азимут второй точки
    p = -coslat*sinazim;
    q = sinlat*sindist - coslat*cosdist*cosazim;
    double azim2 = _reduce(atan2(p, q));
    // теперь широта второй точки
    p = sinlat*cosdist + coslat*sindist*cosazim;
    q = -coslat*sinazim/sin(azim2);
    double lat2 = atan2(p, q);

    result->setLongitude(_reduce(start->getLongitude() + lambda));
    result->setLatitude(lat2);
    return result;
}

double GeodesicUtils::_reduce(double angle){
    while (angle < 0.0) {
        angle += 2.0 * M_PI;
    }
    while (angle >= 2.0 * M_PI) {
        angle -= 2.0 * M_PI;
    }
    return(angle);
}

double GeodesicUtils::toDeg(double rad){
    return rad*180/M_PI;
}

double GeodesicUtils::toRad(double deg){
    return deg*M_PI/180;
}
