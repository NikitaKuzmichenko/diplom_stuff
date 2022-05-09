#ifndef SELFDRAWINGLAYER_H
#define SELFDRAWINGLAYER_H

#include "VisibleLayer.h"
#include<QPen>

class SelfDrawingLayer : public  VisibleLayer{
public:
    SelfDrawingLayer();
    SelfDrawingLayer(int zOrder);
    SelfDrawingLayer(int zOrder, bool changeble);
    SelfDrawingLayer(double wight,double hieght,double xIndent, double yIndent);

    double getXIndent();
    void setXIndent(double value);

    double getYIndent();
    void setYIndent(double value);

    double getHieght();
    void setHieght(double value);

    double getWight();
    void setWight(double value);

    int getLinesPerYAxis();
    void setLinesPerYAxis(int value);

    int getLinesPerXAxis();
    void setLinesPerXAxis(int value);

    QPen getPen();
    void setPen(QPen value);

    double getMinYValue();
    void setMinYValue(double value);

    double getMaxYValue();
    void setMaxYValue(double value);

    double getMinXValue();
    void setMinXValue(double value);

    double getMaxXValue();
    void setMaxXValue(double value);

    virtual void draw() = 0;
    void redraw();

protected:
    QPen pen;

    int linesPerYAxis;
    int linesPerXAxis;

    double minYValue;
    double maxYValue;

    double minXValue;
    double maxXValue;

    double wight;
    double hieght;

    double xIndent;
    double yIndent;
};

#endif // SELFDRAWINGLAYER_H
