#ifndef UINODECREATOR_H
#define UINODECREATOR_H

#include "UIItemIfo.h"

#include <QComboBox>
#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <simulation/Simulation.h>

class UINodeInfo: public UIItemIfo{
public:
   UINodeInfo(QGraphicsView *container,Simulation *simulation);
   ~UINodeInfo();

private:
    // тип точки
    QLabel *nodeTypeLable;
    QComboBox *nodeTypeInput;

    // общие х-ки
    QLabel *latitudeLable;
    QLineEdit *latitudeInput;

    QLabel *longitudeLable;
    QLineEdit *longitudeInput;

    QLabel *heightLable;
    QLineEdit *heightInput;

    // скорость
    QLabel *speedLable;
    QLineEdit *speedInput;

    // новыя высота для точек подъёма и спуска
    QLabel *newHeightLable;
    QLineEdit *newHeightInput;

    // угол наклона для точек подъёма и спуска
    QLabel *thetaLable;
    QLineEdit *thetaInput;

    // радиусп поворота
    QLabel *turnRadiusLable;
    QLineEdit *turnRadiusInput;

    // для зоны коррекции
    QLabel *psiLable;
    QLineEdit *psiInput;

    // радиус угаол наклоа при повороте
    QLabel *zonLenLable;
    QLineEdit *zonLenInput;

    QLabel *zonWidthLable;
    QLineEdit *zonWidthInput;

    QLabel *azimuthLable;
    QLineEdit *azimuthInput;

    QLabel *filePathLable;
    QLineEdit *filePathInput;

 // segment id
    QLabel *segmentIdLable;
    QLineEdit *segmentIdInput;
//===============================================
    QPushButton *saveButton;

    NodePoint *node = nullptr;

public slots :
    void reset();
    void save();
    void typeChange(int index);
public:
    void hide();
    void show();
    void clearInputs();
    void displayNode(NodePoint *node,NP::NodePointType type);
    void displayButtons();
    void hideButtons();
private:
    void displayTypedNode(NP::NodePointType type);
    void displayGeneralInfo(NodePoint *node);
    void displayClimbNode(NodePoint *node);
    void displayDescendNode(NodePoint *node);
    void displayCruiseNode(NodePoint *node);
    void displayDemNode(NodePoint *node);
    void displayImgNode(NodePoint *node);
    void displayTakeOffNode(NodePoint *node);
    void displayFinishNode(NodePoint *node);
    void displayTurnNode(NodePoint *node);
    void displayMarkerNode(NodePoint *node);
};

#endif // UINODECREATOR_H
