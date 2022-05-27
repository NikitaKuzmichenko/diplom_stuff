#include "SettingsManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>

Settings *SettingsManager::settings = nullptr;

SettingsManager::SettingsManager(){
    this->path = QDir::currentPath() + "/settings.json";
    this->settings = new Settings();
}

SettingsManager::SettingsManager(QString path){
    this->path = path;
    this->settings = new Settings();
}

SettingsManager::~SettingsManager(){
    delete settings;
}

bool SettingsManager::readSettings(){
    QFile jsonFile(path);
    if(!jsonFile.exists()){
        return false;
    }

    jsonFile.open(QIODevice::ReadWrite);

    if(!jsonFile.isOpen()){
         return false;
    }

    QByteArray data = jsonFile.readAll();
    jsonFile.close();

    QJsonDocument jsonDoc(QJsonDocument::fromJson(data));
    QJsonArray jArr = jsonDoc.array();
    QJsonValue jsonObj = jArr.at(0);

    Settings *settings = new Settings();

    settings->lines_in_grid = jsonObj[settings->LINES_NUMBER].toInt();
    settings->grid_line_size = jsonObj[settings->GRID_LINE_SIZE].toInt();
    settings->grid_line_color = jsonObj[settings->GRID_LINE_COLOR].toString();

    this->settings = settings;
    return true;
}

bool SettingsManager::writeSettings(){
    QFile jsonFile(path);

    jsonFile.open(QIODevice::ReadWrite);

    QJsonObject obj;
    obj.insert(settings->LINES_NUMBER, settings->lines_in_grid);
    obj.insert(settings->GRID_LINE_SIZE, settings->grid_line_size);
    obj.insert(settings->GRID_LINE_COLOR, settings->grid_line_color);

    QJsonArray array;
    array.push_back(obj);
    jsonFile.write(QJsonDocument(array).toJson(QJsonDocument::Indented));
    jsonFile.close();

    return true;
}

QPen SettingsManager::getGrid_pen(){
    QPen pen;

    pen.setColor(QColor((settings->grid_line_color)));
    pen.setWidth(settings->grid_line_size);
    pen.setStyle(Qt::DashLine);

    return pen;
}

Settings *SettingsManager::getSettings(){
    return settings;
}

void SettingsManager::setSettings(Settings *value){
    settings = value;
}

void SettingsManager::setPath(QString path){
    this->path = path;
}

QString SettingsManager::getPath(){
    return this->path;
}

//bool writeSettings(){
//QFile jsonFile(path);
//jsonFile.open(QIODevice::ReadWrite);

//QJsonObject obj;

//obj.insert(settings->LINES_NUMBER, settings->lines_in_grid);
//obj.insert(settings->GRID_LINE_SIZE, settings-> grid_line_size);
//obj.insert(settings->GRID_LINE_COLOR, settings-> grid_line_color);
//obj.insert(settings-> SEGMENT_WIDTH, settings-> segment_width);
//obj.insert(settings-> SEGMENT_COLOR, settings-> segment_color);

//obj.insert(settings-> NODE_POINT_RADIUS, settings-> node_point_radius);
//obj.insert(settings-> NODE_POINT_COLOR, settings-> node_point_color);
//obj.insert(settings-> NODE_POINT_DESC_FONT, settings-> node_point_desc_font);
//obj.insert(settings-> NODE_POINT_DESC_COLOR, settings-> node_point_desc_color);

//obj.insert(settings-> WAY_POINT_RADIUS, settings-> way_point_radius);
//obj.insert(settings-> WAY_POINT_COLOR, settings-> way_point_color);
//obj.insert(settings-> WAY_POINT_DESC_FONT, settings-> way_point_desc_font);
//obj.insert(settings-> WAY_POINT_DESC_COLOR, settings-> way_point_desc_color);


//QJsonArray array;
//array.push_back(obj);
//   jsonFile.write(QJsonDocument(array).toJson(QJsonDocument::Indented));
//jsonFile.close();
//return true;
//}


//public bool readSettings(){

//path = QDir::currentPath() + "/settings.json"
//QFile jsonFile(path);
//if(!jsonFile.exists()){
//    return false;
//}

//jsonFile.open(QIODevice::ReadWrite);

//if(!jsonFile.isOpen()){
//     return false;
//}

//QByteArray data = jsonFile.readAll();
//jsonFile.close();

//QJsonDocument jsonDoc(QJsonDocument::fromJson(data));
//QJsonArray jArr = jsonDoc.array();
//QJsonValue jsonObj = jArr.at(0);

//Settings *settings = new Settings();

//settings->lines_in_grid = jsonObj[settings-> LINES_NUMBER].toInt();
//settings->grid_line_size = jsonObj[settings-> GRID_LINE_SIZE].toInt();
//settings->grid_line_color = jsonObj[settings-> GRID_LINE_COLOR].toString();

//settings-> segment_width = jsonObj[settings-> SEGMENT_WIDTH].toDouble();
//settings-> segment_color = jsonObj[settings-> SEGMENT_COLOR].toString();

//settings-> node_point_radius = jsonObj[settings-> NODE_POINT_RADIUS].toDouble();
//settings-> node_point_color = jsonObj[settings-> NODE_POINT_COLOR].toString();
//settings-> node_point_desc_font = jsonObj[settings-> NODE_POINT_DESC_FONT].toString();
//settings-> node_point_desc_color = jsonObj[settings-> NODE_POINT_DESC_COLOR].toString();

//settings-> way_point_radius = jsonObj[settings-> WAY_POINT_RADIUS].toDouble();
//settings-> way_point_color = jsonObj[settings-> WAY_POINT_COLOR].toString();
//settings-> way_point_desc_font = jsonObj[settings-> WAY_POINT_DESC_FONT].toString();
//settings-> way_point_desc_color = jsonObj[settings-> WAY_POINT_DESC_COLOR].toString();


//this->settings = settings;
//return true;
//}
