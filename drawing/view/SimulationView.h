#ifndef SIMULATIONWIEW_H
#define SIMULATIONWIEW_H

#include <simulation/Simulation.h>
#include <drawing/layers/LayerManager.h>
#include <drawing/item/point/DisplayedNodePoint.h>
#include <drawing/item/point/NodeCreator.h>
#include <drawing/item/line/DisplayedSegment.h>
#include <drawing/item/line/SegmentCreator.h>


class SimulationView{
public:

    SimulationView(Simulation *simulation,LayerManager *layerManager,PlaneViewMapper *map);
    ~SimulationView();
// остаётся здесь -- создание новой точки в UI
    DisplayedNodePoint *addPoint(QPointF pos,NodePointType type);
    DisplayedNodePoint *addPointToLine(DisplayedSegment *line,QPointF pos,NodePointType type);
    DisplayedSegment *createLineWithLastPoint();
//===========================================================================
// на разных проекциях разные конверисии
    void evaluatePoint(QPointF pos,DisplayedNodePoint *item);  
// удаление и поиск по изображению везде одинаково
    void deletePoint(DisplayedNodePoint *point);

    DisplayedNodePoint *findPointByMainItem(QGraphicsItem *item);
    DisplayedSegment *findLineByMainItem(QGraphicsItem *item);

    void updateRelatedLines(DisplayedItem *point);
//============

    PlaneViewMapper *getMap();
    void setMap(PlaneViewMapper *value);

private:
    // остаётся здесь -- создание объетов точек для отобаржения и лиинй меджу точками
    DisplayedSegment *createLineBetweenPoints(DisplayedNodePoint *startPoint, DisplayedNodePoint *endPoint);
    DisplayedSegment *createLineBetweenPoints(DisplayedNodePoint *startPoint, DisplayedNodePoint *endPoint,long positioInList);

    DisplayedNodePoint *createPoint(QPointF pos,NodePointType type);
    DisplayedNodePoint *createPoint(QPointF pos,NodePointType type,long positioInList);

    QVector<DisplayedSegment *> getRelatedLines(DisplayedNodePoint *point);
//===============
// общая структура для всех
    NodeCreator *pointCreator = new NodeCreator();
    SegmentCreator *lineCreator = new SegmentCreator();

    QVector<DisplayedSegment *> *lines;
    QVector<DisplayedNodePoint *> *points;

    Simulation *simulation;
    LayerManager *layerManager;

    PlaneViewMapper *map;
};

#endif // SIMULATIONWIEW_H
