#ifndef SHAPE_H
#define SHAPE_H

#include "../../Math/Vector/Vector2D.h"
#include <vector>

class Shape{


    Vector2D pivot;

    public:

    Shape();
    Shape(Vector2D pivot);

    void set_pivot(Vector2D pivot);
    Vector2D get_pivot();
    virtual std::vector<std::vector<bool> > generate_points() = 0;    

};

#endif