#ifndef SETTINGS_H
#define SETTINGS_H

#include <QPen>

class Settings{
public:
    Settings();

    QString getGrid_line_color();
    void setGrid_line_color(QString value);

    int getGrid_line_size();
    void setGrid_line_size(int value);

    int getLines_in_grid();
    void setLines_in_grid(int value);

private:
    QString grid_line_color;
    int grid_line_size;
    int lines_in_grid;

public:
    // properties name in file
    const QString LINES_NUMBER = "grid lines number";
    const QString GRID_LINE_COLOR = "grid lines color";
    const QString GRID_LINE_SIZE = "grid lines size";

};

#endif // SETTINGS_H
