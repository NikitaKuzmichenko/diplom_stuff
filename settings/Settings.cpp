#include "Settings.h"

Settings::Settings(){
    this->grid_line_color = QString("Black");
    this->grid_line_size = 2;
    this->lines_in_grid = 3;
}


int Settings::getGrid_line_size(){
    return grid_line_size;
}

void Settings::setGrid_line_size(int value){
    grid_line_size = value;
}

int Settings::getLines_in_grid(){
    return lines_in_grid;
}

void Settings::setLines_in_grid(int value){
    lines_in_grid = value;
}

QString Settings::getGrid_line_color(){
    return grid_line_color;
}

void Settings::setGrid_line_color(QString value){
    grid_line_color = value;
}
