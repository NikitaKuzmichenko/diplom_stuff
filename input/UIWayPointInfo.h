#ifndef UIWAYPOINTINFO_H
#define UIWAYPOINTINFO_H

#include "UIItemIfo.h"

#include <QLabel>
#include <QLineEdit>



class UIWayPointInfo : public UIItemIfo{
public:
    UIWayPointInfo(QGraphicsView *container,Simulation *simulation);
    ~UIWayPointInfo();
    void displayWayPoint(WayPoint *point);
    void hide();
    void show();
    void clearInputs();

private:
    QLabel *typeLable;
    QLineEdit *typeInput;

    QLabel *latitudaLable;
    QLineEdit *latitudaInput;

    QLabel *longitudeLable;
    QLineEdit *longitudeInput;

    QLabel *heightLable;
    QLineEdit *heightInput;

    QLabel *newHLable;
    QLineEdit *newHInput;

    QLabel *thetaLable;
    QLineEdit *thetaInput;

    QLabel *psiLable;
    QLineEdit *psiInput;

    QLabel *gammaLable;
    QLineEdit *gammaInput;

    QLabel *ailerionLable;
    QLineEdit *ailerionInput;

    QLabel *alphaLable;
    QLineEdit *alphaInput;

    QLabel *icLable;
    QLineEdit *icInput;

    QLabel *thrustLable;
    QLineEdit *thrustInput;
};

#endif // UIWAYPOINTINFO_H
