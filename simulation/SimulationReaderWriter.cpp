#include "SimulationReaderWriter.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QTextStream>
#include <QVector>

SimulationReaderWriter::SimulationReaderWriter(){
    this->nodepointReaderWriter = new NodePointReaderWriter();
    this->wayPointReader = new WayPointReaderWriter();

    QString baseFolderName = QDir::currentPath() + "/flip";

    exePath = baseFolderName + "/flip.exe";
    configPath = baseFolderName + "/missile.conf";
    detailsPath =  baseFolderName + "/details.flip";
    programPath =  baseFolderName + "/program.flip";
    logPath = baseFolderName + "/flip.log.flip";
    routePath = baseFolderName + "/route2.flip";
    errorPath = baseFolderName + "/error.flip";
    tempPath = baseFolderName + "/tempRoute.flip";

    outputPath = baseFolderName + genaratOutFileName(baseFolderName);
}

SimulationReaderWriter::~SimulationReaderWriter(){
    delete this->nodepointReaderWriter;
    delete this->wayPointReader;
}

QList<NodePoint *>* SimulationReaderWriter::getNodePoints(long& id){

    QFile file(routePath);
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen()){
        return nullptr;
    }
    QTextStream out(&file);
    QList<NodePoint *> *result =new QList<NodePoint *>();

    while(!out.atEnd()){
        QString str = out.readLine();
        NodePoint *point = nodepointReaderWriter->getPointFromString(str);
        if(point != nullptr){
            point->setId(id);
            id++;
            result->append(point);
        }
    }

    return result;
}

QList<WayPoint *> *SimulationReaderWriter::getWayPoints(long& id){
    QString start = "TKOFF";
    QString end = "FINIS";
    QString segmentDivider = "";

    bool startEncountered = false;
    bool finishEncountered = false;

    QFile file(logPath);
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen()){
        return nullptr;
    }
    QTextStream out(&file);

    QList<WayPoint *> *result =new  QList<WayPoint *>();

    while(!out.atEnd()){

        QString str = out.readLine();
        if(str.startsWith(start)){ // начало списка путевых точке
            startEncountered = true;
        }

        if(!startEncountered){ // пропускать строки до начала
            continue;
        }

        if(str.compare(segmentDivider) == 0){// пустая строка = новый сегмент
             continue;
        }

        WayPoint *point = wayPointReader->getPointFromString(str);
        if(point != nullptr){
            point->id = id;
            id++;
            result->append(point);
        }

        if(str.startsWith(end)){ // конец списка путевых точек
            finishEncountered = true;
            break;
        }
    }

    if(!finishEncountered || !startEncountered){
        return nullptr;
    }
    else{
        return result;
    }
}

void SimulationReaderWriter::writeNodePointsToFile(QVector<NodePoint *> *points){
    QFile file(outputPath);
    file.open(QIODevice::WriteOnly | QIODevice::Text );
    QTextStream stream(&file);
    for(int i=0;i<points->length();i++){
        stream << nodepointReaderWriter->convertPointToString(points->at(i)) << "\n";
    }
    stream.flush();
    file.close();
}

// ничего не далает, проблемыс чтением файла с ошибками
QStringList SimulationReaderWriter::readErrors(){
    return QStringList();
}

bool SimulationReaderWriter::isFileExists(QString fileName){
    return QFileInfo::exists(fileName);
}

QString SimulationReaderWriter::genaratOutFileName(QString folderName){
    QString fileName;
    int i=0;
    while(true){
        fileName = "/genaretadRoute" + QString::number(i) + ".flip";
        if(!isFileExists(folderName + fileName)){
            return fileName;
        }else{
            i++;
        }
    }
}
