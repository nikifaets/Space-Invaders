#include "Sprite.h"
#include <iostream>

Sprite::Sprite(){

    this->shape = new ShapeRect();
}

Sprite::Sprite(ShapeRect* rect, Vector3D color){

    this->shape = rect;
    this->color = color;
}

std::vector<std::vector< Vector3D> > Sprite::get_color_matrix(){

    std::vector<std::vector<bool> > shape_points = shape->generate_points();
    
    int height = shape_points.size();
    int width = shape_points[0].size();


    std::vector<std::vector<Vector3D> > texture(height);
    for(int i=0; i<height; i++){


        for(int j=0; j<width; j++){

            texture[i].push_back(Vector3D());
            texture[i][j] = null_vector_3d;

            if(shape_points[i][j]){

                texture[i][j] = this->color;
            }

        }
    }

    return texture;
}