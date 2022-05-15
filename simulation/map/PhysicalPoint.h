#ifndef PHYSICALPOINT_H
#define PHYSICALPOINT_H

/*!
    Данные хранятся в радианах!!!!!
*/
class PhysicalPoint{
public:

    PhysicalPoint();
    PhysicalPoint(double latitude,double longitude);
    PhysicalPoint(double latitude,double longitude,double hight);

    double getLongitude();
    double getLatitude();
    double getHight();

    void setLongitude(double longitude);
    void setLatitude(double latitude);
    void setHight(double hight);

private:
    double longitude;
    double latitude;
    double hight;
};

#endif // PHYSICALPOINT_H
