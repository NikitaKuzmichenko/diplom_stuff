#include "ElevationMap.h"

#include <QDebug>
#include <QFile>
#include <QTextStream>

#include <utils/Utils.h>

ElevationMap::ElevationMap(){}

ElevationMap::~ElevationMap(){
    if(map!= nullptr){
        for(int i=0;i<rowNumber;i++){
            delete [] map[i];
        }
        delete [] map;
    }
}

ElevationMap::ElevationMap(QString path){
    this->mapPath = path;
}

bool ElevationMap::loadMap(){

    QFile file(this->mapPath);
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen()){
        return false;
    }

    QTextStream in(&file);
    QString paramName;

    in >> paramName;
    in >> this->rowNumber;

    in >> paramName;
    in >> this->columnNumber;

    in >> paramName;
    in >> this->minLongDeg;

    in >> paramName;
    in >> this->minLatDeg;

    in >> paramName;
    in >> this->stepToDegRatio;

    in >> paramName;
    in >> this->undefinedValue;

    in.readLine();

    map = new int*[rowNumber];
    for(int i=0;i<rowNumber;i++){
        map[i] = new int[columnNumber];
    }

    int lineCounter = 0;
    QStringList line;
    for(lineCounter = 0; !in.atEnd() || lineCounter < rowNumber;lineCounter++){
        line = in.readLine().split(' ');
        if(line.size() != columnNumber + 1){
            for(int i=0;i<lineCounter;i++){
                delete [] map[i];
            }
            delete [] map;
            map = nullptr;
            return false;
        }

        for(int column=0;column<columnNumber;column++){
            map[lineCounter][column] = line.at(column).toInt();
        }
    }

    file.close();

    this->maxLongDeg = minLongDeg + rowNumber * stepToDegRatio;
    this->maxLatDeg = minLatDeg + columnNumber * stepToDegRatio;

    Utils::roundUp(maxLongDeg,1000);
    Utils::roundUp(maxLatDeg,1000);
    return true;
}


void ElevationMap::setMapPath(QString path){
    this->mapPath = path;
}

QString ElevationMap::getMapPath(){
    return this->mapPath;
}

bool ElevationMap::addHeightToSinglePoint(PhysicalPoint *point){

    int column = (point->getLongitude() - minLongDeg) / this->stepToDegRatio;
    int row = (maxLatDeg - point->getLatitude()) / this->stepToDegRatio;

    if(column == columnNumber){
        column--;
    }

    if(column > this->columnNumber || row > this->rowNumber){
        return false;
    }

    point->setHight(map[row][column]);

    return true;
}

int ElevationMap::getRowNumber(){
    return this->rowNumber;
}

int ElevationMap::getColumnNumer(){
    return this->columnNumber;
}

int ElevationMap::getUndefinedValue(){
    return this->undefinedValue;
}

double ElevationMap::getMinLongDeg(){
    return this->minLongDeg;
}

double ElevationMap::getMaxLongDeg(){
    return this->maxLongDeg;
}

double ElevationMap::getMinLatDeg(){
    return this->minLatDeg;
}

double ElevationMap::getMaxLatDeg(){
    return this->maxLatDeg;
}

double ElevationMap::getStepToDegRatio(){
    return this->stepToDegRatio;
}
