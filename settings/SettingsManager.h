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

    static Settings *getSettings();
    static void setSettings(Settings *value);

    static QPen getGrid_pen();

private:
    static Settings *settings;
    QString path;
};

#endif // SETTINGSREADER_H
