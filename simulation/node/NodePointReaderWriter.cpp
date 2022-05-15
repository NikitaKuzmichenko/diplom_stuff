#include "ClimbNode.h"
#include "CruiseNode.h"
#include "DemNode.h"
#include "DescentNode.h"
#include "FinishNode.h"
#include "ImgNode.h"
#include "MarkerNode.h"
#include "NodePointReaderWriter.h"
#include "TakeoffNode.h"
#include "TurnNode.h"
#include <QList>
#include <QMap>
#include <QString>
#include <QDebug>

NodePointReaderWriter::NodePointReaderWriter(){

    nodeNames = new QMap<QString,NP::NodePointType>;
    nodeNames->insert("CLMB",NP::CLIMB_NODE);
    nodeNames->insert("CRUS",NP::CRUISE_NODE);
    nodeNames->insert("DEM",NP::DEM_NODE);
    nodeNames->insert("DESC",NP::DESCENT_NODE);
    nodeNames->insert("FIN",NP::FINISH_NODE);
    nodeNames->insert("IMG",NP::IMG_NODE);
    nodeNames->insert("MARK",NP::MARKER_NODE);
    nodeNames->insert("TKOF",NP::TAKEOFF_NODE);
    nodeNames->insert("TURN",NP::TURN_NODE);
}

NodePointReaderWriter::~NodePointReaderWriter(){
    delete nodeNames;
}

QString NodePointReaderWriter::convertPointToString(const NodePoint *point){
    QString result;
    switch (point->type) {
        case NP::CLIMB_NODE : {
            ClimbNode *node = (ClimbNode*)point;

            result.append(climmbNode).append(" ");
            result.append(DoubleToString(node->getPoint()->getLongitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getLatitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getHight(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getV(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getNewH(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getTheta(),heightPrecision));

            break;
        }
        case NP::CRUISE_NODE : {
            CruiseNode *node = (CruiseNode*)point;

            result.append(cruiseNode).append(" ");
            result.append(DoubleToString(node->getPoint()->getLongitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getLatitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getHight(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getV(),lowPrecision));

            break;
        }
        case NP::DEM_NODE : {
            DemNode *node = (DemNode*)point;

            result.append(demNode).append(" ");
            result.append(DoubleToString(node->getPoint()->getLongitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getLatitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getHight(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getV(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getAzim(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getLen(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getWidth(),lowPrecision)).append(" ");
            result.append(node->getPath());

            break;
        }
        case NP::DESCENT_NODE : {
            DescentNode *node = (DescentNode*)point;

            result.append(descendNode).append(" ");
            result.append(DoubleToString(node->getPoint()->getLongitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getLatitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getHight(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getV(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getNewH(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getTheta(),heightPrecision));

            break;
        }
        case NP::FINISH_NODE : {
            FinishNode *node = (FinishNode*)point;

            result.append(finishNode).append(" ");
            result.append(DoubleToString(node->getPoint()->getLongitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getLatitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getHight(),lowPrecision));

            break;
        }
        case NP::IMG_NODE : {
            ImgNode *node = (ImgNode*)point;

            result.append(imgNode).append(" ");
            result.append(DoubleToString(node->getPoint()->getLongitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getLatitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getHight(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getV(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getAzim(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getLen(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getWidth(),lowPrecision)).append(" ");
            result.append(node->getPath());

            break;
        }
        case NP::MARKER_NODE : {
            MarkerNode *node = (MarkerNode*)point;

            result.append(markerNode).append(" ");
            result.append(DoubleToString(node->getPoint()->getLongitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getLatitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getHight(),lowPrecision));

            break;
        }
        case NP::TAKEOFF_NODE : {
            TakeoffNode *node = (TakeoffNode*)point;

            result.append(takeoffNode).append(" ");
            result.append(DoubleToString(node->getPoint()->getLongitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getLatitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getHight(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getV(),lowPrecision));

            break;
        }
        case NP::TURN_NODE : {
            TurnNode *node = (TurnNode*)point;

            result.append(turnNode).append(" ");
            result.append(DoubleToString(node->getPoint()->getLongitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getLatitude(),heightPrecision)).append(" ");
            result.append(DoubleToString(node->getPoint()->getHight(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getV(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getR(),lowPrecision)).append(" ");
            result.append(DoubleToString(node->getPsi(),heightPrecision));

            break;
        }
        default:{
            break;
        }
    }

    return result;
}

NodePoint *NodePointReaderWriter::getPointFromString(QString string){
    string = string.simplified();
    QStringList args = string.split(' ');

    if(args.at(name).at(0) == comment){
        return nullptr;
    }

    switch (nodeNames->value(args.at(name))) {
        case NP::CLIMB_NODE : {
            if(args.size() < 7) break;

            return new ClimbNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                             args.at(thetaOrPsi).toDouble(),args.at(speed).toDouble(),args.at(heightOrRadius).toDouble());
        }
        case NP::CRUISE_NODE : {
            if(args.size() < 5) break;

           return new CruiseNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                                args.at(speed).toDouble());
        }
        case NP::DEM_NODE : {
            if(args.size() < 9) break;

            return new DemNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                                 args.at(speed).toDouble(),args.at(azimut).toDouble(),args.at(len).toDouble(),
                                 args.at(with).toDouble(),args.at(filePath));
        }
        case NP::DESCENT_NODE : {
            if(args.size() < 7) break;

            return new DescentNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                             args.at(thetaOrPsi).toDouble(),args.at(speed).toDouble(),args.at(heightOrRadius).toDouble());
        }
        case NP::FINISH_NODE : {
            if(args.size() < 4) break;

            return new FinishNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble());

        }
        case NP::IMG_NODE : {
            if(args.size() < 9) break;

            return new ImgNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                                 args.at(speed).toDouble(),args.at(azimut).toDouble(),args.at(len).toDouble(),
                                 args.at(with).toDouble(),args.at(filePath));
        }
        case NP::MARKER_NODE : {
            if(args.size() < 4) break;

            return new MarkerNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble());

        }
        case NP::TAKEOFF_NODE : {
           if(args.size() < 5) break;

           return new TakeoffNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                                args.at(speed).toDouble());
        }
        case NP::TURN_NODE : {

            if(args.size() < 7) break;
            return new TurnNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                             args.at(heightOrRadius).toDouble(),args.at(speed).toDouble(),args.at(thetaOrPsi).toDouble());
        }
        default:{
            break;
        }
    }
    return nullptr;
}

QString NodePointReaderWriter::DoubleToString(double number, int precision){
    return QString::number(number,'f',precision);
}
