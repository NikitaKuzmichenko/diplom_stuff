#include "UINodeInfo.h"
#include "QMetaEnum"

#include <simulation/node/ClimbNode.h>
#include <simulation/node/CruiseNode.h>
#include <simulation/node/DemNode.h>
#include <simulation/node/DescentNode.h>
#include <simulation/node/ImgNode.h>
#include <simulation/node/TakeoffNode.h>
#include <simulation/node/TurnNode.h>
#include <drawing/scene/ClicableScene.h>

UINodeInfo::UINodeInfo(QGraphicsView *container, Simulation *simulation) : UIItemIfo(container,simulation){
    nodeTypeLable = new QLabel("Node Point Type",container);
    nodeTypeLable->setGeometry(offset,spaseBetween,lableWidth,inputHeight);

    latitudeLable = new QLabel("Latityde",container);
    latitudeLable->setGeometry(offset,spaseBetween + (totalHeight) * 1,lableWidth,inputHeight);

    longitudeLable = new QLabel("Longitude",container);
    longitudeLable->setGeometry(offset,spaseBetween + (totalHeight) * 2,lableWidth,inputHeight);

    heightLable = new QLabel("Hieght",container);
    heightLable->setGeometry(offset,spaseBetween + (totalHeight) * 3,lableWidth,inputHeight);

    speedLable = new QLabel("Speed",container);
    speedLable->setGeometry(offset,spaseBetween + (totalHeight) * 4,lableWidth,inputHeight);

    newHeightLable = new QLabel("New hieght ",container);
    newHeightLable->setGeometry(offset,spaseBetween + (totalHeight) * 5,lableWidth,inputHeight);

    thetaLable = new QLabel("Theta",container);
    thetaLable->setGeometry(offset,spaseBetween + (totalHeight) * 6,lableWidth,inputHeight);

    turnRadiusLable = new QLabel("Turn radius",container);
    turnRadiusLable->setGeometry(offset,spaseBetween + (totalHeight) * 5,lableWidth,inputHeight);

    psiLable = new QLabel("Psi",container);
    psiLable->setGeometry(offset,spaseBetween + (totalHeight) * 6,lableWidth,inputHeight);

    zonLenLable = new QLabel("Zone length",container);
    zonLenLable->setGeometry(offset,spaseBetween + (totalHeight) * 5,lableWidth,inputHeight);

    zonWidthLable = new QLabel("Zone width",container);
    zonWidthLable->setGeometry(offset,spaseBetween + (totalHeight) * 6,lableWidth,inputHeight);

    azimuthLable = new QLabel("Azimuth",container);
    azimuthLable->setGeometry(offset,spaseBetween + (totalHeight) * 7,lableWidth,inputHeight);

    filePathLable = new QLabel("File path",container);
    filePathLable->setGeometry(offset,spaseBetween + (totalHeight) * 8,lableWidth,inputHeight);

    segmentIdLable= new QLabel("Segment id",container);
    segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 9,lableWidth,inputHeight);

    QDoubleValidator *angleValidator = new QDoubleValidator();
    angleValidator->setRange(-90,90,6);
    angleValidator->setNotation(QDoubleValidator::StandardNotation);

    QDoubleValidator *longitudelidator = new QDoubleValidator();
    longitudelidator->setRange(-180,180,6);
    longitudelidator->setNotation(QDoubleValidator::StandardNotation);

    QDoubleValidator *positiveNubmer = new QDoubleValidator();
    positiveNubmer->setBottom(0);
    positiveNubmer->setNotation(QDoubleValidator::StandardNotation);

    nodeTypeInput = new QComboBox(container);
    nodeTypeInput->setGeometry(offset * 2 + lableWidth,spaseBetween,inputWidth,inputHeight);

    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(0));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(1));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(2));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(3));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(4));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(5));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(6));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(7));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(8));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(9));
    nodeTypeInput->addItem(QMetaEnum::fromType<NP::NodePointType>().valueToKey(10));

    latitudeInput = new QLineEdit("",container);
    latitudeInput->setGeometry(offset * 2 + lableWidth,(spaseBetween + (totalHeight)) * 1,inputWidth,inputHeight);
    latitudeInput->setValidator(angleValidator);

    longitudeInput = new QLineEdit("",container);
    longitudeInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 2,inputWidth,inputHeight);
    longitudeInput->setValidator(longitudelidator);

    heightInput = new QLineEdit("",container);
    heightInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 3,inputWidth,inputHeight);
    heightInput->setValidator(positiveNubmer);

    speedInput = new QLineEdit("",container);
    speedInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 4,inputWidth,inputHeight);
    speedInput->setValidator(positiveNubmer);

    newHeightInput = new QLineEdit("",container);
    newHeightInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 5,inputWidth,inputHeight);
    newHeightInput->setValidator(positiveNubmer);

    thetaInput = new QLineEdit("",container);
    thetaInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 6,inputWidth,inputHeight);
    thetaInput->setReadOnly(true);

    turnRadiusInput = new QLineEdit("",container);
    turnRadiusInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 5,inputWidth,inputHeight);
    turnRadiusInput->setReadOnly(true);

    psiInput = new QLineEdit("",container);
    psiInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 6,inputWidth,inputHeight);
    psiInput->setValidator(angleValidator);

    zonLenInput = new QLineEdit("",container);
    zonLenInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 5,inputWidth,inputHeight);
    zonLenInput->setValidator(positiveNubmer);

    zonWidthInput = new QLineEdit("",container);
    zonWidthInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 6,inputWidth,inputHeight);
    zonWidthInput->setValidator(positiveNubmer);

    azimuthInput = new QLineEdit("",container);
    azimuthInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 7,inputWidth,inputHeight);
    azimuthInput->setValidator(angleValidator);

    filePathInput = new QLineEdit("",container);
    filePathInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 8,inputWidth,inputHeight);

    segmentIdInput = new QLineEdit("",container);
    segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 9,inputWidth,inputHeight);

    saveButton = new QPushButton("Save",container);
    saveButton->setGeometry(offset,spaseBetween + (totalHeight) * 10,lableWidth,inputHeight);
    saveButton->setStyleSheet("QAbstractButton { border: 1px outset }");

    QObject::connect(saveButton,&QPushButton::clicked,this,&UINodeInfo::save);

    QObject::connect(nodeTypeInput,&QComboBox::currentIndexChanged,this,&UINodeInfo::typeChange);
}

