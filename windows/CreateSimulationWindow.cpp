#include "CreateSimulationWindow.h"
#include "SimulationWindow.h"
#include "StartWindow.h"
#include "ui_CreateSimulationWindow.h"

#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QMessageBox>

#include <drawing/layers/GeographicGridLayer.h>

CreateSimulationWindow::CreateSimulationWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::CreateSimulationWindow) {
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    planeViewMapper = new PlaneViewMapper();
    scene = new QGraphicsScene();
    layer = new GeographicGridLayer(1);

    QList<QGraphicsItem *> list;
    layer->setItemGroupe(this->scene->createItemGroup(list));

    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy (Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);

    imgPixelMap = new QGraphicsPixmapItem();
    imgPixelMap->setZValue(0);
    scene->addItem(imgPixelMap);
}

CreateSimulationWindow::~CreateSimulationWindow(){
  //  delete scene;
   // delete imgPixelMap;
//    delete layer;
    delete ui;
}

void CreateSimulationWindow::on_select_img_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "select map image","C:\\Users\\nikit\\OneDrive\\Рабочий стол",
                                                    "Images (*.png *.xpm *.jpg)");

    if(!fileName.isEmpty()){
        ui->map_img_path->setText(fileName);

        QImage *img = new QImage(fileName);
        imgPixelMap->setPixmap(QPixmap::fromImage(*img));

        planeViewMapper->setBoundingRect(*img);
        bgImg = img;

        QRectF rect(0,0,img->width(),img->height());
        rect.adjust(-roundSceneIndent,-roundSceneIndent,roundSceneIndent,roundSceneIndent);
        scene->setSceneRect(rect);

        if(mapPresent){

            layer->setWight(planeViewMapper->getBoundingRect().width());
            layer->setHieght(planeViewMapper->getBoundingRect().height());
            layer->setXIndent(roundSceneIndent);
            layer->setYIndent(roundSceneIndent);

            layer->clear();
            layer->setPen(manager->getGrid_pen());
            layer->draw();


            planeViewMapper->calculateUnitPerPixeRatio();
        }

        ui->graphicsView->show();
        imgPresent = true;
    }
}

void CreateSimulationWindow::on_select_model_clicked(){
    QString fileName = QFileDialog::getOpenFileName(this,"select map image","C:\\Users\\nikit\\OneDrive\\Рабочий стол","*.txt *.asc");

    if(!fileName.isEmpty()){
        ElevationMap *elevationMap = new ElevationMap(fileName);

        if(!elevationMap->loadMap()){

            this->mapPresent = false;
            QMessageBox msgBox;
            msgBox.setText("model file have incorrect format.");
            msgBox.exec();

        }else{

            layer->setLinesPerXAxis(manager->getSettings()->getLines_in_grid());
            layer->setLinesPerYAxis(manager->getSettings()->getLines_in_grid());

            layer->setMaxYValue(elevationMap->getMaxLatDeg());
            layer->setMinYValue(elevationMap->getMinLatDeg());

            layer->setMaxXValue(elevationMap->getMaxLongDeg());
            layer->setMinXValue(elevationMap->getMinLongDeg());

            if(this->imgPresent){

                layer->setWight(planeViewMapper->getBoundingRect().width());
                layer->setHieght(planeViewMapper->getBoundingRect().height());
                layer->setXIndent(roundSceneIndent);
                layer->setYIndent(roundSceneIndent);

                layer->clear();
                layer->setPen(manager->getGrid_pen());
                layer->draw();
            }

            mapPresent = true;
            planeViewMapper->setElevationMap(elevationMap);
            ui->elevation_model_path->setText(fileName);
        }
    }
}

void CreateSimulationWindow::on_start_simulation_clicked(){
    if(mapPresent && imgPresent){

        SimulationWindow *simulation = new SimulationWindow(nullptr,manager,planeViewMapper,*bgImg);
        simulation->setStartWindow(startWindow);
        simulation->showMaximized();

        hide();

    }else{

        QMessageBox msgBox;
        msgBox.setText("height diagram and image are required");
        msgBox.exec();
    }
}

void CreateSimulationWindow::on_back_to_menu_clicked(){
    startWindow->show();
    close();
}

QMainWindow *CreateSimulationWindow::getStartWindow(){
    return startWindow;
}

void CreateSimulationWindow::setStartWindow(QMainWindow *value){
    startWindow = value;
}

SettingsManager *CreateSimulationWindow::getManager(){
    return manager;
}

void CreateSimulationWindow::setManager(SettingsManager *value){
    manager = value;
}
