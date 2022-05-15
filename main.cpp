#include "test1.h"
#include "test2.h"

#include <QApplication>
#include <QDir>
#include <settings/SettingsManager.h>
#include <simulation/map/ElevationMap.h>
#include <simulation/node/ClimbNode.h>
#include <simulation/node/DemNode.h>
#include <utils/GeodesicUtils.h>
#include <windows/CreateSimulationWindow.h>
#include <windows/SettingsWindow.h>
#include <windows/SimulationWindow.h>
#include <windows/StartWindow.h>

#include <QVector>
#include <QtGui>
#include <windows.h>


int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    SettingsManager *manager = new SettingsManager();
    if(!manager->readSettings()){
         manager->writeSettings();
    }

    StartWindow w;
    w.setManager(manager);
    w.showMaximized();
    return a.exec();

    //======================================= -0.00560264
//    Simulation *sim = new Simulation();
//    sim->simulate();
////    sim->saveToFile();
//    Segment * s = sim->getSegment(10);
//    s->calculateHieghtChane();
//    for(int i=0;i<s->getNodes()->length();i++){
//        GeodesicUtils::isPointOnOrthodromy(
//                    s->getStartPoint()->getPoint(),
//                    s->getEndPoint()->getPoint(),
//                    s->getNodes()->at(i)->getPoint());
//        qInfo() << s->getNodes()->at(i)->toString();
//    }

//=======================================
//    1.43074
//    1.43112
//    1.43074
//    1.43803
//    PhysicalPoint *p1 = new PhysicalPoint(0.960948819,0.533755150);
//    PhysicalPoint *p2 = new PhysicalPoint(0.953398866,0.517798071);
//    PhysicalPoint *p3 = new PhysicalPoint(0.952831991,0.516623405);
//    GeodesicUtils::isPointOnOrthodromy(p1,p3,p2);
//    qInfo() << GeodesicUtils::getDistanceBetweenPoints(p1,p2);
//    test1 *t1 = new test1();
//    test2 *t2 = new test2();
//    QObject::connect(t1,&test1::customSignal,t2,&test2::customeSot);
//    QObject::connect(t1,&test1::customSignal,t2,&test2::customeSot2);
//    t1->emitSignal(10);

    return 0;
}
