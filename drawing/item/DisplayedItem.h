#ifndef DISPLAYEDPOINT_H
#define DISPLAYEDPOINT_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <simulation/map/PhysicalPoint.h>

enum ItemType{
    UNDEFINED,
    SEGMENT_ITEM,
    NODE_ITEM,
    WAY_POINT_ITEM
};

class DisplayedItem{
public:

    DisplayedItem();
    DisplayedItem(QGraphicsItem *mainItem);
    ~DisplayedItem();

    void createDescription();

    QGraphicsItem *getMainItem();
    void setMainItem(QGraphicsItem *value);

    QGraphicsTextItem *getText();
    void setText(QGraphicsTextItem *value);

    PhysicalPoint *getCoordinats();
    void setCoordinats(PhysicalPoint *value);

    QString getName();
    void setName(QString &value);

    long getId();
    void setId(long value);

    ItemType type = ItemType::UNDEFINED;
protected:
    long id;
    QString name;
    QGraphicsItem *mainItem = nullptr;
    QGraphicsTextItem *text = nullptr;
};

#endif
