#include "ItemManager.h"

ItemManager::ItemManager(){
    points = new QVector<DisplayedNodePoint *>;
    lines = new QVector<DisplayedLine *>;
}

ItemManager::ItemManager(SimulationMap *map,LayerManager *layerManager){
    points = new QVector<DisplayedNodePoint *>;
    lines = new QVector<DisplayedLine *>;

    this->layerManager = layerManager;
    this->map = map;
    map->findDegPerPixeRatio();
}

ItemManager::~ItemManager(){
    delete [] points;
    delete [] lines;
}

LayerManager *ItemManager::getLayerManager(){
    return layerManager;
}

void ItemManager::setLayerManager(LayerManager *value){
    layerManager = value;
}

DisplayedNodePoint* ItemManager::addPoint(QPointF pos,QString name,PointType type){

    DisplayedNodePoint *newItem =  pointCreator->ceratePoint(pos,name,type,lastId);
    evaluatePoint(pos,newItem);
    newItem->createDescription();

    this->points->append(newItem);

    lastId++;
    layerManager->getLayerByName(LayerName::node_point)->addItem(newItem->getMainItem());
    layerManager->getLayerByName(LayerName::text)->addItem(newItem->getText());
    return newItem;
}

DisplayedNodePoint *ItemManager::addPoint(QPointF pos, PointType type){

    DisplayedNodePoint *newItem =  pointCreator->ceratePoint(pos,type,lastId);
    evaluatePoint(pos,newItem);
    newItem->createDescription();

    this->points->append(newItem);

    lastId++;

    layerManager->getLayerByName(LayerName::node_point)->addItem(newItem->getMainItem());
    layerManager->getLayerByName(LayerName::text)->addItem(newItem->getText());
    return newItem;
}

DisplayedNodePoint *ItemManager::addPointToLine(DisplayedLine *line, QPointF pos, PointType type){

    DisplayedNodePoint *midlePoint = addPoint(pos,type);

    this->createLineBetweenPoints(line->getStartPoint(),midlePoint);
    this->createLineBetweenPoints(midlePoint,line->getEndPoint());

    this->lines->removeOne(line);
    delete line;
}

void ItemManager::deletePoint(DisplayedNodePoint *point){
    QVector<DisplayedLine *> relatedLines = getRelatedLines(point);

    if(relatedLines.size() == 2){

        DisplayedNodePoint *newStart;
        DisplayedNodePoint *newEnd;

        if(relatedLines.at(0)->getStartPoint()->getId() < relatedLines.at(1)->getStartPoint()->getId()){
            newStart = relatedLines.at(0)->getStartPoint();
        }
        else{
            newStart = relatedLines.at(1)->getStartPoint();
        }

        if(relatedLines.at(0)->getEndPoint()->getId() >= relatedLines.at(1)->getEndPoint()->getId()){
            newEnd = relatedLines.at(0)->getEndPoint();
        }
        else{
            newEnd = relatedLines.at(1)->getEndPoint();
        }

        createLineBetweenPoints(newStart,newEnd);

        lines->removeOne(relatedLines.at(0));
        lines->removeOne(relatedLines.at(1));

        delete relatedLines.at(0);
        delete relatedLines.at(1);
    }

    if(relatedLines.size() == 1){
        lines->removeOne(relatedLines.at(0));
        delete relatedLines.at(0);
    }

    points->removeOne(point);
    delete point;
}

void ItemManager::evaluatePoint(QPointF pos, DisplayedNodePoint *item){

    if(item->getCoordinats() == nullptr){
        item->setCoordinats(new PhysicalPoint());
    }

    item->getCoordinats()->setLongitude(map->getElevationMap()->getMinLongDeg() + SimulationMap::degPerPixelX * pos.x());
    item->getCoordinats()->setLatitude(map->getElevationMap()->getMaxLatDeg() - SimulationMap::degPerPixelY * pos.y());

    map->getElevationMap()->addHeightToSinglePoint(item->getCoordinats());

    item->setPoint(pos);
}


SimulationMap *ItemManager::getMap(){
    return map;
}

void ItemManager::setMap(SimulationMap *value){
    map = value;
}

DisplayedNodePoint *ItemManager::findPointByMainItem(QGraphicsItem *item){
    for(auto result: *points){
        if(result->getMainItem() == item){
            return result;
        }
    }
    return nullptr;
}

DisplayedLine *ItemManager::findLineByMainItem(QGraphicsItem *item){
    for(auto result: *lines){
        if(result->getMainItem() == item){
            return result;
        }
    }
    return nullptr;
}

QVector<DisplayedLine *> ItemManager::getRelatedLines(DisplayedNodePoint *point){
    QVector<DisplayedLine *> result;

    for(auto line: *lines){
        if(line->getEndPoint() == point || line->getStartPoint() == point){
             result.push_back(line);
        }
    }
    return result;
}

void ItemManager::deleteRelatedLines(NamedItem *point){
    for(auto line: *lines){
        if(line->getEndPoint() == point || line->getStartPoint() == point){
            lines->removeOne(line);
            delete line;
        }
    }
}

void ItemManager::updateRelatedLines(NamedItem *point){
    for(auto line: *lines){
        if(line->getEndPoint() == point || line->getStartPoint() == point){
           line->updateCoordinates();
        }
    }
}

DisplayedLine *ItemManager::createLineWithLastPoint(){
    if(points->size() > 1){
        DisplayedLine *line = lineCreator->createLine(points->at(points->size() - 2),(points->at(points->size() - 1)),lastId);
        lines->push_back(line);

        layerManager->getLayerByName(LayerName::lines)->addItem(line->getMainItem());
        return line;
    }
    return nullptr;
}

DisplayedLine *ItemManager::createLineBetweenPoints(DisplayedNodePoint *point1, DisplayedNodePoint *poin2){
    DisplayedLine *line = lineCreator->createLine(point1,poin2,lastId);
    lines->append(line);
    layerManager->getLayerByName(LayerName::lines)->addItem(line->getMainItem());
    return line;
}

