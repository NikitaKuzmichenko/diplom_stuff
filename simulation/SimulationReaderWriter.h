#ifndef SIMULATIONREADERWRITER_H
#define SIMULATIONREADERWRITER_H

#include <simulation/wayPoint/WayPointReadeRwriter.h>
#include <simulation/node/NodePointReaderWriter.h>

class SimulationReaderWriter{
public:
    SimulationReaderWriter();
    ~SimulationReaderWriter();

    /*! читает все узловые точки, указанные в файле по пути programPath*/
    QList<NodePoint*> *getNodePoints(long& id);
    /*! читает все путевые точки, указанные в файле по пути logPath*/
    QList<WayPoint *> *getWayPoints(long& id);
    /*! читает все узлвые точки в файл, указаныне в outputPath*/
    void writeNodePointsToFile(QVector<NodePoint *> *points);
    /*! читает все ощибки из файла errorPath*/
    QStringList readErrors();

    bool isFileExists(QString fileName);

    QString exePath;
    QString configPath;
    QString detailsPath;
    QString programPath;
    QString logPath;
    QString routePath;
    QString errorPath;
    QString tempPath;
    QString outputPath;

private:
    WayPointReaderWriter *wayPointReader;
    NodePointReaderWriter *nodepointReaderWriter;

    QString genaratOutFileName(QString folderName);
};

#endif // SIMULATIONREADERWRITER_H