UINodeInfo::~UINodeInfo(){
    delete nodeTypeLable;
    delete nodeTypeInput;

    delete latitudeLable;
    delete latitudeInput;

    delete longitudeLable;
    delete longitudeInput;

    delete heightLable;
    delete heightInput;

    delete speedLable;
    delete speedInput;

    delete newHeightLable;
    delete newHeightInput;

    delete thetaLable;
    delete thetaInput;

    delete turnRadiusLable;
    delete turnRadiusInput;

    delete psiLable;
    delete psiInput;

    delete zonLenLable;
    delete zonLenInput;

    delete zonWidthLable;
    delete zonWidthInput;

    delete azimuthLable;
    delete azimuthInput;

    delete filePathLable;
    delete filePathInput;

    delete segmentIdLable;
    delete segmentIdInput;

    delete saveButton;
}

void UINodeInfo::reset(){
}

void UINodeInfo::save(){
    NP::NodePointType oldType = node->type;
    NP::NodePointType newType = NP::NodePointType(nodeTypeInput->currentIndex());
    if(oldType == newType){
        node->getPoint()->setHight(heightInput->text().toDouble());
        node->getPoint()->setLatitude(latitudeInput->text().toDouble());
        node->getPoint()->setLongitude(longitudeInput->text().toDouble());

        switch (node->type) {
            case NP::DEM_NODE:{
                DemNode *castedNode = (DemNode *)node;
                castedNode->setV(speedInput->text().toDouble());
                castedNode->setAzim(azimuthInput->text().toDouble());
                castedNode->setLen(zonLenInput->text().toDouble());
                castedNode->setWidth(zonWidthInput->text().toDouble());
                break;
            }

            case NP::IMG_NODE:{
                ImgNode *castedNode = (ImgNode *)node;
                castedNode->setV(speedInput->text().toDouble());
                castedNode->setAzim(azimuthInput->text().toDouble());
                castedNode->setLen(zonLenInput->text().toDouble());
                castedNode->setWidth(zonWidthInput->text().toDouble());
                break;
            }

            case NP::TURN_NODE:{
                TurnNode *castedNode = (TurnNode *)node;
                castedNode->setV(speedInput->text().toDouble());
                castedNode->setR(turnRadiusInput->text().toDouble());
                castedNode->setPsi(psiInput->text().toDouble());
                break;
            }

            case NP::CLIMB_NODE:{
                ClimbNode *castedNode = (ClimbNode *)node;
                castedNode->setV(speedInput->text().toDouble());
                castedNode->setNewH(newHeightInput->text().toDouble());
                castedNode->setTheta(thetaInput->text().toDouble());
                break;
            }

            case NP::CRUISE_NODE:{
                CruiseNode *castedNode = (CruiseNode *)node;
                castedNode->setV(speedInput->text().toDouble());
                break;
            }

            case NP::DESCENT_NODE:{
                DescentNode *castedNode = (DescentNode *)node;
                castedNode->setV(speedInput->text().toDouble());
                castedNode->setNewH(newHeightInput->text().toDouble());
                castedNode->setTheta(thetaInput->text().toDouble());
                break;
            }

            case NP::TAKEOFF_NODE:{
                TakeoffNode *castedNode = (TakeoffNode *)node;
                castedNode->setV(speedInput->text().toDouble());
                break;
            }

            default: break;
        }

        simulation->updateNode(node->getId());
    }
    else{
        simulation->changeNodeType(node->getId(),newType);
    }
}

