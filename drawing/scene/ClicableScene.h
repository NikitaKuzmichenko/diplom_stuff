#ifndef CLICABLESCENE_H
#define CLICABLESCENE_H

#include <drawing/view/SimulationViewTest.h>
#include <QGraphicsScene>

namespace Actions{
    Q_NAMESPACE;
    enum ActionType {
        noAction,
        addItem,
        addItemToSegment,
        moveItem,
        removeItem
    };
    Q_ENUM_NS(ActionType)
}

class ClicableScene : public QGraphicsScene{
        Q_OBJECT
public:
    ClicableScene(QObject *parent = 0);
    ClicableScene(SimulationViewTest *view, LayerManager *layerManager);

    QPointF getMousePos();
    void setMousePos(QPointF &value);

    QRect getBoundingRect();
    void setBoundingRect(QRect &value);

    SimulationViewTest *getView();
    void setView(SimulationViewTest *value);

    LayerManager *getLayerManager();
    void setLayerManager(LayerManager *value);

    void setRightAdjustmet(double value);
    void setLetfAdjustmet(double value);
    void setBotAdjustmet(double value);
    void setTopAdjustmet(double value);

    bool contain(QPointF mousePos);
    bool contain();

    static DisplayedItem * seclectedItem;
    static bool itemSelected;
    static Actions::ActionType action;

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

protected:
    double topAdjustmet;
    double botAdjustmet;
    double letfAdjustmet;
    double rightAdjustmet;

    QPointF mousePos;
    SimulationViewTest *view;
    LayerManager *layerManager;

    virtual bool selectItem(QPointF pos) = 0;
    virtual bool releaseItem(QPointF pos) = 0;
    virtual bool moveItem(QPointF pos) = 0;
    virtual bool createItem(QPointF pos,NP::NodePointType type) = 0;
    virtual bool createItemOnSegment(QPointF pos,NP::NodePointType type) = 0;
    virtual bool deleteItem(QPointF pos) = 0;
};

#endif // CLICABLESCENE_H
