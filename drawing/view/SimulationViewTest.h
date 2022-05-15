#ifndef SIMULATIONWIEW_H
#define SIMULATIONWIEW_H

#include <simulation/Simulation.h>
#include <drawing/layers/LayerManager.h>
#include <simulation/node/NodePointType.h>
#include <drawing/item/node/DisplayedNodeCreator.h>
#include <drawing/item/segment/DisplayedSegment.h>
#include <drawing/item/segment/DisplayedSegmentCreator.h>


class SimulationViewTest{
public:

    SimulationViewTest(Simulation *simulation,LayerManager *layerManager,PlaneViewMapper *map);
    ~SimulationViewTest();
// остаётся здесь -- создание новой точки в UI
    DisplayedNode *addPoint(QPointF pos,NP::NodePointType type);
    DisplayedNode *addPointToLine(DisplayedSegment *line,QPointF pos,NP::NodePointType type);
    DisplayedSegment *createLineWithLastPoint();
//===========================================================================
// на разных проекциях разные конверисии
    void evaluatePoint(QPointF pos,DisplayedNode *item);
// удаление и поиск по изображению везде одинаково
    void deletePoint(DisplayedNode *point);

    DisplayedNode *findPointByMainItem(QGraphicsItem *item);
    DisplayedSegment *findLineByMainItem(QGraphicsItem *item);

    void updateRelatedLines(DisplayedItem *point);
//============

    PlaneViewMapper *getMap();
    void setMap(PlaneViewMapper *value);

private:
    // остаётся здесь -- создание объетов точек для отобаржения и лиинй меджу точками
    DisplayedSegment *createLineBetweenPoints(DisplayedNode *startPoint, DisplayedNode *endPoint);
    DisplayedSegment *createLineBetweenPoints(DisplayedNode *startPoint, DisplayedNode *endPoint,long positioInList);

    DisplayedNode *createPoint(QPointF pos,NP::NodePointType type);
    DisplayedNode *createPoint(QPointF pos,NP::NodePointType type,long positioInList);

    QVector<DisplayedSegment *> getRelatedLines(DisplayedNode *point);
//===============
// общая структура для всех
    DisplayedNodeCreator *pointCreator = new DisplayedNodeCreator();
    DisplayedSegmentCreator *lineCreator = new DisplayedSegmentCreator();

    QVector<DisplayedSegment *> *lines;
    QVector<DisplayedNode *> *points;

    Simulation *simulation;
    LayerManager *layerManager;

    PlaneViewMapper *map;
};

#endif // SIMULATIONWIEW_H
