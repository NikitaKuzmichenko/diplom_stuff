#ifndef UIITEMIFO_H
#define UIITEMIFO_H

#include <QGraphicsView>
#include <simulation/Simulation.h>
#include <drawing/item/DisplayedItem.h>

class UIItemIfo : public QObject{
    Q_OBJECT
public:
    UIItemIfo(QGraphicsView *container,Simulation *simulation);
    virtual ~UIItemIfo();

    virtual void hide() = 0;
    virtual void show() = 0;
    virtual void clearInputs() = 0;

    double offset = 50;
    double inputHeight = 20;
    double inputWidth = 200;
    double lableWidth = 100;
    double spaseBetween = 5;
    double totalHeight = inputHeight + spaseBetween;
protected:
    QGraphicsView *container;
    Simulation *simulation;
};

#endif // UIITEMIFO_H
