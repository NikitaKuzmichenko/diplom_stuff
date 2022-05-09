#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <drawing/view/maper/PlaneViewMapper.h>

#include <drawing/layers/GeographicGridLayer.h>
#include <drawing/layers/LayerManager.h>

#include <settings/SettingsManager.h>

#include <drawing/view/ClickablePlane.h>

namespace Ui {
class SimulationWindow;
}

class SimulationWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit SimulationWindow(QWidget *parent,SettingsManager *settingsManager,PlaneViewMapper *planeView);
    ~SimulationWindow();

    QMainWindow *getStartWindow();
    void setStartWindow(QMainWindow *value);

private slots:
    void on_geo_base_en_stateChanged(int arg1);
    void on_node_points_en_stateChanged(int arg1);
    void on_action_type_activated(int index);
    void on_text_stateChanged(int arg1);
    void on_lines_stateChanged(int arg1);

private:

    void ViewSettings();
    void initGrlidLayer(QImage img);
    void initBackground(QImage img);

    QMainWindow *startWindow;

    SettingsManager *settingsManager;

    PlaneViewMapper *planeView;

    LayerManager *layerManager;

    ClickablePlane *clickablePlane;

    Ui::SimulationWindow *ui;
};

#endif // SIMULATIONWINDOW_H
