#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>

#include <drawing/view/maper/PlaneViewMapper.h>
#include <settings/SettingsManager.h>

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit StartWindow(QWidget *parent = nullptr,SettingsManager *manager = nullptr);
    ~StartWindow();

    SettingsManager *getManager();
    void setManager(SettingsManager *value);

private slots:

    void on_createSimulation_clicked();
    void on_settings_clicked();
    void on_exit_clicked();

private:
    SettingsManager *manager;
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
