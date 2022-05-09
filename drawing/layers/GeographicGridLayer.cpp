#include "GeographicGridLayer.h"

#include <bits/stl_map.h>

#include <QPen>
#include <QString>

#include <utils/Utils.h>

GeographicGridLayer::GeographicGridLayer(int zOrder) : SelfDrawingLayer(zOrder,false){}

GeographicGridLayer::GeographicGridLayer(int zOrder, bool changeble) : SelfDrawingLayer(zOrder,changeble){}

GeographicGridLayer::GeographicGridLayer(double wight, double hieght, double xIndent, double yIndent) : SelfDrawingLayer( wight, hieght, xIndent, yIndent){}

void GeographicGridLayer::draw(){

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

        Utils::fromUTMToGK(currentLat,maxYValue,x,y);
        y.append("km");

        QGraphicsTextItem *kmText = new QGraphicsTextItem();
        kmText->setX(wight + 10);
        if(i==0){
            kmText->setY(pixelsPerStep * i + yIndent + 20);
        } else if(i== linesPerYAxis - 1){
            kmText->setY(pixelsPerStep * i + yIndent - 10);
        } else{
            kmText->setY(pixelsPerStep * i + yIndent);
        }
        kmText->setPlainText(y);
        kmText->setRotation(-90);

        addItem(kmText);
        addItem(item);
        addItem(text);
    }


    pixelsPerStep =  wight / (linesPerXAxis - 1);
    for(int i=0;i<linesPerXAxis;i++){

        QGraphicsLineItem *line = new QGraphicsLineItem(pixelsPerStep * i,0,pixelsPerStep * i,hieght);
        line->setPen(pen);

        double currentLong = minXValue + degPerPixelX * pixelsPerStep * i;

        Utils::fromUTMToGK(currentLong + 180,minXValue,x,y);
        x.append("km");

        QString angle;
        angle.setNum(currentLong,10,2);
        angle.append("°");

        QGraphicsTextItem *degText = new QGraphicsTextItem();
        QGraphicsTextItem *kmText = new QGraphicsTextItem();

        if(i==0){
            degText->setX(pixelsPerStep * i - xIndent + 10);
            kmText->setX(pixelsPerStep * i - xIndent + 10);
        } else if(i == linesPerXAxis - 1){
            degText->setX(pixelsPerStep * i - xIndent - 10);
            kmText->setX(pixelsPerStep * i - xIndent - 25);
        }else{
            degText->setX(pixelsPerStep * i - xIndent);
            kmText->setX(pixelsPerStep * i - xIndent);
        }

        degText->setY(-yIndent);
        kmText->setY(hieght);

        degText->setPlainText(angle);
        kmText->setPlainText(x);

        addItem(line);
        addItem(degText);
        addItem(kmText);
    }
}
