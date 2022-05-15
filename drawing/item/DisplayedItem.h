#ifndef DISPLAYEDPOINT_H
#define DISPLAYEDPOINT_H

#include <QGraphicsPixmapItem>
#include <QString>
#include <simulation/map/PhysicalPoint.h>

enum ItemType{
    Udefinde,
    SegmentItem,
    NodeItem,
    WayPointItem
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

protected:
    ItemType type = ItemType::Udefinde;
    QString name;
    QGraphicsItem *mainItem = nullptr;
    QGraphicsTextItem *text = nullptr;
};

#endif
