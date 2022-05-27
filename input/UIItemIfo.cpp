#include "UIItemIfo.h"

UIItemIfo::UIItemIfo(QGraphicsView *container, Simulation *simulation){
    this->container = container;
    this->simulation = simulation;
}

UIItemIfo::~UIItemIfo(){
    delete simulation;
    delete container;
}
