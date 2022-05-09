#ifndef CLICKABLEVIEW_H
#define CLICKABLEVIEW_H

#include "SimulationView.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>

#include <drawing/layers/LayerManager.h>

namespace Actions{
    Q_NAMESPACE;
    enum ActionType {addItem,addItemToLine,moveItem,removeItem};
    Q_ENUM_NS(ActionType)
}


class ClickablePlane : public QGraphicsScene{
    Q_OBJECT

public:
   explicit ClickablePlane(QObject *parent = 0);
   explicit ClickablePlane(LayerManager *layerManager,SimulationView *view);

   Actions::ActionType getAction();
   void setAction(Actions::ActionType value);

   static const int roundSceneIndent = 30;

   static bool getItemSelected();
   static void setItemSelected(bool value);

public slots:
   void mousePressEvent(QGraphicsSceneMouseEvent *e);
   void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    bool contain(QPointF point);

    SimulationView *view;

    static bool itemSelected; // FIX THIS CRAP
    static DisplayedNodePoint * selectedItem;
    QPointF mousePos;

    Actions::ActionType action;
    LayerManager *layerManager;
};

#endif // CLICKABLEVIEW_H