void UINodeInfo::typeChange(int index){
    displayTypedNode(NP::NodePointType(index));
    if(node != nullptr){
        displayNode(node,NP::NodePointType(index));
    }
}

void UINodeInfo::displayTypedNode(NP::NodePointType type){
    hide();
    clearInputs();
    displayButtons();

    nodeTypeLable->show();
    nodeTypeInput->show();
    nodeTypeInput->setCurrentIndex(type);

    latitudeLable->show();
    latitudeInput->show();

    longitudeLable->show();
    longitudeInput->show();

    heightLable->show();
    heightInput->show();

    switch (type) {
        case NP::DEM_NODE:
            speedLable->show();
            speedInput->show();

            azimuthLable->show();
            azimuthInput->show();

            zonLenLable->show();
            zonLenInput->show();

            zonWidthLable->show();
            zonWidthInput->show();

            filePathLable->show();
            filePathInput->show();

            segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 9,lableWidth,inputHeight);
            segmentIdLable->show();

            segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 9,inputWidth,inputHeight);
            segmentIdInput->show();

            break;
        case NP::IMG_NODE:
            speedLable->show();
            speedInput->show();

            azimuthLable->show();
            azimuthInput->show();

            zonLenLable->show();
            zonLenInput->show();

            zonWidthLable->show();
            zonWidthInput->show();

            filePathLable->show();
            filePathInput->show();

            segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 9,lableWidth,inputHeight);
            segmentIdLable->show();

            segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 9,inputWidth,inputHeight);
            segmentIdInput->show();
            break;

        case NP::TURN_NODE:
            speedLable->show();
            speedInput->show();

            turnRadiusLable->show();
            turnRadiusInput->show();

            psiLable->show();
            psiInput->show();

            segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 7,lableWidth,inputHeight);
            segmentIdLable->show();

            segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 7,inputWidth,inputHeight);
            segmentIdInput->show();
            break;

        case NP::CLIMB_NODE:
            speedLable->show();
            speedInput->show();

            newHeightLable->show();
            newHeightInput->show();

            thetaLable->show();
            thetaInput->show();

            segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 7,lableWidth,inputHeight);
            segmentIdLable->show();

            segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 7,inputWidth,inputHeight);
            segmentIdInput->show();
            break;

        case NP::EVENT_NODE:
            segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 4,lableWidth,inputHeight);
            segmentIdLable->show();

            segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 4,inputWidth,inputHeight);
            segmentIdInput->show();
            break;

        case NP::CRUISE_NODE:
            speedLable->show();
            speedInput->show();

            segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 5,lableWidth,inputHeight);
            segmentIdLable->show();

            segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 5,inputWidth,inputHeight);
            segmentIdInput->show();
            break;

        case NP::FINISH_NODE:
        // nothing
        break;
        case NP::MARKER_NODE:
            segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 4,lableWidth,inputHeight);
            segmentIdLable->show();

            segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 4,inputWidth,inputHeight);
            segmentIdInput->show();
            break;

        case NP::DESCENT_NODE:
            speedLable->show();
            speedInput->show();

            newHeightLable->show();
            newHeightInput->show();

            thetaLable->show();
            thetaInput->show();

            segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 7,lableWidth,inputHeight);
            segmentIdLable->show();

            segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 7,inputWidth,inputHeight);
            segmentIdInput->show();
            break;

        case NP::TAKEOFF_NODE:
            speedLable->show();
            speedInput->show();

            segmentIdLable->setGeometry(offset,spaseBetween + (totalHeight) * 5,lableWidth,inputHeight);
            segmentIdLable->show();

            segmentIdInput->setGeometry(offset * 2 + lableWidth,spaseBetween + (totalHeight) * 5,inputWidth,inputHeight);
            segmentIdInput->show();
            break;

        case NP::UNDEFINED_NODE:
            break;

        default: break;
    }
}

