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

    manager->getSettings()->lines_in_grid = ui->GridLinesNumber->value();
    manager->getSettings()->grid_line_size = ui->GridLineSize->value();

    if(ui->GridLineColor->currentText().isEmpty()){
       manager->getSettings()->grid_line_color = ui->GridLineColor->placeholderText();
    }else{
         manager->getSettings()->grid_line_color = ui->GridLineColor->currentText();
    }

    this->getManager()->writeSettings();
}

void SettingsWindow::on_resetButton_clicked(){
    Settings *newSettins = new Settings();
    manager->setSettings(newSettins);

    ui->GridLineSize->setValue(newSettins->grid_line_size);
    ui->GridLinesNumber->setValue(newSettins->lines_in_grid);
    ui->GridLineColor->setCurrentText(newSettins->grid_line_color);
}

QMainWindow *SettingsWindow::getStartWindow(){
    return startWindow;
}

void SettingsWindow::setStartWindow(QMainWindow *value){
    startWindow = value;
}

void SettingsWindow::setManager(SettingsManager *value){

    ui->GridLineSize->setValue(value->getSettings()->grid_line_size);
    ui->GridLinesNumber->setValue(value->getSettings()->lines_in_grid);

    ui->GridLineColor->setPlaceholderText(value->getSettings()->grid_line_color);

    ui->GridLineColor->addItems(colors);
    ui->WayPointDescColor->addItems(colors);
    ui->NodePointColor->addItems(colors);
    ui->SegmentColor->addItems(colors);
    ui->NodePointDescColor->addItems(colors);
    ui->WayPointColor->addItems(colors);

    manager = value;
}

SettingsManager *SettingsWindow::getManager(){
    return manager;
}
