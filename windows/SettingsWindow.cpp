#include "SettingsWindow.h"
#include "StartWindow.h"
#include "ui_SettingsWindow.h"

SettingsWindow::SettingsWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::SettingsWindow){
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

SettingsWindow::~SettingsWindow(){
    delete ui;
}

void SettingsWindow::on_backButton_clicked(){
    StartWindow *startWindow = new StartWindow(nullptr,manager);
    startWindow->showMaximized();

    this->deleteLater();
}

void SettingsWindow::on_saveButton_clicked(){

    manager->getSettings()->setLines_in_grid(ui->GridLinesNumber->value());
    manager->getSettings()->setGrid_line_size(ui->GridLineSize->value());

    if(ui->GridLineColor->currentText().isEmpty()){
       manager->getSettings()->setGrid_line_color(ui->GridLineColor->placeholderText());
    }else{
         manager->getSettings()->setGrid_line_color(ui->GridLineColor->currentText());
    }

    this->getManager()->writeSettings();
}

void SettingsWindow::on_resetButton_clicked(){
    Settings *newSettins = new Settings();
    manager->setSettings(newSettins);

    ui->GridLineSize->setValue(newSettins->getGrid_line_size());
    ui->GridLinesNumber->setValue(newSettins->getLines_in_grid());
    ui->GridLineColor->setCurrentText(newSettins->getGrid_line_color());
}

QMainWindow *SettingsWindow::getStartWindow(){
    return startWindow;
}

void SettingsWindow::setStartWindow(QMainWindow *value){
    startWindow = value;
}

void SettingsWindow::setManager(SettingsManager *value){

    ui->GridLineSize->setValue(value->getSettings()->getGrid_line_size());
    ui->GridLinesNumber->setValue(value->getSettings()->getLines_in_grid());

    ui->GridLineSize->setMinimum(1);
    ui->GridLineSize->setMaximum(20);

    ui->GridLinesNumber->setMinimum(2);
    ui->GridLinesNumber->setMaximum(10);

    ui->GridLineColor->setPlaceholderText(value->getSettings()->getGrid_line_color());
    ui->GridLineColor->addItems(colors);

    manager = value;
}

SettingsManager *SettingsWindow::getManager(){
    return manager;
}
