// Example program:
// Using SDL2 to create an application window

#include "SDL2/SDL.h"
#include "Math/Vector/Vector3D.h"
#include "Graphics/Sprite/Sprite.h"
#include "Geometry/Shape/Shape.h"
#include "Geometry/Shape/ShapeRect/ShapeRect.h"

#include <iostream>
using namespace std;

int main() {

    ShapeRect rect;
    Shape* shape;

    Vector2D rect_size = rect.get_rect();
    rect_size.print_vector();

    shape = &rect;
    
    Sprite sprite(&rect);
    std::vector<std::vector<Vector3D> > txt = sprite.get_color_matrix();

    cout << txt.size();
    return 0;
}