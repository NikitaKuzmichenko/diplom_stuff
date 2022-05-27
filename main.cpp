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

#include <QApplication>
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
}
