
#include <SDL.h>
#include <iostream>
#include "../../include.h"
using std::unique_ptr;

// box y and height of undertale box
const int BOX_Y = (((WIN_HEIGHT / 2) + (WIN_HEIGHT / 11)) + (BOX_THICCNESS * 2));
const int BOX_HEIGHT = (WIN_HEIGHT / 2) - (BOX_Y / 2);
// x and width of undertale box
const int BOX_X = WIN_WIDTH / 5;
const int BOX_WIDTH = WIN_WIDTH - (BOX_X * 2);

void PLAYER::heartKeyHandler() {

  // controls the movment variables
	if (h_move_up && heart_y > BOX_Y)
		heart_y -= heart_velocity;
	if (h_move_down && heart_y < (BOX_Y + BOX_HEIGHT) - (BOX_THICCNESS * 5))
		heart_y += heart_velocity;
	if (h_move_left && heart_x > BOX_X + (BOX_THICCNESS * 2))
		heart_x -= heart_velocity;
	if (h_move_right && heart_x < (BOX_X + BOX_WIDTH) - (BOX_THICCNESS * 4))
		heart_x += heart_velocity;
		
}

void PLAYER::health_bar(SDL_Renderer * renderer, bool & game_over) {
	for (int i = 0; i < 15; i++) {
		// set color red
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		// draws absence of health
		SDL_RenderDrawLine(
			renderer, 
			(WIN_WIDTH / 2) + WIN_WIDTH / 20, 
			(WIN_HEIGHT / 2) + ((WIN_HEIGHT * 4) / 13) + i,
			((WIN_WIDTH / 2) + (WIN_WIDTH / 20)) + (MAX_HP * 2),
			(WIN_HEIGHT / 2) + ((WIN_HEIGHT * 4) / 13) + i
		);
		// set color orange
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		// draw fullness of health bar
		SDL_RenderDrawLine(
			renderer, 
			(WIN_WIDTH / 2) + WIN_WIDTH / 20,
			(WIN_HEIGHT / 2) + ((WIN_HEIGHT * 4) / 13) + i,
			((WIN_WIDTH / 2) + (WIN_WIDTH / 20)) + (HP * 2),
			(WIN_HEIGHT / 2) + ((WIN_HEIGHT * 4) / 13) + i
		);
	}
	if (HP < 1)
		game_over = true;

	// reset color to black
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
