#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPen>

class Settings{
public:
    Settings();

    QString grid_line_color;
    int grid_line_size;
    int lines_in_grid;

    double segment_width;
    QString segment_color;

    double node_point_radius;
    QString node_point_color;
    QString node_point_desc_font;
    QString node_point_desc_color;

    double way_point_radius;
    QString way_point_color;
    QString way_point_desc_font;
    QString way_point_desc_color;

public:
    // properties name in file
    const QString LINES_NUMBER = "grid lines number";
    const QString GRID_LINE_COLOR = "grid lines color";
    const QString GRID_LINE_SIZE = "grid lines size";

    const QString SEGMENT_WIDTH = "segment width";
    const QString SEGMENT_COLOR = "segment color";

    const QString NODE_POINT_RADIUS = "node point radius";
    const QString NODE_POINT_COLOR = "node point color";
    const QString NODE_POINT_DESC_FONT = "node point desc font";
    const QString NODE_POINT_DESC_COLOR = "node point desc color";

    const QString WAY_POINT_RADIUS = "way point radius";
    const QString WAY_POINT_COLOR = "way point color";
    const QString WAY_POINT_DESC_FONT = "way point desc font";
    const QString WAY_POINT_DESC_COLOR = "way point desc color";
};

#endif // SETTINGS_H
