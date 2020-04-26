#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow(){}
MainWindow::MainWindow(int height_, int width_) : height(height_), width(width_){

	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	}

MainWindow::~MainWindow(){

	std::cout << "destruct " << std::endl;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Renderer* MainWindow::get_renderer(){

	return this->renderer;
}
