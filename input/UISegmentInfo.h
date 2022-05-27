#ifndef UISEGMENTINFO_H
#define UISEGMENTINFO_H

#include "UIItemIfo.h"

#include <QLabel>
#include <QLineEdit>



class UISegmentInfo: public UIItemIfo{
public:
    UISegmentInfo(QGraphicsView *container,Simulation *simulation);
    ~UISegmentInfo();
private :

    QLabel *distanceLable;
    QLineEdit *distanceInput;

    QLabel *startCourceLable;
    QLineEdit *startCourceInput;

    QLabel *endCourceLable;
    QLineEdit *endCourceInput;

    QLabel *startPointLable;

    QLabel *startLatitudeLable;
    QLineEdit *startLatitudeInput;

    QLabel *startLongitudeLable;
    QLineEdit *startLongitudeInput;

    QLabel *startHeightLable;
    QLineEdit *startHeightInput;

    QLabel *endPointPointLable;

    QLabel *endLatitudeLable;
    QLineEdit *endLatitudeInput;

    QLabel *endLongitudeLable;
    QLineEdit *endLongitudeInput;

    QLabel *endLeightLable;
    QLineEdit *endLeightInput;

    // UIItemIfo interface
public:
    void displayItem(Segment *item);
    void hide();
    void show();
    void clearInputs();
};

#endif // UISEGMENTINFO_H
