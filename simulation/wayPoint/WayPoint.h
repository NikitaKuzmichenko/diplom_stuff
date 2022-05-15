#ifndef WAYPOINT_H
#define WAYPOINT_H

#include <QString>
#include <simulation/map/PhysicalPoint.h>
#include <simulation/wayPoint/WayPointType.h>

class WayPoint{
public:
    WayPoint();
    QString genarateDefaultName();
    QString toString();

    QString *name = nullptr; // отображаемое название точки
    //Segment *segment = nullptr; // указатель на сегмент, к которму приндлежит путевыя точка
    WP::WayPointType type; // тип путевой точки

    PhysicalPoint *point; // широта, долгота, высота точки
    long    id = 0;
    double  dist;   // расстояние в плане от "начала" ортодромии на уровне базового узла (node_s)
    double  h2;     // высота следующей точки
    double  V;      // скорость прохождения
    double  Theta;  // наклон траектории
    double  Psi;
    double  gamma;          // крен, с которым выполняется разворот
    double  aileron;        // отклонение элеронов для входа/выхода в/из разворота
    double  alpha;          // угол атаки
    int     interceptor;    // состояние интерцептора
    double  thrust;         // тяга
};

#endif // WAYPOINT_H
