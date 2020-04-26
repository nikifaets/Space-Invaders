#include "ShapeRect.h"
#include <iostream>

ShapeRect::ShapeRect(int width, int height){

    this->width = width;
    this->height = height;
}

std::vector<std::vector<bool> > ShapeRect::generate_points(){

    std::vector<std::vector<bool> > rect;

    for(int i=0; i<height; i++){

        rect.push_back(std::vector<bool>());
        
        for(int j=0; j<width; j++){

            rect[i].push_back(true);
        }
    }

    return rect;
    
}

Vector2D ShapeRect::get_rect(){

    return Vector2D(height, width);
}