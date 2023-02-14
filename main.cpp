

// things that i only need in main
// scout animation code
#include "src/game/scout.h"
// attacks and related functions
#include "src/attacks/attack.h"

// for undertale buttons
#include "src/game/buttons/buttons.h"

// for fonting
#include "src/font/font.h"

#include "include.h"

#include <stdlib.h>
#include <memory>
#include <iostream>
#include <string>
#include <SDL.h>

#include <time.h>

using std::string;
using std::unique_ptr;


int main(int argc, char ** argv) {

  bool quit = false;
  SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Init(SDL_INIT_AUDIO);

	unique_ptr<MASTER> mast(new MASTER());

	SDL_Window * cover_window = SDL_CreateWindow(
		"dont mind me.",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP
	);
	
	SDL_Renderer * cover_window_renderer = SDL_CreateRenderer(cover_window, -1, SDL_RENDERER_ACCELERATED);
	
	SDL_SetRenderDrawColor(cover_window_renderer, 0, 0, 0, 255);
	SDL_RenderPresent(cover_window_renderer);

  mast->window = SDL_CreateWindow(
		TITLE,
 		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		WIN_WIDTH, WIN_HEIGHT, 
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS
	);

	mast->renderer = SDL_CreateRenderer(mast->window, -1, SDL_RENDERER_ACCELERATED);


	// images
	// heart image
	unique_ptr<IMAGE> heart_img(new IMAGE(mast->renderer, ASSETPATH "interactable/heart.bmp"));
    // scout sprites
    unique_ptr<IMAGE> scout_head  (new IMAGE(mast->renderer, ASSETPATH "scout/head.bmp"));
    unique_ptr<IMAGE> scout_torso (new IMAGE(mast->renderer, ASSETPATH "scout/torso.bmp"));
    unique_ptr<IMAGE> scout_legs  (new IMAGE(mast->renderer, ASSETPATH "scout/legs.bmp"));
		// alternate scout sprites
    unique_ptr<IMAGE> scout_raised_hands_torso(new IMAGE(mast->renderer, ASSETPATH "scout/alternate_parts/hand-raised-torso.bmp"));
    unique_ptr<IMAGE> scout_winking_head(new IMAGE(mast->renderer, ASSETPATH "scout/alternate_parts/winking-head.bmp"));
		

	// holds the states of the body parts (if a differnt texture is needed to be rendered)
	SDL_Texture * head_state;
	SDL_Texture * torso_state;
	SDL_Texture * legs_state;

	// test entity system
	unique_ptr<IMAGE> scout_attack_test(new IMAGE(mast->renderer, ASSETPATH "attacks/cleaver.bmp"));


	// gameplay objects
	unique_ptr<BOX> box(new BOX());
	unique_ptr<PLAYER> heart(new PLAYER());
	unique_ptr<BUTTONS> buttons(new BUTTONS());


	unique_ptr<SCOUT> scout(new SCOUT());


	// create sound
	unique_ptr<SOUND> scout_attack_sound(new SOUND(SOUNDPATH "hit_sound.wav"));

	

	int scout_animation_cycle = 0;

	// font for letters and stuff
	unique_ptr<FONT> font(new FONT());
	font->setTexture(mast->renderer, ASSETPATH "font.bmp");

	srand(time(NULL));

	// master loop
  while (!quit) {

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
						buttons->button_delay = true;
						break;
					case SDL_KEYUP:
						
						// if your pressing z and your on the fight button
						if (buttons->button_pressed == 1 && event.key.keysym.sym == SDLK_z) {
							buttons->scout_turn = true;
							buttons->scout_dodge = true;
							scout->scout_dodge = true;
							scout_attack_sound->playsound();
						}

						// if the z key is up
						if (event.key.keysym.sym == SDLK_z) {
							buttons->enterMenu = true;
						}
						buttons->button_delay = false;
						heart->syntax_compressor = false;
						break;
					default:
						break;
				}

				// handles keyboard events
				switch (event.key.keysym.sym) {
					
					case SDLK_UP:
						if (buttons->scout_turn) {
							heart->h_move_up = heart->syntax_compressor;
						}
						break;
					case SDLK_DOWN:
						if (buttons->scout_turn) {
							heart->h_move_down = heart->syntax_compressor;
						}
						break;
					case SDLK_RIGHT:
						if (!buttons->scout_turn && !buttons->enterMenu && buttons->button_delay) {
							buttons->button_selected++;
						} else if (buttons->scout_turn) {
							heart->h_move_right = heart->syntax_compressor;
						}
						break;
					case SDLK_LEFT:
					  if (!buttons->scout_turn && !buttons->enterMenu && buttons->button_delay) {
							buttons->button_selected--;
						} else if (buttons->scout_turn) {
							heart->h_move_left = heart->syntax_compressor;
						}
						break;
				
                                  
					default:
						break;

				}
			}
		}


		// clears the buffer for new things to be drawn.
		SDL_RenderClear(mast->renderer);
		SDL_RenderClear(cover_window_renderer);

		// draws the box
		box->drawBox(mast->renderer);

		// draws the text for the box
		box->drawBoxText(mast->renderer, buttons->scout_turn);

		// handles the heart's position changes
		heart->heartKeyHandler();

    // draws the undertale heart if its scouts turn
		if (buttons->scout_turn)
		heart_img->renderScaledTexture(
			mast->renderer, 
			heart->heart_x, 
			heart->heart_y, 
			HEART_SIZE, HEART_SIZE
		);

		// handles things like the text after the button is pressed
		buttons->button_pressed_events(
			mast->renderer,
			box->box_x,
			box->box_y
		);
		if (buttons->enterMenu) {
			
			if (buttons->button_selected == 1) {
				buttons->button_pressed = 1;
				font->letter_seq(
					mast->renderer,
					box->box_x + 20,
					box->box_y + 20,
					50, 50,
					"*scout"
				);
			}

			buttons->enterMenu = false;
		}

		// does what the fn says
		scout->animate_scout();

		// sets what scout texture to draw
		if (scout->scout_dodge) {
			head_state = scout_winking_head->returnTexture();
		} else {
			head_state = scout_head->returnTexture();
		}
		torso_state = scout_torso->returnTexture();
		legs_state = scout_legs->returnTexture();

		// draws the scout piese's
		scout->render_scout(
			mast->renderer,
			head_state, 
			torso_state,
			legs_state
		);

		// draws the undertale buttons
		buttons->draw_buttons(
			mast->renderer
		);

		// renders all things that can damage the	heart
		attacks(mast->renderer, heart->heart_x, heart->heart_y, 1, buttons->scout_turn);

		// draws over the weird pixel in the corner of the heart for some reason
		SDL_SetRenderDrawColor(mast->renderer, 0, 0, 0, 255);
		SDL_RenderDrawPoint(mast->renderer, heart->heart_x + HEART_SIZE - 1, heart->heart_y + HEART_SIZE - 1);

		// makes the backround of the screen black
		SDL_SetRenderDrawColor(mast->renderer, 0, 0, 0, 255);

		// display things in the renderer buffer.
		SDL_RenderPresent(mast->renderer);

		SDL_SetRenderDrawColor(cover_window_renderer, 0, 0, 0, 255);
		SDL_RenderPresent(cover_window_renderer);

		// for the fps
		SDL_Delay((1000 / 30));

	}

	SDL_DestroyTexture(head_state);
	SDL_DestroyTexture(torso_state);
	SDL_DestroyTexture(legs_state);

  SDL_Quit();

	SDL_DestroyRenderer(cover_window_renderer);
	SDL_DestroyWindow(cover_window);

	return 0;
}
