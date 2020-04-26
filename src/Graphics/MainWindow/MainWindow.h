#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <SDL2/SDL.h>
#include <vector>
#include "../../Math/Vector/Vector3D.h"
#include "../Sprite/Sprite.h"
#include "../../Game/SceneComponent/SceneComponent.h"

class MainWindow{

    int height;
    int width;
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;

    public:

    MainWindow();
    MainWindow(int height_, int width_);
    SDL_Renderer* get_renderer();
    ~MainWindow();

  	void render_component(SceneComponent* component);
};

#endif