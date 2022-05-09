#ifndef VISIBLELAYER_H
#define VISIBLELAYER_H

#include <qgraphicsitem.h>

class VisibleLayer{
public:
    VisibleLayer();
    VisibleLayer(int zOrder);
    VisibleLayer(int zOrder,bool changeble);
    ~VisibleLayer();

    void addItem(QGraphicsItem *item);
    bool contain(QGraphicsItem *item);

    QGraphicsItemGroup *getItemGroupe();
    void setItemGroupe(QGraphicsItemGroup *value);

    void hideGroupe();
    void displayGrouope();

    void clear();

    int getZOrder();
    void setZOrder(int value);

    bool getChangeable();
    void setChangeable(bool value);

protected:
    QGraphicsItemGroup *itemGroupe;

    int zOrder = 0;
    bool changeable = false;
};

#endif // VISIBLELAYER_H
