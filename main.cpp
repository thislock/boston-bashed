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
		WIN_WIDTH, WIN_HEIGHT, NULL
	);

	mast->renderer = SDL_CreateRenderer(mast->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	// images
	// heart image
	unique_ptr<IMAGE> heart_img(new IMAGE(mast->renderer, ASSETPATH "interactable/heart.bmp"));
    // scout sprites
    unique_ptr<IMAGE> scout_head  (new IMAGE(mast->renderer, ASSETPATH "scout/head.bmp"));
    unique_ptr<IMAGE> scout_torso (new IMAGE(mast->renderer, ASSETPATH "scout/torso.bmp"));
    unique_ptr<IMAGE> scout_legs  (new IMAGE(mast->renderer, ASSETPATH "scout/legs.bmp"));


	// gameplay objects
	unique_ptr<BOX> box(new BOX());
	unique_ptr<PLAYER> heart(new PLAYER());

	std::cout << head_x - (WIN_WIDTH / 2) << '\n' << torso_x << '\n';
	
	int scout_animation_cycle = 0;

	// attacks
	int attack = 1;

	// for animatining the scout on twos - every other frame is skipped
	bool twos = true;
	float twosCounter = 0.f;

	// makes the game run SLIGHTLY smoother by dialing down the delay between frames if there is a lag spike
	int time_keeper_init;
	int time_keeper_final;

	// master loop
  while (!quit) {

		// starts time before anything is processed
		time_keeper_init = time(NULL) * 1000;

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
		animate_scout(box->boxSize);
		// draws the scout piese's
		render_scout(
			mast->renderer,
			scout_head->returnTexture(),
			scout_torso->returnTexture(),
			scout_legs->returnTexture()
		);
			

		// draws over the weird pixel in the corner of the heart for some reason
		SDL_SetRenderDrawColor(mast->renderer, 0, 0, 0, 255);
		SDL_RenderDrawPoint(mast->renderer, heart->heart_x + HEART_SIZE - 1, heart->heart_y + HEART_SIZE - 1);

		// makes the backround of the screen black
		SDL_SetRenderDrawColor(mast->renderer, 0, 0, 0, 255);

		// display things in the renderer buffer.
		SDL_RenderPresent(mast->renderer);

		// for the fps
		time_keeper_final = (time(NULL) * 1000) - time_keeper_init;
		SDL_Delay((1000 / 30));

	}
	

  SDL_Quit();

	return 0;
}