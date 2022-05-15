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
    drawing/item/node/DisplayedNode.cpp \
    drawing/item/node/DisplayedNodeCreator.cpp \
    drawing/item/segment/DisplayedSegment.cpp \
    drawing/item/segment/DisplayedSegmentCreator.cpp \
    drawing/item/wayPoint/DisplayedWayPoint.cpp \
    drawing/item/wayPoint/DisplayedWayPointCreator.cpp \
    drawing/layers/GeographicGridLayer.cpp \
    drawing/layers/LayerManager.cpp \
    drawing/layers/SelfDrawingLayer.cpp \
    drawing/layers/VisibleLayer.cpp \
    drawing/scene/ClicablePlaneScene.cpp \
    drawing/scene/ClicableScene.cpp \
    drawing/view/PlaneSimulationView.cpp \
    drawing/view/SimulationView.cpp \
    drawing/view/SimulationViewTest.cpp \
    drawing/view/maper/PlaneViewMapper.cpp \
    drawing/view/maper/ProfileViewMapper.cpp \
    drawing/view/maper/ViewMapper.cpp \
    main.cpp \
    settings/Settings.cpp \
    settings/SettingsManager.cpp \
    simulation/Simulation.cpp \
    simulation/SimulationReaderWriter.cpp \
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
    simulation/wayPoint/WayPoint.cpp \
    simulation/wayPoint/WayPointReaderWriter.cpp \
    test1.cpp \
    test2.cpp \
    utils/GeodesicUtils.cpp \
    utils/Utils.cpp \
    windows/CreateSimulationWindow.cpp \
    windows/SettingsWindow.cpp \
    windows/SimulationWindow.cpp \
    windows/StartWindow.cpp

HEADERS += \
    drawing/item/DisplayedItem.h \
    drawing/item/node/DisplayedNode.h \
    drawing/item/node/DisplayedNodeCreator.h \
    drawing/item/segment/DisplayedSegment.h \
    drawing/item/segment/DisplayedSegmentCreator.h \
    drawing/item/wayPoint/DisplayedWayPoint.h \
    drawing/item/wayPoint/DisplayedWayPointCreator.h \
    drawing/layers/GeographicGridLayer.h \
    drawing/layers/LayerManager.h \
    drawing/layers/SelfDrawingLayer.h \
    drawing/layers/VisibleLayer.h \
    drawing/scene/ClicablePlaneScene.h \
    drawing/scene/ClicableScene.h \
    drawing/view/PlaneSimulationView.h \
    drawing/view/SimulationView.h \
    drawing/view/SimulationViewTest.h \
    drawing/view/maper/PlaneViewMapper.h \
    drawing/view/maper/ProfileViewMapper.h \
    drawing/view/maper/ViewMapper.h \
    settings/Settings.h \
    settings/SettingsManager.h \
    simulation/Simulation.h \
    simulation/SimulationReaderWriter.h \
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
    simulation/node/NodePointType.h \
    simulation/node/TakeoffNode.h \
    simulation/node/TurnNode.h \
    simulation/segment/Segment.h \
    simulation/wayPoint/WayPoint.h \
    simulation/wayPoint/WayPointReadeRwriter.h \
    simulation/wayPoint/WayPointType.h \
    test1.h \
    test2.h \
    utils/GeodesicUtils.h \
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
