#include "CreateSimulationWindow.h"
#include "SettingsWindow.h"
#include "StartWindow.h"
#include "ui_StartWindow.h"

StartWindow::StartWindow(QWidget *parent, SettingsManager *manager) : QMainWindow(parent), ui(new Ui::StartWindow){
    ui->setupUi(this);

    if(manager == nullptr){
        manager = new SettingsManager();
    }
    setManager(manager);
}

StartWindow::~StartWindow(){
    delete manager;
    delete ui;
}

void StartWindow::on_createSimulation_clicked(){
    CreateSimulationWindow *createSimulation = new CreateSimulationWindow();
    createSimulation->setManager(manager);
    createSimulation->setStartWindow(this);
    createSimulation->showMaximized();

    close();
}

void StartWindow::on_settings_clicked(){
    SettingsWindow *settingsWindow = new SettingsWindow();
    settingsWindow->setManager(manager);
    settingsWindow->setStartWindow(this);
    settingsWindow->showMaximized();

    close();
}

void StartWindow::on_exit_clicked(){
    qApp->exit();
}

SettingsManager *StartWindow::getManager(){
    return manager;
}

void StartWindow::setManager(SettingsManager *value){
    manager = value;
}
