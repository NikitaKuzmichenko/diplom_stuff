#include "SettingsManager.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDir>

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

    settings->setLines_in_grid(jsonObj[settings->LINES_NUMBER].toInt());
    settings->setGrid_line_size(jsonObj[settings->GRID_LINE_SIZE].toInt());
    settings->setGrid_line_color(jsonObj[settings->GRID_LINE_COLOR].toString());

    this->settings = settings;
    return true;
}

bool SettingsManager::writeSettings(){
    QFile jsonFile(path);

    jsonFile.open(QIODevice::ReadWrite);

    QJsonObject obj;
    obj.insert(settings->LINES_NUMBER, settings->getLines_in_grid());
    obj.insert(settings->GRID_LINE_SIZE, settings->getGrid_line_size());
    obj.insert(settings->GRID_LINE_COLOR, settings->getGrid_line_color());

    QJsonArray array;
    array.push_back(obj);
    jsonFile.write(QJsonDocument(array).toJson(QJsonDocument::Indented));
    jsonFile.close();

    return true;
}

QPen SettingsManager::getGrid_pen(){
    QPen pen;

    pen.setColor(QColor((settings->getGrid_line_color())));
    pen.setWidth(settings->getGrid_line_size());
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
