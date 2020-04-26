#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <SDL2/SDL.h>

class MainWindow{

public:

    MainWindow(int height_, int width_);

    ~MainWindow();

  	void render_display();

private:

    int height;
    int width;
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
};

#endif