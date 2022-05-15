#ifndef NODEPOINTTYPE_H
#define NODEPOINTTYPE_H

#include <QObject>


namespace NP{
    Q_NAMESPACE
    enum NodePointType : int {
        UNDEFINED_NODE,
        TAKEOFF_NODE,
        FINISH_NODE,
        TURN_NODE,
        EVENT_NODE,
        CLIMB_NODE,
        DESCENT_NODE,
        CRUISE_NODE,
        MARKER_NODE,
        IMG_NODE,
        DEM_NODE
    };
    Q_ENUM_NS(NodePointType);
};

#endif // NODEPOINTTYPE_H
