#include "UISegmentInfo.h"

UISegmentInfo::UISegmentInfo(QGraphicsView *container, Simulation *simulation) : UIItemIfo(container,simulation){

    spaseBetween = 3;
    totalHeight = inputHeight + spaseBetween;

    distanceLable = new QLabel("Distance",container);
    distanceLable->setGeometry(offset,spaseBetween,lableWidth,inputHeight);

    distanceInput = new QLineEdit("",container);
    distanceInput->setGeometry(offset * 2 + lableWidth,spaseBetween,inputWidth,inputHeight);
    distanceInput->setReadOnly(true);

    startCourceLable = new QLabel("Start cource",container);
    startCourceLable->setGeometry(offset,(spaseBetween + totalHeight) * 1,lableWidth,inputHeight);

    startCourceInput= new QLineEdit("",container);
    startCourceInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 1,inputWidth,inputHeight);
    startCourceInput->setReadOnly(true);

    endCourceLable = new QLabel("Finish cource",container);
    endCourceLable->setGeometry(offset,(spaseBetween + totalHeight) * 2,lableWidth,inputHeight);

    endCourceInput = new QLineEdit("",container);
    endCourceInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 2,inputWidth,inputHeight);
    endCourceInput->setReadOnly(true);
// =================================================================== statr point
    startPointLable = new QLabel("Start node :",container);
    startPointLable->setGeometry(offset,(spaseBetween + totalHeight) * 3,lableWidth,inputHeight);

    startLatitudeLable = new QLabel("Start latitude",container);
    startLatitudeLable->setGeometry(offset * 1.5,(spaseBetween + totalHeight) * 4,lableWidth,inputHeight);

    startLatitudeInput = new QLineEdit("",container);
    startLatitudeInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 4,inputWidth,inputHeight);
    startLatitudeInput->setReadOnly(true);

    startLongitudeLable = new QLabel("Start longitude",container);
    startLongitudeLable->setGeometry(offset * 1.5,(spaseBetween + totalHeight) * 5,lableWidth,inputHeight);

    startLongitudeInput = new QLineEdit("",container);
    startLongitudeInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 5,inputWidth,inputHeight);
    startLongitudeInput->setReadOnly(true);

    startHeightLable = new QLabel("Start height",container);
    startHeightLable->setGeometry(offset * 1.5,(spaseBetween + totalHeight) * 6,lableWidth,inputHeight);

    startHeightInput = new QLineEdit("",container);
    startHeightInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 6,inputWidth,inputHeight);
    startHeightInput->setReadOnly(true);
// =================================================================== end point
    endPointPointLable = new QLabel("End node :",container);
    endPointPointLable->setGeometry(offset,(spaseBetween + totalHeight)  * 7,lableWidth,inputHeight);

    endLatitudeLable = new QLabel("End latitude",container);
    endLatitudeLable->setGeometry(offset * 1.5,(spaseBetween + totalHeight)  * 8,lableWidth,inputHeight);

    endLatitudeInput = new QLineEdit("",container);
    endLatitudeInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 8,inputWidth,inputHeight);
    endLatitudeInput->setReadOnly(true);

    endLongitudeLable = new QLabel("End longitude",container);
    endLongitudeLable->setGeometry(offset * 1.5,(spaseBetween + totalHeight)  * 9,lableWidth,inputHeight);

    endLongitudeInput = new QLineEdit("",container);
    endLongitudeInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 9,inputWidth,inputHeight);
    endLongitudeInput->setReadOnly(true);

    endLeightLable = new QLabel("End height",container);
    endLeightLable->setGeometry(offset * 1.5,(spaseBetween + totalHeight) * 10,lableWidth,inputHeight);

    endLeightInput = new QLineEdit("",container);
    endLeightInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 10,inputWidth,inputHeight);
    endLeightInput->setReadOnly(true);
}

UISegmentInfo::~UISegmentInfo(){
    delete distanceLable;
    delete distanceInput;

    delete startCourceLable;
    delete startCourceInput;

    delete endCourceLable;
    delete endCourceInput;

    delete startPointLable;

    delete startLatitudeLable;
    delete startLatitudeInput;

    delete startLongitudeLable;
    delete startLongitudeInput;

    delete startHeightLable;
    delete startHeightInput;

    delete endPointPointLable;

    delete endLatitudeLable;
    delete endLatitudeInput;

    delete endLongitudeLable;
    delete endLongitudeInput;

    delete endLeightLable;
    delete endLeightInput;
}

void UISegmentInfo::displayItem(Segment *item){
    distanceInput->setText(QString::number(item->lenght,'f',3));

    startCourceInput->setText(QString::number(item->startCource,'f',3));

    endCourceInput->setText(QString::number(item->endCource,'f',3));

    startLatitudeInput->setText(QString::number(item->getStartPoint()->getPoint()->getLatitude(),'f',3));

    startLongitudeInput->setText(QString::number(item->getStartPoint()->getPoint()->getLongitude(),'f',3));

    startHeightInput->setText(QString::number(item->getStartPoint()->getPoint()->getHight(),'f',3));

    endLatitudeInput->setText(QString::number(item->getEndPoint()->getPoint()->getLatitude(),'f',3));

    endLongitudeInput->setText(QString::number(item->getEndPoint()->getPoint()->getLongitude(),'f',3));

    endLeightInput->setText(QString::number(item->getEndPoint()->getPoint()->getHight(),'f',3));
}

void UISegmentInfo::hide(){
    distanceLable->hide();
    distanceInput->hide();

    startCourceLable->hide();
    startCourceInput->hide();

    endCourceLable->hide();
    endCourceInput->hide();

    startPointLable->hide();

    startLatitudeLable->hide();
    startLatitudeInput->hide();

    startLongitudeLable->hide();
    startLongitudeInput->hide();

    startHeightLable->hide();
    startHeightInput->hide();

    endPointPointLable->hide();

    endLatitudeLable->hide();
    endLatitudeInput->hide();

    endLongitudeLable->hide();
    endLongitudeInput->hide();

    endLeightLable->hide();
    endLeightInput->hide();
}

void UISegmentInfo::show(){

    distanceLable->show();
    distanceInput->show();

    startCourceLable->show();
    startCourceInput->show();

    endCourceLable->show();
    endCourceInput->show();

    startPointLable->show();

    startLatitudeLable->show();
    startLatitudeInput->show();

    startLongitudeLable->show();
    startLongitudeInput->show();

    startHeightLable->show();
    startHeightInput->show();

    endPointPointLable->show();

    endLatitudeLable->show();
    endLatitudeInput->show();

    endLongitudeLable->show();
    endLongitudeInput->show();

    endLeightLable->show();
    endLeightInput->show();
}

void UISegmentInfo::clearInputs(){}
