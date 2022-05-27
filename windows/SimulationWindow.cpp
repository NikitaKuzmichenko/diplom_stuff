#include "CreateSimulationWindow.h"
#include "SimulationWindow.h"
#include "StartWindow.h"
#include "ui_SimulationWindow.h"

#include <QLineEdit>
#include <QMetaEnum>
#include <QPixmap>
#include <QPushButton>
#include <QVBoxLayout>
#include <drawing/scene/ClicablePlaneScene.h>
#include <drawing/view/PlaneSimulationView.h>
#include <input/SimulationTreeView.h>
#include <input/UIItemsManager.h>
#include <input/UINodeInfo.h>
#include <simulation/Simulation.h>

SimulationWindow::SimulationWindow(QWidget *parent,
                                   SettingsManager *settings,
                                   PlaneViewMapper *planeView,
                                   QImage bgImg,
                                   QString nodesPath) : QMainWindow(parent),ui(new Ui::SimulationWindow){

    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    this->planeView = planeView;
    settingsManager = settings;
    layerManager = new LayerManager();

    simulation = new Simulation();
    PlaneSimulationView *planeSimulationView = new PlaneSimulationView(simulation,layerManager,planeView);

    UIItemsManager *itemManger = new UIItemsManager(ui->nodeDetails,simulation);

    ui->nodeDetails->show();
    clickablePlane = new ClicablePlaneScene(planeSimulationView,layerManager);

    QObject::connect(clickablePlane,&ClicableScene::itemSelectedEvent,itemManger,&UIItemsManager::itemSelected);
    QObject::connect(simulation,&Simulation::segmentUpdated,itemManger,&UIItemsManager::segmentWasUpdated);
    QObject::connect(simulation,&Simulation::nodeUpdated,itemManger,&UIItemsManager::nodeWasUpdated);

    treeView = new SimulationTreeView(ui->treeView,simulation);

    QRectF rect(0,0,bgImg.width(),bgImg.height());
    rect.adjust(-30,-30,30,30);
    clickablePlane->setSceneRect(rect);
    clickablePlane->setBackground(bgImg);
    clickablePlane->displayBackgound();
    clickablePlane->initVisiblaLayers();

    ui->geo_base_en->setCheckState(Qt::CheckState::Checked);
    ui->node_points_en->setCheckState(Qt::CheckState::Checked);
    ui->text->setCheckState(Qt::CheckState::Checked);
    ui->lines->setCheckState(Qt::CheckState::Checked);

    ViewSettings();
    ui->planeView->show();

    if(!nodesPath.isEmpty()){
        simulation->getReaderWriter()->routePath = nodesPath;
        simulation->getNodePoints();
        simulation->display();
    }

    ClicableScene::action = Actions::addTurnNode;
}

SimulationWindow::~SimulationWindow(){
    //delete planeView;
    delete layerManager;
    delete clickablePlane;
    delete simulation;
    delete treeView;
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

void SimulationWindow::ViewSettings(){
    ui->planeView->setRenderHint(QPainter::Antialiasing);
    ui->planeView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->planeView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->planeView->setScene(clickablePlane);

}

QMainWindow *SimulationWindow::getStartWindow(){
    return startWindow;
}

void SimulationWindow::setStartWindow(QMainWindow *value){
    startWindow = value;
}

void SimulationWindow::on_deleteButton_clicked(){
    ClicableScene::action = Actions::removeNode;
}

void SimulationWindow::on_addTurnNodeButton_clicked(){
    ClicableScene::action = Actions::addTurnNode;
}

void SimulationWindow::on_moveNodeButton_clicked(){
    ClicableScene::action = Actions::moveNode;
}

void SimulationWindow::on_addNodeToSegmentButton_clicked(){
    ClicableScene::action = Actions::addNodeToSegment;
}

void SimulationWindow::on_selectItemButton_clicked(){
     ClicableScene::action = Actions::selectItem;
}

void SimulationWindow::on_saveButton_clicked(){
    simulation->saveToFile();
}

void SimulationWindow::on_simulateButton_clicked(){
    simulation->simulate();
}

void SimulationWindow::on_backButton_clicked(){
    CreateSimulationWindow *createSimulation = new CreateSimulationWindow();
    createSimulation->setManager(settingsManager);
    createSimulation->setStartWindow(startWindow);
    createSimulation->showMaximized();

    close();
}

void SimulationWindow::on_clearButton_clicked(){
    simulation->clear();
}
