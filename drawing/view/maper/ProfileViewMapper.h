#ifndef PROFILEVIEWMAPPER_H
#define PROFILEVIEWMAPPER_H

#include "ViewMapper.h"

class ProfileViewMapper: public ViewMapper{
public:
    ProfileViewMapper();
    double maxHeight;
    double minHeight;
    double distance;

    void calculateUnitPerPixeRatio();
};

#endif // PROFILEVIEWMAPPER_H
