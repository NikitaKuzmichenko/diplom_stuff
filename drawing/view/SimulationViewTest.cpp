#include "SimulationViewTest.h"
#include <utils/GeodesicUtils.h>

SimulationViewTest::SimulationViewTest(Simulation *simulation, LayerManager *layerManager,PlaneViewMapper *map){
    this->simulation = simulation;
    this->map = map;
    map->calculateUnitPerPixeRatio();
    this->layerManager = layerManager;

    points = new QVector<DisplayedNode *>;
    lines = new QVector<DisplayedSegment *>;
}

SimulationViewTest::~SimulationViewTest(){
    delete pointCreator;
    delete pointCreator;
    delete [] points;
    delete [] lines;
}

PlaneViewMapper *SimulationViewTest::getMap(){
    return map;
}

void SimulationViewTest::setMap(PlaneViewMapper *value){
    map = value;
}

DisplayedNode *SimulationViewTest::addPoint(QPointF pos, NP::NodePointType type){
    DisplayedNode *newItem = createPoint(pos,type);
    points->append(newItem);
    return newItem;
}

DisplayedSegment *SimulationViewTest::createLineWithLastPoint(){
    if(points->size() > 1){
        DisplayedSegment *line = createLineBetweenPoints(points->at(points->size() - 2),(points->at(points->size() - 1)));
        return line;
    }
    return nullptr;
}

DisplayedNode *SimulationViewTest::addPointToLine(DisplayedSegment *line, QPointF pos, NP::NodePointType type){

    long midlePosition = (points->indexOf(line->getStartPoint()) + points->indexOf(line->getEndPoint())) / 2;
    DisplayedNode *midlePoint = createPoint(pos,type,midlePosition + 1);
    points->insert(midlePosition + 1,midlePoint);

    long linePosisition = lines->indexOf(line);

    createLineBetweenPoints(line->getStartPoint(),midlePoint,linePosisition);
    createLineBetweenPoints(midlePoint,line->getEndPoint(),linePosisition + 1);

    lines->removeOne(line);
    simulation->removeSegment(line->getRealSegment()->getId());

    delete line;
    return midlePoint;
}

void SimulationViewTest::deletePoint(DisplayedNode *point){
    QVector<DisplayedSegment *> relatedLines = getRelatedLines(point);

    if(relatedLines.size() == 2){
        DisplayedNode *newStart;
        DisplayedNode *newEnd;

        newStart = relatedLines.at(0)->getStartPoint();
        newEnd = relatedLines.at(1)->getEndPoint();

        long posotionInList = (lines->indexOf(relatedLines.at(0)) + lines->indexOf(relatedLines.at(1))) / 2;

        lines->removeOne(relatedLines.at(0));
        simulation->removeSegment(relatedLines.at(0)->getRealSegment()->getId());
        delete relatedLines.at(0);

        lines->removeOne(relatedLines.at(1));
        simulation->removeSegment(relatedLines.at(1)->getRealSegment()->getId());
        delete relatedLines.at(1);

        createLineBetweenPoints(newStart,newEnd,posotionInList);
    }
    if(relatedLines.size() == 1){
        lines->removeOne(relatedLines.at(0));
        simulation->removeSegment(relatedLines.at(0)->getRealSegment()->getId());
        delete relatedLines.at(0);
    }

    simulation->removeNode(point->getNode()->getId());
    points->removeOne(point);
    delete point;
}

void SimulationViewTest::evaluatePoint(QPointF pos, DisplayedNode *item){
    if(item->getNode() == nullptr){
        return;
    }

    item->getNode()->getPoint()->setLongitude(map->minXValue + map->unitPerPixelX * pos.x());
    item->getNode()->getPoint()->setLatitude(map->maxYValue - map->unitPerPixelY * pos.y());
    map->getElevationMap()->addHeightToSinglePoint(item->getNode()->getPoint());

    item->setPosition(pos);
}

DisplayedNode *SimulationViewTest::findPointByMainItem(QGraphicsItem *item){
    for(auto result: *points){
        if(result->getMainItem() == item){
            return result;
        }
    }
    return nullptr;
}

DisplayedSegment *SimulationViewTest::findLineByMainItem(QGraphicsItem *item){
    for(auto result: *lines){
        if(result->getMainItem() == item){
            return result;
        }
    }
    return nullptr;
}

QVector<DisplayedSegment *> SimulationViewTest::getRelatedLines(DisplayedNode *point){
    QVector<DisplayedSegment *> result;

    for(auto line: *lines){
        if(line->getEndPoint() == point || line->getStartPoint() == point){
             result.push_back(line);
        }
    }
    return result;
}


void SimulationViewTest::updateRelatedLines(DisplayedItem *point){
    for(auto line: *lines){
        if(line->getEndPoint() == point || line->getStartPoint() == point){
           line->updateCoordinates();
        }
    }
}

// privater functions ===========================================================================================
DisplayedSegment *SimulationViewTest::createLineBetweenPoints(DisplayedNode *startPoint, DisplayedNode *endPoint){
    DisplayedSegment *line = lineCreator->createSegment(startPoint,endPoint);
    layerManager->getLayerByName(LayerName::line)->addItem(line->getMainItem());

    simulation->insertSegmentToEnd(line->getRealSegment());
    lines->push_back(line);
    return line;
}

DisplayedSegment *SimulationViewTest::createLineBetweenPoints(DisplayedNode *startPoint, DisplayedNode *endPoint, long positioInList){
    DisplayedSegment *line = lineCreator->createSegment(startPoint,endPoint);
    layerManager->getLayerByName(LayerName::line)->addItem(line->getMainItem());

    simulation->insertSegment(line->getRealSegment(),positioInList);
    lines->insert(positioInList,line);

    return line;
}

DisplayedNode *SimulationViewTest::createPoint(QPointF pos, NP::NodePointType type){
    PhysicalPoint *phisicalPosition = new PhysicalPoint();


    phisicalPosition->setLongitude(map->minXValue + map->unitPerPixelX * pos.x());
    phisicalPosition->setLatitude(map->maxYValue - map->unitPerPixelY * pos.y());
    map->getElevationMap()->addHeightToSinglePoint(phisicalPosition);

    DisplayedNode *newItem = pointCreator->ceratePoint(simulation->createTurnNode(phisicalPosition,type),pos);
    newItem->createDescription();

    layerManager->getLayerByName(LayerName::node_point)->addItem(newItem->getMainItem());
    layerManager->getLayerByName(LayerName::text)->addItem(newItem->getText());

    return newItem;
}

DisplayedNode *SimulationViewTest::createPoint(QPointF pos, NP::NodePointType type, long positioInList){
    PhysicalPoint *phisicalPosition = new PhysicalPoint();

    phisicalPosition->setLongitude(map->minXValue + map->unitPerPixelX * pos.x());
    phisicalPosition->setLatitude(map->maxYValue - map->unitPerPixelY * pos.y());
    map->getElevationMap()->addHeightToSinglePoint(phisicalPosition);

    DisplayedNode *newItem = pointCreator->ceratePoint(simulation->createTurnNode(phisicalPosition,type,positioInList),pos);
    newItem->createDescription();

    layerManager->getLayerByName(LayerName::node_point)->addItem(newItem->getMainItem());
    layerManager->getLayerByName(LayerName::text)->addItem(newItem->getText());

    return newItem;
}
