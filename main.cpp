#include <QApplication>
#include <QDir>
#include <settings/SettingsManager.h>
#include <simulation/map/ElevationMap.h>
#include <simulation/node/NodePointReaderWriter.h>
#include <windows/CreateSimulationWindow.h>
#include <windows/SettingsWindow.h>
#include <windows/SimulationWindow.h>
#include <windows/StartWindow.h>

#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SettingsManager *manager = new SettingsManager();
    if(!manager->readSettings()){
         manager->writeSettings();
    }

    StartWindow w;
    w.setManager(manager);
    w.showMaximized();
    return a.exec();


//    QFile file("C:\\Users\\nikit\\OneDrive\\Рабочий стол\\route.flip");
//    file.open(QIODevice::ReadOnly);
//    if(!file.isOpen()){
//        return false;
//    }
//    QTextStream out(&file);
//    //out.readLine();

//    NodePointReaderWriter *r = new NodePointReaderWriter();

//    while(!out.atEnd()){
//        QString str = out.readLine();
//        NodePoint *point = r->getPointFromString(str);
//    }

    return 0;
}
