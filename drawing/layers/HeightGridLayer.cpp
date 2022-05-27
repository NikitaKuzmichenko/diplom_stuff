#include "HeightGridLayer.h"

HeightGridLayer::HeightGridLayer(int zOrder) : SelfDrawingLayer(zOrder,false){}

HeightGridLayer::HeightGridLayer(int zOrder, bool changeble) : SelfDrawingLayer(zOrder,changeble){}

HeightGridLayer::HeightGridLayer(double wight, double hieght, double xIndent, double yIndent) : SelfDrawingLayer( wight, hieght, xIndent, yIndent){}

void HeightGridLayer::draw(){

    int pixelsPerStep =  hieght / (linesPerYAxis - 1);

    float degPerPixelY = (maxYValue - minYValue) / hieght;
    float degPerPixelX = (maxXValue - minXValue) / wight;

    QString x;
    QString y;

    for(int i=0;i<linesPerXAxis;i++){
        QGraphicsLineItem *item = new QGraphicsLineItem(0, pixelsPerStep * i, wight, pixelsPerStep * i);
        item->setPen(pen);

        double currentLat = maxYValue - degPerPixelY * pixelsPerStep * i;
        QString angle;
        angle.setNum(currentLat,10,2);
        angle.append("°");

        QGraphicsTextItem *text = new QGraphicsTextItem();
        text->setX(-xIndent - 5);
        text->setY(pixelsPerStep * i + yIndent);
        text->setPlainText(angle);
        text->setRotation(-90);

        addItem(item);
        addItem(text);
    }


    pixelsPerStep =  wight / (linesPerXAxis - 1);
    for(int i=0;i<linesPerXAxis;i++){

        QGraphicsLineItem *line = new QGraphicsLineItem(pixelsPerStep * i,0,pixelsPerStep * i,hieght);
        line->setPen(pen);

        double currentLong = minXValue + degPerPixelX * pixelsPerStep * i;

        QString angle;
        angle.setNum(currentLong,10,2);
        angle.append("°");

        QGraphicsTextItem *degText = new QGraphicsTextItem();

        if(i==0){
            degText->setX(pixelsPerStep * i - xIndent + 10);
        } else if(i == linesPerXAxis - 1){
            degText->setX(pixelsPerStep * i - xIndent - 10);
        }else{
            degText->setX(pixelsPerStep * i - xIndent);
        }

       degText->setY(-yIndent);
       degText->setPlainText(angle);

        addItem(line);
        addItem(degText);

    }
}
