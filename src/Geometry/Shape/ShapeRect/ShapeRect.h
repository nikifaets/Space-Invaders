#ifndef SHAPE_RECT_H
#define SHAPE_RECT_H

#include "../Shape.h"

class ShapeRect : public Shape{


    int width;
    int height;

    public:

    ShapeRect(int width=10, int height=10);
    std::vector<std::vector<bool> > generate_points();
    Vector2D get_rect();
    
};
#endif