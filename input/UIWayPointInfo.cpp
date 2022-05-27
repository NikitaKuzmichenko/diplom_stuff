#include "UIWayPointInfo.h"
#include "QMetaEnum"

UIWayPointInfo::UIWayPointInfo(QGraphicsView *container, Simulation *simulation) : UIItemIfo(container,simulation){

    spaseBetween = 2;
    totalHeight = inputHeight + spaseBetween;

    typeLable = new QLabel("Way point type",container);
    typeLable->setGeometry(offset,spaseBetween,lableWidth,inputHeight);

    typeInput = new QLineEdit("",container);
    typeInput->setGeometry(offset * 2 + lableWidth,spaseBetween,inputWidth,inputHeight);
    typeInput->setReadOnly(true);

    latitudaLable = new QLabel("Latitude",container);
    latitudaLable->setGeometry(offset,(spaseBetween + totalHeight) * 1,lableWidth,inputHeight);

    latitudaInput = new QLineEdit("",container);
    latitudaInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 1,inputWidth,inputHeight);
    latitudaInput->setReadOnly(true);

    longitudeLable = new QLabel("Longitude",container);
    longitudeLable->setGeometry(offset,(spaseBetween + totalHeight) * 2,lableWidth,inputHeight);

    longitudeInput = new QLineEdit("",container);
    longitudeInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 2,inputWidth,inputHeight);
    longitudeInput->setReadOnly(true);

    heightLable = new QLabel("Height",container);
    heightLable->setGeometry(offset,(spaseBetween + totalHeight) * 3,lableWidth,inputHeight);

    heightInput = new QLineEdit("",container);
    heightInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 3,inputWidth,inputHeight);
    heightInput->setReadOnly(true);

    newHLable = new QLabel("Nex point height",container);
    newHLable->setGeometry(offset,(spaseBetween + totalHeight) * 4,lableWidth,inputHeight);

    newHInput = new QLineEdit("",container);
    newHInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 4,inputWidth,inputHeight);
    newHInput->setReadOnly(true);

    thetaLable = new QLabel("Theta",container);
    thetaLable->setGeometry(offset,(spaseBetween + totalHeight) * 5,lableWidth,inputHeight);

    thetaInput = new QLineEdit("",container);
    thetaInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 5,inputWidth,inputHeight);
    thetaInput->setReadOnly(true);

    psiLable = new QLabel("Psi",container);
    psiLable->setGeometry(offset,(spaseBetween + totalHeight) * 6,lableWidth,inputHeight);

    psiInput = new QLineEdit("",container);
    psiInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 6,inputWidth,inputHeight);
    psiInput->setReadOnly(true);

    gammaLable = new QLabel("Gamma",container);
    gammaLable->setGeometry(offset,(spaseBetween + totalHeight) * 7,lableWidth,inputHeight);

    gammaInput = new QLineEdit("",container);
    gammaInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 7,inputWidth,inputHeight);
    gammaInput->setReadOnly(true);

    ailerionLable = new QLabel("Ailerion",container);
    ailerionLable->setGeometry(offset,(spaseBetween + totalHeight) * 8,lableWidth,inputHeight);

    ailerionInput = new QLineEdit("",container);
    ailerionInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 8,inputWidth,inputHeight);
    ailerionInput->setReadOnly(true);

    alphaLable = new QLabel("Alpha",container);
    alphaLable->setGeometry(offset,(spaseBetween + totalHeight) * 9,lableWidth,inputHeight);

    alphaInput = new QLineEdit("",container);
    alphaInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 9,inputWidth,inputHeight);
    alphaInput->setReadOnly(true);

    icLable = new QLabel("Interceptor",container);
    icLable->setGeometry(offset,(spaseBetween + totalHeight) * 10,lableWidth,inputHeight);

    icInput = new QLineEdit("",container);
    icInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 10,inputWidth,inputHeight);
    icInput->setReadOnly(true);

    thrustLable = new QLabel("Thrust",container);
    thrustLable->setGeometry(offset,(spaseBetween + totalHeight) * 11,lableWidth,inputHeight);

    thrustInput = new QLineEdit("",container);
    thrustInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + totalHeight) * 11,inputWidth,inputHeight);
    thrustInput->setReadOnly(true);
}

UIWayPointInfo::~UIWayPointInfo(){
    delete typeLable;
    delete typeInput;

    delete latitudaLable;
    delete latitudaInput;

    delete longitudeLable;
    delete longitudeInput;

    delete heightLable;
    delete heightInput;

    delete newHLable;
    delete newHInput;

    delete thetaLable;
    delete thetaInput;

    delete psiLable;
    delete psiInput;

    delete gammaLable;
    delete gammaInput;

    delete ailerionLable;
    delete ailerionInput;

    delete alphaLable;
    delete alphaInput;

    delete icLable;
    delete icInput;

    delete thrustLable;
    delete thrustInput;
}

void UIWayPointInfo::displayWayPoint(WayPoint *point){
    typeInput->setText(QMetaEnum::fromType<WP::WayPointType>().valueToKey(point->type));
    latitudaInput->setText(QString::number(point->point->getLatitude(),'f',3));
    longitudeInput->setText(QString::number(point->point->getLongitude(),'f',3));
    heightInput->setText(QString::number(point->point->getHight(),'f',3));
    newHInput->setText(QString::number(point->h2,'f',3));
    thetaInput->setText(QString::number(point->Theta,'f',3));
    psiInput->setText(QString::number(point->Psi,'f',3));
    gammaInput->setText(QString::number(point->gamma,'f',3));
    ailerionInput->setText(QString::number(point->aileron,'f',3));
    alphaInput->setText(QString::number(point->alpha,'f',3));
    icInput->setText(QString::number(point->interceptor,'f',3));
    thrustInput->setText(QString::number(point->thrust,'f',3));
}

void UIWayPointInfo::hide(){
    typeLable->hide();
    typeInput->hide();

    latitudaLable->hide();
    latitudaInput->hide();

    longitudeLable->hide();
    longitudeInput->hide();

    heightLable->hide();
    heightInput->hide();

    newHLable->hide();
    newHInput->hide();

    thetaLable->hide();
    thetaInput->hide();

    psiLable->hide();
    psiInput->hide();

    gammaLable->hide();
    gammaInput->hide();

    ailerionLable->hide();
    ailerionInput->hide();

    alphaLable->hide();
    alphaInput->hide();

    icLable->hide();
    icInput->hide();

    thrustLable->hide();
    thrustInput->hide();
}

void UIWayPointInfo::show(){
    typeLable->show();
    typeInput->show();

    latitudaLable->show();
    latitudaInput->show();

    longitudeLable->show();
    longitudeInput->show();

    heightLable->show();
    heightInput->show();

    newHLable->show();
    newHInput->show();

    thetaLable->show();
    thetaInput->show();

    psiLable->show();
    psiInput->show();

    gammaLable->show();
    gammaInput->show();

    ailerionLable->show();
    ailerionInput->show();

    alphaLable->show();
    alphaInput->show();

    icLable->show();
    icInput->show();

    thrustLable->show();
    thrustInput->show();
}

void UIWayPointInfo::clearInputs(){

}
