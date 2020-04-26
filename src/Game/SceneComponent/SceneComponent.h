#ifndef SCENE_COMPONENT_H
#define SCENE_COMPONENT_H

#include "../../Graphics/Sprite/Sprite.h"

class SceneComponent{

    Sprite* sprite;
    Vector2D translation;

    public:

    Sprite* get_sprite();
    void set_sprite(Sprite* sprite);
    void set_translation(Vector2D translation);
    Vector2D get_translation();
    void translate(Vector2D translation);
};

#endif