#include "SimulationWindow.h"
#include "ui_SimulationWindow.h"

#include <QMetaEnum>
#include <QPixmap>
#include <drawing/scene/ClicablePlaneScene.h>
#include <simulation/Simulation.h>

SimulationWindow::SimulationWindow(QWidget *parent,
                                   SettingsManager *manager,
                                   PlaneViewMapper *simulationMap,
                                   QImage bgImg) : QMainWindow(parent),ui(new Ui::SimulationWindow){

    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    this->planeView = simulationMap;
    settingsManager = manager;
    layerManager = new LayerManager();

    Simulation *simulation = new Simulation();

    clickablePlane = new ClicablePlaneScene(new SimulationViewTest(simulation,layerManager,simulationMap),layerManager);
    ClicableScene::action = Actions::ActionType::addItem;

    ViewSettings();

    QRectF rect(0,0,bgImg.width(),bgImg.height());

    rect.adjust(-30,-30,30,30);

    clickablePlane->setSceneRect(rect);

    initBackground(bgImg);
    initGrlidLayer(bgImg);

    QList<QGraphicsItem *> node_items;
    VisibleLayer *nodePointsLayer = new VisibleLayer(LayerName::node_point,true);
    nodePointsLayer->setItemGroupe(clickablePlane->createItemGroup(node_items));
    layerManager->addlayer(LayerName::node_point,nodePointsLayer);

    QList<QGraphicsItem *> text_items;
    VisibleLayer *text_layer = new VisibleLayer(LayerName::text,false);
    text_layer->setItemGroupe(clickablePlane->createItemGroup(text_items));
    layerManager->addlayer(LayerName::text,text_layer);

    QList<QGraphicsItem *> lines_items;
    VisibleLayer *lines_layer = new VisibleLayer(LayerName::line,true);
    lines_layer->setItemGroupe(clickablePlane->createItemGroup(text_items));
    layerManager->addlayer(LayerName::line,lines_layer);


    ui->geo_base_en->setCheckState(Qt::CheckState::Checked);
    ui->node_points_en->setCheckState(Qt::CheckState::Checked);
    ui->text->setCheckState(Qt::CheckState::Checked);
    ui->lines->setCheckState(Qt::CheckState::Checked);

    ui->action_type->setPlaceholderText("secelt action type");
    ui->action_type->addItem(QMetaEnum::fromType<Actions::ActionType>().valueToKey(0));
    ui->action_type->addItem(QMetaEnum::fromType<Actions::ActionType>().valueToKey(1));
    ui->action_type->addItem(QMetaEnum::fromType<Actions::ActionType>().valueToKey(2));
    ui->action_type->addItem(QMetaEnum::fromType<Actions::ActionType>().valueToKey(3));
    ui->action_type->addItem(QMetaEnum::fromType<Actions::ActionType>().valueToKey(4));

    ui->planeView->show();
}

SimulationWindow::~SimulationWindow(){
    //delete simulationMap;
    delete layerManager;
    delete clickablePlane;
    delete ui;
}


void SimulationWindow::on_geo_base_en_stateChanged(int arg1){
    if(arg1 == Qt::CheckState::Unchecked){
        layerManager->getLayerByName(LayerName::grid)->hideGroupe();
    }else{
        layerManager->getLayerByName(LayerName::grid)->displayGrouope();
    }

}

void SimulationWindow::on_node_points_en_stateChanged(int arg1){
    if(arg1 == Qt::CheckState::Unchecked){
        layerManager->getLayerByName(LayerName::node_point)->hideGroupe();
    }else{
        layerManager->getLayerByName(LayerName::node_point)->displayGrouope();
    }
}

void SimulationWindow::on_text_stateChanged(int arg1){
    if(arg1 == Qt::CheckState::Unchecked){
        layerManager->getLayerByName(LayerName::text)->hideGroupe();
    }else{
        layerManager->getLayerByName(LayerName::text)->displayGrouope();
    }

}

void SimulationWindow::on_lines_stateChanged(int arg1){
    if(arg1 == Qt::CheckState::Unchecked){
        layerManager->getLayerByName(LayerName::line)->hideGroupe();
    }else{
        layerManager->getLayerByName(LayerName::line)->displayGrouope();
    }
}

void SimulationWindow::on_action_type_activated(int index){
     ClicableScene::action =Actions::ActionType(index);
}


void SimulationWindow::ViewSettings(){
    ui->planeView->setRenderHint(QPainter::Antialiasing);
    ui->planeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->planeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->planeView->setScene(clickablePlane);

}

void SimulationWindow::initGrlidLayer(QImage img){

    GeographicGridLayer *gridLayer = new GeographicGridLayer(LayerName::grid,false);
    QList<QGraphicsItem *> grid_items;
    gridLayer->setItemGroupe(clickablePlane->createItemGroup(grid_items));

    gridLayer->setLinesPerXAxis(settingsManager->getSettings()->getLines_in_grid());
    gridLayer->setLinesPerYAxis(settingsManager->getSettings()->getLines_in_grid());
    gridLayer->setMaxYValue(planeView->getElevationMap()->getMaxLatDeg());
    gridLayer->setMinYValue(planeView->getElevationMap()->getMinLatDeg());
    gridLayer->setMaxXValue(planeView->getElevationMap()->getMaxLongDeg());
    gridLayer->setMinXValue(planeView->getElevationMap()->getMinLongDeg());
    gridLayer->setWight(img.width());
    gridLayer->setHieght(img.height());
    gridLayer->setXIndent(30);
    gridLayer->setYIndent(30);
    gridLayer->setPen(settingsManager->getGrid_pen());
    gridLayer->draw();

    layerManager->addlayer(LayerName::grid,gridLayer);
}

void SimulationWindow::initBackground(QImage img){

    GeographicGridLayer *background = new GeographicGridLayer(LayerName::backgroud,false);
    QList<QGraphicsItem *> background_items;
    background->setItemGroupe(clickablePlane->createItemGroup(background_items));

    QGraphicsPixmapItem *pixMap = new QGraphicsPixmapItem(QPixmap::fromImage(img));
    clickablePlane->addItem(pixMap);
    background->addItem(pixMap);

    layerManager->addlayer(LayerName::backgroud,background);
}


QMainWindow *SimulationWindow::getStartWindow(){
    return startWindow;
}

void SimulationWindow::setStartWindow(QMainWindow *value){
    startWindow = value;
}
