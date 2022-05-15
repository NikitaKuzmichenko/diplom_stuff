#include "WayPoint.h"
#include <QMetaEnum>

WayPoint::WayPoint(){
    this->point = new PhysicalPoint();
}

QString WayPoint::genarateDefaultName(){
    this->name = new QString();
    this->name->append("way point №").append(std::to_string(this->id).c_str());
    return *this->name;
}

QString WayPoint::toString(){
    QMetaEnum m = QMetaEnum :: fromType <WP::WayPointType>();
    QString result = QString();
    result.append("{ ");
    result.append("id = "+ QString::number(id)).append(" ");
    result.append("type = "+ m.valueToKeys(type)).append(" ");
    result.append("lat = "+ QString::number(point->getLatitude())).append(" ");
    result.append("long = "+ QString::number(point->getLongitude())).append(" ");
    result.append("hieght = "+ QString::number(point->getHight())).append(" ");
    result.append(" }");
    return result;
}
