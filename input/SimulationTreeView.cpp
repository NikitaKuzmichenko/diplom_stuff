#include "SimulationTreeView.h"

#include <QStandardItemModel>

SimulationTreeView::SimulationTreeView(QTreeView *view,Simulation *simulation){
    this->simulation = simulation;
    this->view = view;
    view->show();

    QObject::connect(simulation,&Simulation::segmentCreated,this,&SimulationTreeView::simulationUpdated);
    QObject::connect(simulation,&Simulation::segmentDeleted,this,&SimulationTreeView::simulationUpdated);
    QObject::connect(simulation,&Simulation::segmentUpdated,this,&SimulationTreeView::simulationUpdated);

    QObject::connect(simulation,&Simulation::nodeUpdated,this,&SimulationTreeView::simulationUpdated);
    QObject::connect(simulation,&Simulation::nodeAddedToSegment,this,&SimulationTreeView::simulationUpdated);
    QObject::connect(simulation,&Simulation::nodeCreated,this,&SimulationTreeView::simulationUpdated);
    QObject::connect(simulation,&Simulation::nodeDeleted,this,&SimulationTreeView::simulationUpdated);

    QObject::connect(simulation,&Simulation::wayPointDeleted,this,&SimulationTreeView::simulationUpdated);
    QObject::connect(simulation,&Simulation::wayPointCreated,this,&SimulationTreeView::simulationUpdated);

    QStandardItemModel* model = new QStandardItemModel();
    model->setHorizontalHeaderItem( 0, new QStandardItem( "" ));

    QStandardItem* item0 = new QStandardItem("Segments");
    QStandardItem* item1 = new QStandardItem("Turn points");
    QStandardItem* item2 = new QStandardItem("Way points");

    model->appendRow(item0);
    model->appendRow(item1);
    model->appendRow(item2);

    view->setModel(model);
}

SimulationTreeView::~SimulationTreeView(){}

void SimulationTreeView::simulationUpdated(){

    QStandardItemModel* model = new QStandardItemModel();
    model->setHorizontalHeaderItem( 0, new QStandardItem( "Simulation items" ) );

    QStandardItem* item0 = new QStandardItem("Segments");
    QStandardItem* item1 = new QStandardItem("Turn points");
    QStandardItem* item2 = new QStandardItem("Way points");

    model->appendRow(item0);
    model->appendRow(item1);
    model->appendRow(item2);

    for(int i=0; i<simulation->getWayPoints()->length();i++){
        item2->appendRow(new QStandardItem(simulation->getWayPoints()->at(i)->genarateDefaultName()));
    }
    for(int i=0; i<simulation->getTurnPoints()->length();i++){
        item1->appendRow(new QStandardItem(simulation->getTurnPoints()->at(i)->generateDefaultName()));
    }

    for(int i=0; i<simulation->getSegments()->length();i++){
        QString name = QString("Segment, id = ");
        name.append(QString::number(simulation->getSegments()->at(i)->getId()));
        QStandardItem *segment = new QStandardItem(name);
        QStandardItem *startNode = new QStandardItem("Start node point");
        startNode->appendRow(new QStandardItem(simulation->getSegments()->at(i)->getStartPoint()->generateDefaultName()));
        QStandardItem *endNode = new QStandardItem("End node point");
        endNode->appendRow(new QStandardItem(simulation->getSegments()->at(i)->getEndPoint()->generateDefaultName()));
        QStandardItem *nodes = new QStandardItem("Internal nodes");
        for(int j=0;j< simulation->getSegments()->at(i)->getNodes()->length();j++){
            nodes->appendRow(new QStandardItem(simulation->getSegments()->at(i)->getNodes()->at(j)->generateDefaultName()));
        }
        segment->appendRow(startNode);
        segment->appendRow(endNode);
        segment->appendRow(nodes);

        item0->appendRow(segment);
    }
    view->setModel(model);
}
