#pragma once
#include "SceneComponent.h"

class Bullet : public SceneComponent{

    static const int SPEED;
    int speed;

    public:

    Bullet(Vector2D start_pos, int speed=SPEED);
    void loop();
};