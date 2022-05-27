#include "WayPoint.h"
#include <QMetaEnum>

WayPoint::WayPoint(){
    this->point = new PhysicalPoint();
}

QString WayPoint::genarateDefaultName(){
    this->name = new QString();
    this->name->
            append(QMetaEnum :: fromType <WP::WayPointType>().valueToKeys(type))
            .append(", id = ")
            .append(std::to_string(this->id).c_str());
    return *this->name;
}

QString WayPoint::toString(){
    QString result = QString();
    result.append("{ ");
    result.append("id = "+ QString::number(id)).append(" ");
    result.append("type = "+ QMetaEnum :: fromType <WP::WayPointType>().valueToKeys(type)).append(" ");
    result.append("lat = "+ QString::number(point->getLatitude())).append(" ");
    result.append("long = "+ QString::number(point->getLongitude())).append(" ");
    result.append("hieght = "+ QString::number(point->getHight())).append(" ");
    result.append(" }");
    return result;
}
