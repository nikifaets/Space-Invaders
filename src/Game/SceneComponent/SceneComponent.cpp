#include "SceneComponent.h"
#include <iostream>

Sprite* SceneComponent::get_sprite(){

    return this->sprite;
}

void SceneComponent::set_sprite(Sprite* sprite){

    this->sprite = sprite;
}
void SceneComponent::set_translation(Vector2D translation){

    this->translation = translation;
}

Vector2D SceneComponent::get_translation(){

    return this->translation;
}

void SceneComponent::translate(Vector2D translation){

    this->translation = this->translation + translation;
}
