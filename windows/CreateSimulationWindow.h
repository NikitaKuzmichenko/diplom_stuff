#ifndef CREATESIMULATIONWINDOW_H
#define CREATESIMULATIONWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <drawing/view/maper/PlaneViewMapper.h>
#include <drawing/layers/GeographicGridLayer.h>
#include <drawing/layers/VisibleLayer.h>
#include <settings/SettingsManager.h>

namespace Ui {
class CreateSimulationWindow;
}

class CreateSimulationWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit CreateSimulationWindow(QWidget *parent = nullptr);
    ~CreateSimulationWindow();

    SettingsManager *getManager();
    void setManager(SettingsManager *value);

    QMainWindow *getStartWindow();
    void setStartWindow(QMainWindow *value);

private slots:
    void on_select_img_clicked();
    void on_select_model_clicked();
    void on_start_simulation_clicked();
    void on_back_to_menu_clicked();

    void on_select_simulation_clicked();

private:
    const int roundSceneIndent = 30;

    QMainWindow * startWindow;
    SettingsManager *manager;

    bool imgPresent = false;
    bool mapPresent = false;

    QImage *bgImg;
    QString simulationPath;

    GeographicGridLayer *layer;
    QGraphicsScene *scene;
    PlaneViewMapper *planeViewMapper;

    QGraphicsPixmapItem * imgPixelMap;

    Ui::CreateSimulationWindow *ui;
};

#endif // CREATESIMULATIONWINDOW_H
