// things that i only need in main
// scout animation code
#include "src/game/scout.h"
// attacks and related functions
#include "src/attacks/attack.h"

#include "include.h"

#include <SDL.h>
#include <memory>
#include <iostream>
#include <string>

#include <time.h>

using std::string;
using std::unique_ptr;


int main(int argc, char ** argv) {

  bool quit = false;
  SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	unique_ptr<MASTER> mast(new MASTER());

  mast->window = SDL_CreateWindow(
		TITLE,
 		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		WIN_WIDTH, WIN_HEIGHT, 
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN
	);

	mast->renderer = SDL_CreateRenderer(mast->window, -1, SDL_RENDERER_ACCELERATED);

	
	// images
	// heart image
	unique_ptr<IMAGE> heart_img(new IMAGE(mast->renderer, ASSETPATH "interactable/heart.bmp"));
    // scout sprites
    unique_ptr<IMAGE> scout_head  (new IMAGE(mast->renderer, ASSETPATH "scout/head.bmp"));
    unique_ptr<IMAGE> scout_torso (new IMAGE(mast->renderer, ASSETPATH "scout/torso.bmp"));
    unique_ptr<IMAGE> scout_legs  (new IMAGE(mast->renderer, ASSETPATH "scout/legs.bmp"));

	// test entity system
	unique_ptr<IMAGE> scout_attack_test(new IMAGE(mast->renderer, ASSETPATH "attacks/cleaver.bmp"));

	// buttons
		// fight buttons
		// unselected
		unique_ptr<IMAGE> attack_button(new IMAGE(mast->renderer, ASSETPATH "interactable/buttons/fight/fight.bmp"));
		// selected
		unique_ptr<IMAGE> attack_button_selceted(new IMAGE(mast->renderer, ASSETPATH "interactable/buttons/fight/fight_selected.bmp"));
		
		// act
		// unselected
		unique_ptr<IMAGE> act_button(new IMAGE(mast->renderer, ASSETPATH "interactable/buttons/act/act.bmp"));
		// selected
		unique_ptr<IMAGE> act_button_selected(new IMAGE(mast->renderer, ASSETPATH "interactable/buttons/act/selected_act.bmp"));

	// gameplay objects
	unique_ptr<BOX> box(new BOX());
	unique_ptr<PLAYER> heart(new PLAYER());
	
	int scout_animation_cycle = 0;

	// attacks
	int attack = 1;

	// for animatining the scout on twos - every other frame is skipped
	bool twos = true;
	float twosCounter = 0.f;

	// master loop
  while (!quit) {

		if (crashMain) {
			return 1;
		}

		// repeat until all events are handled
  	for (; SDL_PollEvent(&event);) {

			// handles exiting event
			if (event.type == SDL_QUIT)
				quit = true;

			if (event.type == SDL_KEYDOWN || SDL_KEYUP) {
      	switch (event.key.keysym.sym) {
      	case SDLK_ESCAPE:
      	    quit = true;
      	    break;
      	default:
      	    break;
      	}

				switch (event.type) {
					case SDL_KEYDOWN:
						heart->syntax_compressor = true;
						break;
					case SDL_KEYUP:
						heart->syntax_compressor = false;
						break;
					default:
						break;
				}

				// handles keyboard events
				switch (event.key.keysym.sym) {
					case SDLK_UP:
						heart->h_move_up = heart->syntax_compressor;
						break;
					case SDLK_DOWN:
						heart->h_move_down = heart->syntax_compressor;
						break;
					case SDLK_RIGHT:
						heart->h_move_right = heart->syntax_compressor;
						break;
					case SDLK_LEFT:
						heart->h_move_left = heart->syntax_compressor;
						break;                        
					case SDLK_SPACE:
						scout_dodge = true;
						break;                                    
					default:
						break;
				}
			}
		}

		// clears the buffer for new things to be drawn.
		SDL_RenderClear(mast->renderer);

		heart->heartKeyHandler();
		box->drawBox(mast->renderer);

        // draws the undertale heart
		heart_img->renderScaledTexture(
			mast->renderer, 
			heart->heart_x, 
			heart->heart_y, 
			HEART_SIZE, HEART_SIZE
		);


		// does what the fn says
		animate_scout();
		// draws the scout piese's
		render_scout(
			mast->renderer,
			scout_head->returnTexture(),
			scout_torso->returnTexture(),
			scout_legs->returnTexture()
		);

		// draws the undertale buttons
		attack_button->renderTexture(
			mast->renderer,
			0, 0
		);
			

		// draws over the weird pixel in the corner of the heart for some reason
		SDL_SetRenderDrawColor(mast->renderer, 0, 0, 0, 255);
		SDL_RenderDrawPoint(mast->renderer, heart->heart_x + HEART_SIZE - 1, heart->heart_y + HEART_SIZE - 1);

		// makes the backround of the screen black
		SDL_SetRenderDrawColor(mast->renderer, 0, 0, 0, 255);

		// display things in the renderer buffer.
		SDL_RenderPresent(mast->renderer);

		// for the fps
		SDL_Delay((1000 / 30));

	}
	

  SDL_Quit();

	return 0;
}