void UINodeInfo::displayNode(NodePoint *node,NP::NodePointType type){
    this->node = node;
    displayTypedNode(type);
    displayGeneralInfo(node);
    switch (type) {
        case NP::DEM_NODE:
            displayDemNode(node);
            break;

        case NP::IMG_NODE:
            displayImgNode(node);
            break;

        case NP::TURN_NODE:
            displayTurnNode(node);
            break;

        case NP::CLIMB_NODE:
            displayClimbNode(node);
            break;

        case NP::EVENT_NODE:
            displayMarkerNode(node);
            break;

        case NP::CRUISE_NODE:
            displayCruiseNode(node);
            break;

        case NP::FINISH_NODE:
            displayFinishNode(node);
            break;

        case NP::MARKER_NODE:
            displayMarkerNode(node);
            break;

        case NP::DESCENT_NODE:
            displayDescendNode(node);
            break;

        case NP::TAKEOFF_NODE:
            displayTakeOffNode(node);
            break;

        case NP::UNDEFINED_NODE:
            break;

        default: break;
    }

}

void UINodeInfo::displayButtons(){
    saveButton->show();
}

void UINodeInfo::hideButtons(){
    saveButton->hide();
}

void UINodeInfo::displayGeneralInfo(NodePoint *node){
    latitudeInput->setText(QString::number(node->getPoint()->getLatitude(),'f',3));
    longitudeInput->setText(QString::number(node->getPoint()->getLongitude(),'f',3));
    heightInput->setText(QString::number(node->getPoint()->getHight(),'f',3));
    if(node->getSegmentId() >= 0){
        segmentIdInput->setText(QString::number(node->getSegmentId()));
    }
}

void UINodeInfo::displayClimbNode(NodePoint *node){
    ClimbNode *newNode = (ClimbNode*)node;
    speedInput->setText(QString::number(newNode->getV(),'f',3));
    newHeightInput->setText(QString::number(newNode->getNewH(),'f',3));
    thetaInput->setText(QString::number(newNode->getTheta(),'f',3));
}

void UINodeInfo::displayDescendNode(NodePoint *node){
    DescentNode *newNode = (DescentNode*)node;
    speedInput->setText(QString::number(newNode->getV(),'f',3));
    newHeightInput->setText(QString::number(newNode->getNewH(),'f',3));
    thetaInput->setText(QString::number(newNode->getTheta(),'f',3));
}

void UINodeInfo::displayCruiseNode(NodePoint *node){
    CruiseNode *newNode = (CruiseNode*)node;
    speedInput->setText(QString::number(newNode->getV(),'f',3));
}

