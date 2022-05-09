QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    drawing/item/DisplayedItem.cpp \
    drawing/item/line/DisplayedSegment.cpp \
    drawing/item/line/SegmentCreator.cpp \
    drawing/item/point/DisplayedNodePoint.cpp \
    drawing/item/point/NodeCreator.cpp \
    drawing/layers/GeographicGridLayer.cpp \
    drawing/layers/LayerManager.cpp \
    drawing/layers/SelfDrawingLayer.cpp \
    drawing/layers/VisibleLayer.cpp \
    drawing/view/ClickablePlane.cpp \
    drawing/view/SimulationView.cpp \
    drawing/view/maper/PlaneViewMapper.cpp \
    drawing/view/maper/ViewMapper.cpp \
    main.cpp \
    settings/Settings.cpp \
    settings/SettingsManager.cpp \
    simulation/Simulation.cpp \
    simulation/map/ElevationMap.cpp \
    simulation/map/PhysicalPoint.cpp \
    simulation/node/ClimbNode.cpp \
    simulation/node/CruiseNode.cpp \
    simulation/node/DemNode.cpp \
    simulation/node/DescentNode.cpp \
    simulation/node/FinishNode.cpp \
    simulation/node/ImgNode.cpp \
    simulation/node/MarkerNode.cpp \
    simulation/node/NodePoint.cpp \
    simulation/node/NodePointReaderWriter.cpp \
    simulation/node/TakeoffNode.cpp \
    simulation/node/TurnNode.cpp \
    simulation/segment/Segment.cpp \
    utils/Utils.cpp \
    windows/CreateSimulationWindow.cpp \
    windows/SettingsWindow.cpp \
    windows/SimulationWindow.cpp \
    windows/StartWindow.cpp

HEADERS += \
    drawing/item/DisplayedItem.h \
    drawing/item/line/DisplayedSegment.h \
    drawing/item/line/SegmentCreator.h \
    drawing/item/point/DisplayedNodePoint.h \
    drawing/item/point/NodeCreator.h \
    drawing/layers/GeographicGridLayer.h \
    drawing/layers/LayerManager.h \
    drawing/layers/SelfDrawingLayer.h \
    drawing/layers/VisibleLayer.h \
    drawing/view/ClickablePlane.h \
    drawing/view/SimulationView.h \
    drawing/view/maper/PlaneViewMapper.h \
    drawing/view/maper/ViewMapper.h \
    settings/Settings.h \
    settings/SettingsManager.h \
    simulation/Simulation.h \
    simulation/map/ElevationMap.h \
    simulation/map/PhysicalPoint.h \
    simulation/node/ClimbNode.h \
    simulation/node/CruiseNode.h \
    simulation/node/DemNode.h \
    simulation/node/DescentNode.h \
    simulation/node/FinishNode.h \
    simulation/node/ImgNode.h \
    simulation/node/MarkerNode.h \
    simulation/node/NodePoint.h \
    simulation/node/NodePointReaderWriter.h \
    simulation/node/TakeoffNode.h \
    simulation/node/TurnNode.h \
    simulation/segment/Segment.h \
    utils/Utils.h \
    windows/CreateSimulationWindow.h \
    windows/SettingsWindow.h \
    windows/SimulationWindow.h \
    windows/StartWindow.h

FORMS += \
    windows/CreateSimulationWindow.ui \
    windows/SettingsWindow.ui \
    windows/SimulationWindow.ui \
    windows/StartWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
