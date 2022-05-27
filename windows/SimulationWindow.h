#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <drawing/view/maper/PlaneViewMapper.h>
#include <drawing/layers/GeographicGridLayer.h>
#include <drawing/layers/LayerManager.h>
#include <settings/SettingsManager.h>
#include <drawing/scene/ClicableScene.h>
#include <input/SimulationTreeView.h>

namespace Ui {
class SimulationWindow;
}

class SimulationWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit SimulationWindow(QWidget *parent,
                              SettingsManager *settingsManager,
                              PlaneViewMapper *planeView,
                              QImage bgImg,
                              QString nodesPath);
    ~SimulationWindow();

    QMainWindow *getStartWindow();
    void setStartWindow(QMainWindow *value);

private slots:
    void on_geo_base_en_stateChanged(int arg1);
    void on_node_points_en_stateChanged(int arg1);
    void on_text_stateChanged(int arg1);
    void on_lines_stateChanged(int arg1);
    void on_deleteButton_clicked();
    void on_addTurnNodeButton_clicked();
    void on_moveNodeButton_clicked();
    void on_addNodeToSegmentButton_clicked();
    void on_selectItemButton_clicked();
    void on_saveButton_clicked();
    void on_simulateButton_clicked();
    void on_backButton_clicked();
    void on_clearButton_clicked();

private:

    void ViewSettings();
    void initGrlidLayer(QImage img);
    void initBackground(QImage img);

    QMainWindow *startWindow;
    SettingsManager *settingsManager;
    PlaneViewMapper *planeView;
    LayerManager *layerManager;

    SimulationTreeView *treeView;
    Simulation *simulation;
    ClicableScene *clickablePlane;

    Ui::SimulationWindow *ui;
};

#endif // SIMULATIONWINDOW_H
