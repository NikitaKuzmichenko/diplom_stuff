#ifndef CLICABLESCENE_H
#define CLICABLESCENE_H

#include <drawing/view/SimulationView.h>
#include <QGraphicsScene>
#include <drawing/layers/SelfDrawingLayer.h>

namespace Actions{
    Q_NAMESPACE;
    enum ActionType {
        noAction,
        addTurnNode,
        addNodeToSegment,
        moveNode,
        removeNode,
        selectItem
    };
    Q_ENUM_NS(ActionType)
}

class ClicableScene : public QGraphicsScene{
        Q_OBJECT
public:
    ClicableScene(QObject *parent = 0);
    ClicableScene(SimulationView *view, LayerManager *layerManager);

    QPointF getMousePos();
    void setMousePos(QPointF &value);

    QRect getBoundingRect();
    void setBoundingRect(QRect &value);

    SimulationView *getView();
    void setView(SimulationView *value);

    LayerManager *getLayerManager();
    void setLayerManager(LayerManager *value);

    void setRightAdjustmet(double value);
    void setLetfAdjustmet(double value);
    void setBotAdjustmet(double value);
    void setTopAdjustmet(double value);

    bool contain(QPointF mousePos);
    bool contain();

    QImage getBackground();
    void setBackground(QImage value);

    virtual void displayBackgound() = 0;
    virtual void updateBackgound() = 0;
    virtual void initVisiblaLayers() = 0;

    static DisplayedItem * seclectedItem;
    static DisplayedItem * movedItem;
    static bool itemSelected;
    static Actions::ActionType action;

    SelfDrawingLayer *getBacgroundlayer();
    void setBacgroundlayer(SelfDrawingLayer *value);

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
signals:
    void itemSelectedEvent(ItemType type,long itemId);
protected:

    double topAdjustmet;
    double botAdjustmet;
    double letfAdjustmet;
    double rightAdjustmet;

    QPointF mousePos;
    SimulationView *view;
    LayerManager *layerManager;
    QImage backgroundImg;
    SelfDrawingLayer *bacgroundlayer;

    virtual bool selectAnyItem(QPointF pos) = 0;
    virtual bool selectItem(QPointF pos) = 0;
    virtual bool releaseItem(QPointF pos) = 0;
    virtual bool moveItem(QPointF pos) = 0;
    virtual bool createItem(QPointF pos,NP::NodePointType type) = 0;
    virtual bool createItemOnSegment(QPointF pos,NP::NodePointType type) = 0;
    virtual bool deleteItem(QPointF pos) = 0;
};
#endif // CLICABLESCENE_H
