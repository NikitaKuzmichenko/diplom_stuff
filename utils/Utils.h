#ifndef UTILS_H
#define UTILS_H

#include <QString>

class Utils{
public:
    static void roundUp(double &number, int precision);

    static void fromUTMToGK(double lon,double lat,QString &xAndZone,QString &y);
};

#endif // UTILS_H
