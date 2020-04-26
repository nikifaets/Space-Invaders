// Example program:
// Using SDL2 to create an application window

#include "SDL2/SDL.h"
#include "Math/Vector/Vector3D.h"
#include "Graphics/Sprite/Sprite.h"
#include "Geometry/Shape/Shape.h"
#include "Geometry/Shape/ShapeRect/ShapeRect.h"
#include "Game/Scene/Scene.h"
#include "Graphics/MainWindow/MainWindow.h"
#include <iostream>
using namespace std;

int main() {

    //Create window
    MainWindow window(480, 640);
    SDL_Renderer* renderer = window.get_renderer();

    //Create scene
    Scene scene(renderer);

    //Create main player
    Sprite player_texture(5);
    SceneComponent player;

    player.set_sprite(&player_texture);
    player.set_translation(Vector2D(200,300));

    //Add player to scene
    scene.add_player(&player);

    //Start main loop
    scene.loop();
    

    return 0;
}