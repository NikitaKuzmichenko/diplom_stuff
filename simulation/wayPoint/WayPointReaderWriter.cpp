#include "WayPointReadeRwriter.h"
#include <QMap>

WayPointReaderWriter::WayPointReaderWriter(){
    pointNames = new QMap<QString,WP::WayPointType>;

    pointNames->insert("NMARK",WP::MARKER_POINT);
    pointNames->insert("TKOFF",WP::TAKEOFF_POINT);
    pointNames->insert("CRUIS",WP::CRUISE_POINT);
    pointNames->insert("TURN", WP::TURN_POINT);
    pointNames->insert("CLIMB",WP::CLIMB_POINT);
    pointNames->insert("DSCNT",WP::DESCENT_POINT);
    pointNames->insert("DEM",  WP::DEM_POINT);
    pointNames->insert("IMG",  WP::IMG_POINT);
    pointNames->insert("FINIS",WP::FINISH_POINT);

    pointNames->insert("ACCEL",WP::ACCEL_START);

    pointNames->insert("TURNS",WP::TURN_START);
    pointNames->insert("TURNF",WP::TURN_FINISH);

    pointNames->insert("ORTHO",WP::SWITCH_ORTHODROMY);

    pointNames->insert("CLM_S",WP::CLIMB_START);
    pointNames->insert("CLM_F",WP::CLIMB_FINISH);

    pointNames->insert("DSC_S",WP::DESCENT_START);
    pointNames->insert("DSC_F",WP::DESCENT_FINISH);

    pointNames->insert("DCR_S",WP::DESCENT_CLIMB_START);
    pointNames->insert("DCR_F",WP::DESCENT_CLIMB_FINISH);

    pointNames->insert("CDL_S",WP::CLIMB_DESCENT_START);
    pointNames->insert("CDL_F",WP::CLIMB_DESCENT_FINISH);

    pointNames->insert("CCR_S",WP::CLIMB_CLIMB_RAISE_START);
    pointNames->insert("CCR_F",WP::CLIMB_CLIMB_RAISE_FINISH);

    pointNames->insert("CCL_S",WP::CLIMB_CLIMB_LOWER_START);
    pointNames->insert("CCL_F",WP::CLIMB_CLIMB_LOWER_FINISH);

    pointNames->insert("DDR_S",WP::DESCENT_DESCENT_RAISE_START);
    pointNames->insert("DDR_F",WP::DESCENT_DESCENT_RAISE_FINISH);

    pointNames->insert("DDL_S",WP::DESCENT_DESCENT_LOWER_START);
    pointNames->insert("DDL_F",WP::DESCENT_DESCENT_LOWER_FINISH);

    pointNames->insert("HDL_S",WP::CRUISE_DESCENT_START);
    pointNames->insert("HDL_F",WP::CRUISE_DESCENT_FINISH);

    pointNames->insert("HCR_S",WP::CRUISE_CLIMB_START);
    pointNames->insert("HCR_F",WP::CRUISE_CLIMB_FINISH);

    pointNames->insert("DHR_S",WP::DESCENT_CRUISE_START);
    pointNames->insert("DHR_F",WP::DESCENT_CRUISE_FINISH);

    pointNames->insert("CHL_S",WP::CLIMB_CRUISE_START);
    pointNames->insert("CHL_F",WP::CLIMB_CRUISE_FINISH);

    pointNames->insert("DEM_S",WP::DEM_START);
    pointNames->insert("DEM_F",WP::DEM_FINISH);

    pointNames->insert("IMG_S",WP::IMG_START);
    pointNames->insert("IMG_F",WP::IMG_FINISH);
}

WayPointReaderWriter::~WayPointReaderWriter(){
    delete pointNames;
}

WayPoint *WayPointReaderWriter::getPointFromString(QString string){
    string = string.simplified();
    QStringList args = string.split(' ');

    if(args.length() < 14){
        return nullptr;
    }

    WayPoint *point = new WayPoint();
    point->type = pointNames->value(args.at(0));
    // ignore id
    point->dist = args.at(2).toDouble();
    point->point->setLongitude(args.at(3).toDouble());
    point->point->setLatitude(args.at(4).toDouble());
    point->point->setHight(args.at(5).toDouble());
    point->h2 = args.at(6).toDouble();
    point->V = args.at(7).toDouble();
    point->Theta = args.at(8).toDouble();
    point->Psi = args.at(9).toDouble();
    point->gamma = args.at(10).toDouble();
    point->aileron = args.at(11).toDouble();
    point->alpha = args.at(12).toDouble();
    point->interceptor = args.at(13).toInt();
    point->thrust = args.at(14).toDouble();

    return point;
}
