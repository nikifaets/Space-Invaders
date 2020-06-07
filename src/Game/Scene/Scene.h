#ifndef SCENE_H
#define SCENE_H

#include "../../Graphics/Sprite/Sprite.h"
#include "../SceneComponent/SceneComponent.h"
#include "SDL2/SDL.h"

class Scene{

    static const int WIDTH = 640;
    static const int HEIGHT = 480;

    std::vector<SceneComponent*> components;
    SceneComponent* player;

    const int win_height = 480;
    const int win_width = 640;

    SDL_Renderer* renderer;

    void handle_input(SDL_Event& event);
    void render_component(SceneComponent* component);
    bool is_on_screen(SceneComponent* component);
    void clear_components();
    
    public:

        Scene();
        Scene(SDL_Renderer* renderer);

        void render();
        void add_component(SceneComponent* component);
        void add_player(SceneComponent* player);
        void set_background(Sprite background);
        void loop();


};
#endif