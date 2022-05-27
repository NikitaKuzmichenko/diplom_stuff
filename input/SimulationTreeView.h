#ifndef SIMULATIONTREEVIEW_H
#define SIMULATIONTREEVIEW_H

#include <QObject>
#include <QTreeView>

#include <simulation/Simulation.h>

class SimulationTreeView : public QObject{
    Q_OBJECT
public:
    SimulationTreeView(QTreeView *view,Simulation *simulation);
    ~SimulationTreeView();
public slots:
    void simulationUpdated();
private :
    QTreeView *view;
    Simulation *simulation;
};

#endif // SIMULATIONTREEVIEW_H
