
#include <SDL.h>
#include <iostream>
#include "../../include.h"

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