#include "SimulationView.h"

SimulationView::SimulationView(Simulation *simulation, LayerManager *layerManager,PlaneViewMapper *map){
    this->simulation = simulation;
    this->map = map;
    map->calculateUnitPerPixeRatio();
    this->layerManager = layerManager;

    points = new QVector<DisplayedNodePoint *>;
    lines = new QVector<DisplayedSegment *>;
}

SimulationView::~SimulationView(){
    delete pointCreator;
    delete pointCreator;
    delete [] points;
    delete [] lines;
}

PlaneViewMapper *SimulationView::getMap(){
    return map;
}

void SimulationView::setMap(PlaneViewMapper *value){
    map = value;
}

// constuctor functions ===========================================================================================

DisplayedNodePoint *SimulationView::addPoint(QPointF pos, NodePointType type){
    DisplayedNodePoint *newItem = createPoint(pos,type);
    points->append(newItem);
    return newItem;
}

DisplayedSegment *SimulationView::createLineWithLastPoint(){
    if(points->size() > 1){
        DisplayedSegment *line = createLineBetweenPoints(points->at(points->size() - 2),(points->at(points->size() - 1)));
        return line;
    }
    return nullptr;
}

DisplayedNodePoint *SimulationView::addPointToLine(DisplayedSegment *line, QPointF pos, NodePointType type){

    long midlePosition = (points->indexOf(line->getStartPoint()) + points->indexOf(line->getEndPoint())) / 2;
    DisplayedNodePoint *midlePoint = createPoint(pos,type,midlePosition + 1);
    points->insert(midlePosition + 1,midlePoint);

    long linePosisition = lines->indexOf(line);

    createLineBetweenPoints(line->getStartPoint(),midlePoint,linePosisition);
    createLineBetweenPoints(midlePoint,line->getEndPoint(),linePosisition + 1);

    lines->removeOne(line);
    simulation->removeSegment(line->getRealSegment());

    delete line;
    return midlePoint;
}

void SimulationView::deletePoint(DisplayedNodePoint *point){
    QVector<DisplayedSegment *> relatedLines = getRelatedLines(point);

    if(relatedLines.size() == 2){
        DisplayedNodePoint *newStart;
        DisplayedNodePoint *newEnd;

        newStart = relatedLines.at(0)->getStartPoint();
        newEnd = relatedLines.at(1)->getEndPoint();

        long posotionInList = (lines->indexOf(relatedLines.at(0)) + lines->indexOf(relatedLines.at(1))) / 2;

        lines->removeOne(relatedLines.at(0));
        simulation->removeSegment(relatedLines.at(0)->getRealSegment());
        delete relatedLines.at(0);

        lines->removeOne(relatedLines.at(1));
        simulation->removeSegment(relatedLines.at(1)->getRealSegment());
        delete relatedLines.at(1);

        createLineBetweenPoints(newStart,newEnd,posotionInList);
    }
    if(relatedLines.size() == 1){
        lines->removeOne(relatedLines.at(0));
        simulation->removeSegment(relatedLines.at(0)->getRealSegment());
        delete relatedLines.at(0);
    }

    simulation->removeNode(point->getNode());
    points->removeOne(point);
    delete point;
}


// utils functions ===========================================================================================
void SimulationView::evaluatePoint(QPointF pos, DisplayedNodePoint *item){
    if(item->getNode() == nullptr){
        return;
    }

    item->getNode()->getPoint()->setLongitude(map->getElevationMap()->getMinLongDeg() + map->getUnitPerPixelX() * pos.x());
    item->getNode()->getPoint()->setLatitude(map->getElevationMap()->getMaxLatDeg() - map->getUnitPerPixelY() * pos.y());
    map->getElevationMap()->addHeightToSinglePoint(item->getNode()->getPoint());

    item->setPosition(pos);
}

DisplayedNodePoint *SimulationView::findPointByMainItem(QGraphicsItem *item){
    for(auto result: *points){
        if(result->getMainItem() == item){
            return result;
        }
    }
    return nullptr;
}

DisplayedSegment *SimulationView::findLineByMainItem(QGraphicsItem *item){
    for(auto result: *lines){
        if(result->getMainItem() == item){
            return result;
        }
    }
    return nullptr;
}

QVector<DisplayedSegment *> SimulationView::getRelatedLines(DisplayedNodePoint *point){
    QVector<DisplayedSegment *> result;

    for(auto line: *lines){
        if(line->getEndPoint() == point || line->getStartPoint() == point){
             result.push_back(line);
        }
    }
    return result;
}


void SimulationView::updateRelatedLines(DisplayedItem *point){
    for(auto line: *lines){
        if(line->getEndPoint() == point || line->getStartPoint() == point){
           line->updateCoordinates();
        }
    }
}

// privater functions ===========================================================================================
DisplayedSegment *SimulationView::createLineBetweenPoints(DisplayedNodePoint *startPoint, DisplayedNodePoint *endPoint){
    DisplayedSegment *line = lineCreator->createSegment(startPoint,endPoint);
    layerManager->getLayerByName(LayerName::lines)->addItem(line->getMainItem());

    simulation->insertSegmentToEnd(line->getRealSegment());
    lines->push_back(line);
    return line;
}

DisplayedSegment *SimulationView::createLineBetweenPoints(DisplayedNodePoint *startPoint, DisplayedNodePoint *endPoint, long positioInList){
    DisplayedSegment *line = lineCreator->createSegment(startPoint,endPoint);
    layerManager->getLayerByName(LayerName::lines)->addItem(line->getMainItem());

    simulation->insertSegment(line->getRealSegment(),positioInList);
    lines->insert(positioInList,line);

    return line;
}

DisplayedNodePoint *SimulationView::createPoint(QPointF pos, NodePointType type){
    PhysicalPoint *phisicalPosition = new PhysicalPoint();

    phisicalPosition->setLongitude(map->getElevationMap()->getMinLongDeg() + map->getUnitPerPixelX() * pos.x());
    phisicalPosition->setLatitude(map->getElevationMap()->getMaxLatDeg() - map->getUnitPerPixelY() * pos.y());
    map->getElevationMap()->addHeightToSinglePoint(phisicalPosition);

    DisplayedNodePoint *newItem = pointCreator->ceratePoint(simulation->addNodePoint(phisicalPosition,type),pos);
    newItem->createDescription();

    layerManager->getLayerByName(LayerName::node_point)->addItem(newItem->getMainItem());
    layerManager->getLayerByName(LayerName::text)->addItem(newItem->getText());

    return newItem;
}

DisplayedNodePoint *SimulationView::createPoint(QPointF pos, NodePointType type, long positioInList){
    PhysicalPoint *phisicalPosition = new PhysicalPoint();

    phisicalPosition->setLongitude(map->getElevationMap()->getMinLongDeg() + map->getUnitPerPixelX() * pos.x());
    phisicalPosition->setLatitude(map->getElevationMap()->getMaxLatDeg() - map->getUnitPerPixelY() * pos.y());
    map->getElevationMap()->addHeightToSinglePoint(phisicalPosition);

    DisplayedNodePoint *newItem = pointCreator->ceratePoint(simulation->addNodePoint(phisicalPosition,type,positioInList),pos);
    newItem->createDescription();

    layerManager->getLayerByName(LayerName::node_point)->addItem(newItem->getMainItem());
    layerManager->getLayerByName(LayerName::text)->addItem(newItem->getText());

    return newItem;
}
