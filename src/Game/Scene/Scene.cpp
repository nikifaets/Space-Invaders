#include "Scene.h"
#include <iostream>
#include "../SceneComponent/Bullet.h"
Scene::Scene(){

}

Scene::Scene(SDL_Renderer* renderer){

    this->renderer = renderer;
}

void Scene::loop(){

    SDL_Event event;


    while(event.type != SDL_QUIT){

		//draw black background
		SDL_SetRenderDrawColor(renderer, 0,0,0,255);
		SDL_RenderClear(renderer);

		handle_input(event);

		//let all components perform their updates

		for(int i=0; i<components.size(); i++){

			components[i]->loop();
		}

		//clear particles outside of the screen
		clear_components();

        //render all components in scene
        for(int i=0; i<components.size(); i++){

            render_component(components[i]);
        }

		SDL_PollEvent(&event);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);

    }

}

void Scene::add_player(SceneComponent* player){

	this->player = player;
	player->get_translation().print_vector();
	add_component(player);

}
void Scene::add_component(SceneComponent* component){

    components.push_back(component);
}

void Scene::render_component(SceneComponent* component){

	int opacity = 255;

	std::vector <std::vector <Vector3D> > display = component->get_sprite()->get_color_matrix();


	//We want to draw the element around its translation
	Vector2D pivot = component->get_translation();

	int start_offset_w = pivot.x - display.size()/2;
	int start_offset_h = pivot.y - display[0].size()/2;

	for(int i=0; i<display.size(); i++){

		
		for(int j=0; j<display[i].size(); j++){

			int pixel_i = start_offset_w + i;
			int pixel_j = start_offset_h + j;

			Vector3D pixel = display[i][j];

			SDL_SetRenderDrawColor(renderer, pixel.x, pixel.y, pixel.z, opacity);
			SDL_RenderDrawPoint(renderer, pixel_j, pixel_i);
		}
	}

}

void Scene::handle_input(SDL_Event &event){

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_W]) {
		
		player->translate(Vector2D(-5,0));
	}
	if (state[SDL_SCANCODE_S]) {

		player->translate(Vector2D(5,0));
	}

	if (state[SDL_SCANCODE_D]) {

		player->translate(Vector2D(0,5));
	}


	if (state[SDL_SCANCODE_A]) {

		player->translate(Vector2D(0,-5));
	}

	if(event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_SPACE){

		add_component(new Bullet(player->get_translation()));
	}

}
  
void Scene::clear_components(){

	for(int i=0; i<components.size(); i++){

		if(! is_on_screen(components[i])){

			if(components[i]->get_type() == Type::Particle){

				components.erase(components.begin()+i);
				//delete components[i];

			}
		}
	}
}

bool Scene::is_on_screen(SceneComponent* component){

	Vector2D pos = component->get_translation();

	if(pos.x > WIDTH || pos.x < 0) return false;
	if(pos.y > HEIGHT || pos.y < 0) return false;

	return true;
}