void UINodeInfo::displayDemNode(NodePoint *node){
    DemNode *newNode = (DemNode*)node;
    speedInput->setText(QString::number(newNode->getV(),'f',3));
    azimuthInput->setText(QString::number(newNode->getAzim(),'f',3));
    zonLenInput->setText(QString::number(newNode->getLen(),'f',3));
    zonWidthInput->setText(QString::number(newNode->getWidth(),'f',3));

    if(dynamic_cast<ImgNode*>(node) != nullptr || dynamic_cast<DemNode*>(node) != nullptr){
        filePathInput->setText(newNode->getPath());
    }else{
        filePathInput->setText("");
    }
}

void UINodeInfo::displayImgNode(NodePoint *node){
    ImgNode *newNode = (ImgNode*)node;
    speedInput->setText(QString::number(newNode->getV(),'f',3));
    azimuthInput->setText(QString::number(newNode->getAzim(),'f',3));
    zonLenInput->setText(QString::number(newNode->getLen(),'f',3));
    zonWidthInput->setText(QString::number(newNode->getWidth(),'f',3));

    if(dynamic_cast<ImgNode*>(node) != nullptr || dynamic_cast<DemNode*>(node) != nullptr){
        filePathInput->setText(newNode->getPath());
    }else{
        filePathInput->setText("");
    }

}

void UINodeInfo::displayTakeOffNode(NodePoint *node){
    TakeoffNode *newNode = (TakeoffNode*)node;
    speedInput->setText(QString::number(newNode->getV(),'f',3));
}

void UINodeInfo::displayFinishNode(NodePoint *node){}

void UINodeInfo::displayTurnNode(NodePoint *node){
    TurnNode *newNode = (TurnNode*)node;
    speedInput->setText(QString::number(newNode->getV(),'f',3));
    turnRadiusInput->setText(QString::number(newNode->getR(),'f',3));
    psiInput->setText(QString::number(newNode->getPsi(),'f',3));
}

void UINodeInfo::displayMarkerNode(NodePoint *node){}

void UINodeInfo::hide(){
    nodeTypeLable->hide();
    nodeTypeInput->hide();

    latitudeLable->hide();
    latitudeInput->hide();

    longitudeLable->hide();
    longitudeInput->hide();

    heightLable->hide();
    heightInput->hide();

    speedLable->hide();
    speedInput->hide();

    newHeightLable->hide();
    newHeightInput->hide();

    thetaLable->hide();
    thetaInput->hide();

    turnRadiusLable->hide();
    turnRadiusInput->hide();

    psiLable->hide();
    psiInput->hide();

    zonLenLable->hide();
    zonLenInput->hide();

    zonWidthLable->hide();
    zonWidthInput->hide();

    azimuthLable->hide();
    azimuthInput->hide();

    filePathLable->hide();
    filePathInput->hide();

    segmentIdLable->hide();
    segmentIdInput->hide();

    saveButton->hide();
}

void UINodeInfo::show(){

    nodeTypeLable->show();
    nodeTypeInput->show();

    latitudeLable->show();
    latitudeInput->show();

    longitudeLable->show();
    longitudeInput->show();

    heightLable->show();
    heightInput->show();

    speedLable->show();
    speedInput->show();

    newHeightLable->show();
    newHeightInput->show();

    thetaLable->show();
    thetaInput->show();

    turnRadiusLable->show();
    turnRadiusInput->show();

    psiLable->show();
    psiInput->show();

    zonLenLable->show();
    zonLenInput->show();

    zonWidthLable->show();
    zonWidthInput->show();

    azimuthLable->show();
    azimuthInput->show();

    filePathLable->show();
    filePathInput->show();

    segmentIdLable->show();
    segmentIdInput->show();

    saveButton->show();
}

void UINodeInfo::clearInputs(){

    latitudeInput->setText("");
    longitudeInput->setText("");
    heightInput->setText("");
    speedInput->setText("");
    newHeightInput->setText("");
    thetaInput->setText("");
    turnRadiusInput->setText("");
    psiInput->setText("");
    zonLenInput->setText("");
    zonWidthInput->setText("");
    azimuthInput->setText("");
    filePathInput->setText("");
    segmentIdInput->setText("");
}
