#ifndef SETTINGSREADER_H
#define SETTINGSREADER_H

#include "Settings.h"
#include <QString>
#include <string>

class SettingsManager{
public:
    SettingsManager();
    SettingsManager(QString path);

    ~SettingsManager();
    void setPath(QString path);
    QString getPath();

    bool readSettings();
    bool writeSettings();

    Settings *getSettings();
    void setSettings(Settings *value);

    QPen getGrid_pen();

private:
    Settings *settings;
    QString path;
};

#endif // SETTINGSREADER_H
