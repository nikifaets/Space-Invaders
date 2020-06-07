#include "Bullet.h"
#include "../../Graphics/Sprite/Sprite.h"

const int Bullet::SPEED = 10;

Bullet::Bullet(Vector2D start_pos, int speed) : speed(speed){

    set_type(Particle);
    set_sprite(new Sprite(7));
    set_translation(start_pos);

}

void Bullet::loop(){

    translate(Vector2D(-1, 0).scale(speed));
}