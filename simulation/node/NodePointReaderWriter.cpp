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

    nodeNames = new QMap<QString,NodePointType>;
    nodeNames->insert(climmbNode,NodePointType::CLIMB_NODE);
    nodeNames->insert(cruiseNode,NodePointType::CRUISE_NODE);
    nodeNames->insert(demNode,NodePointType::DEM_NODE);
    nodeNames->insert(descendNode,NodePointType::DESCENT_NODE);
    nodeNames->insert(finishNode,NodePointType::FINISH_NODE);
    nodeNames->insert(imgNode,NodePointType::IMG_NODE);
    nodeNames->insert(markerNode,NodePointType::MARKER_NODE);
    nodeNames->insert(takeoffNode,NodePointType::TAKEOFF_NODE);
    nodeNames->insert(turnNode,NodePointType::TURN_NODE);
}

NodePointReaderWriter::~NodePointReaderWriter(){
    delete nodeNames;
}

QString NodePointReaderWriter::convertPointToString(const NodePoint *point){
    QString result;

    switch (point->type) {
        case CLIMB_NODE : {
            ClimbNode *node = (ClimbNode*)point;

            result.append(climmbNode).append(" ");
            result.append(QString::number(node->getPoint()->getLongitude())).append(" ");
            result.append(QString::number(node->getPoint()->getLatitude())).append(" ");
            result.append(QString::number(node->getPoint()->getHight())).append(" ");
            result.append(QString::number(node->getV())).append(" ");
            result.append(QString::number(node->getNewH())).append(" ");
            result.append(QString::number(node->getTheta()));

            break;
        }
        case CRUISE_NODE : {
            CruiseNode *node = (CruiseNode*)point;

            result.append(cruiseNode).append(" ");
            result.append(QString::number(node->getPoint()->getLongitude())).append(" ");
            result.append(QString::number(node->getPoint()->getLatitude())).append(" ");
            result.append(QString::number(node->getPoint()->getHight())).append(" ");
            result.append(QString::number(node->getV()));

            break;
        }
        case DEM_NODE : {
            DemNode *node = (DemNode*)point;

            result.append(demNode).append(" ");
            result.append(QString::number(node->getPoint()->getLongitude())).append(" ");
            result.append(QString::number(node->getPoint()->getLatitude())).append(" ");
            result.append(QString::number(node->getPoint()->getHight())).append(" ");
            result.append(QString::number(node->getV())).append(" ");
            result.append(QString::number(node->getAzim())).append(" ");
            result.append(QString::number(node->getLen())).append(" ");
            result.append(QString::number(node->getWidth())).append(" ");
            result.append(node->getPath());

            break;
        }
        case DESCENT_NODE : {
            DescentNode *node = (DescentNode*)point;

            result.append(descendNode).append(" ");
            result.append(QString::number(node->getPoint()->getLongitude())).append(" ");
            result.append(QString::number(node->getPoint()->getLatitude())).append(" ");
            result.append(QString::number(node->getPoint()->getHight())).append(" ");
            result.append(QString::number(node->getV())).append(" ");
            result.append(QString::number(node->getNewH())).append(" ");
            result.append(QString::number(node->getTheta()));

            break;
        }
        case FINISH_NODE : {
            FinishNode *node = (FinishNode*)point;

            result.append(finishNode).append(" ");
            result.append(QString::number(node->getPoint()->getLongitude())).append(" ");
            result.append(QString::number(node->getPoint()->getLatitude())).append(" ");
            result.append(QString::number(node->getPoint()->getHight()));

            break;
        }
        case IMG_NODE : {
            ImgNode *node = (ImgNode*)point;

            result.append(imgNode).append(" ");
            result.append(QString::number(node->getPoint()->getLongitude())).append(" ");
            result.append(QString::number(node->getPoint()->getLatitude())).append(" ");
            result.append(QString::number(node->getPoint()->getHight())).append(" ");
            result.append(QString::number(node->getV())).append(" ");
            result.append(QString::number(node->getAzim())).append(" ");
            result.append(QString::number(node->getLen())).append(" ");
            result.append(QString::number(node->getWidth())).append(" ");
            result.append(node->getPath());

            break;
        }
        case MARKER_NODE : {
            MarkerNode *node = (MarkerNode*)point;

            result.append(markerNode).append(" ");
            result.append(QString::number(node->getPoint()->getLongitude())).append(" ");
            result.append(QString::number(node->getPoint()->getLatitude())).append(" ");
            result.append(QString::number(node->getPoint()->getHight()));

            break;
        }
        case TAKEOFF_NODE : {
            TakeoffNode *node = (TakeoffNode*)point;

            result.append(takeoffNode).append(" ");
            result.append(QString::number(node->getPoint()->getLongitude())).append(" ");
            result.append(QString::number(node->getPoint()->getLatitude())).append(" ");
            result.append(QString::number(node->getPoint()->getHight())).append(" ");
            result.append(QString::number(node->getV()));

            break;
        }
        case TURN_NODE : {
            TurnNode *node = (TurnNode*)point;

            result.append(turnNode).append(" ");
            result.append(QString::number(node->getPoint()->getLongitude())).append(" ");
            result.append(QString::number(node->getPoint()->getLatitude())).append(" ");
            result.append(QString::number(node->getPoint()->getHight())).append(" ");
            result.append(QString::number(node->getV())).append(" ");
            result.append(QString::number(node->getR())).append(" ");
            result.append(QString::number(node->getPsi()));

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
        case CLIMB_NODE : {
            if(args.size() < 7) break;

            return new ClimbNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                             args.at(thetaOrPsi).toDouble(),args.at(speed).toDouble(),args.at(heightOrRadius).toDouble());
            break;
        }
        case CRUISE_NODE : {
            if(args.size() < 5) break;

           return new CruiseNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                                args.at(speed).toDouble());
            break;
        }
        case DEM_NODE : {
            if(args.size() < 9) break;

            return new DemNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                                 args.at(speed).toDouble(),args.at(azimut).toDouble(),args.at(len).toDouble(),
                                 args.at(with).toDouble(),args.at(filePath));
            break;
        }
        case DESCENT_NODE : {
            if(args.size() < 7) break;

            return new DescentNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                             args.at(thetaOrPsi).toDouble(),args.at(speed).toDouble(),args.at(heightOrRadius).toDouble());
            break;
        }
        case FINISH_NODE : {
            if(args.size() < 4) break;

            return new FinishNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble());

            break;
        }
        case IMG_NODE : {
            if(args.size() < 9) break;

            return new ImgNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                                 args.at(speed).toDouble(),args.at(azimut).toDouble(),args.at(len).toDouble(),
                                 args.at(with).toDouble(),args.at(filePath));
            break;
        }
        case MARKER_NODE : {
            if(args.size() < 4) break;

            return new MarkerNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble());

            break;
        }
        case TAKEOFF_NODE : {
           if(args.size() < 5) break;

           return new TakeoffNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                                args.at(speed).toDouble());
            break;
        }
        case TURN_NODE : {

            if(args.size() < 7) break;

            return new TurnNode(args.at(longitude).toDouble(),args.at(latitide).toDouble(),args.at(height).toDouble(),
                             args.at(heightOrRadius).toDouble(),args.at(speed).toDouble(),args.at(thetaOrPsi).toDouble());
            break;
        }
        default:{
            break;
        }
    }
    return nullptr;
}
