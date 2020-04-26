#ifndef SPRITE_H
#define SPRITE_H

#include "../../Geometry/Shape/Shape.h"
#include "../../Math/Vector/Vector3D.h"
#include "../../Geometry/Shape/ShapeRect/ShapeRect.h"
#include <vector>

class Sprite{

    Shape* shape;
    Vector3D color;

    public:

    Sprite();
    Sprite(ShapeRect* rect, Vector3D color = Vector3D(255,255,255));
    std::vector<std::vector<Vector3D> > get_color_matrix();


};

#endif