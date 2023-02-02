
#include <SDL.h>
#include <iostream>
#include "../../include.h"


void PLAYER::heartKeyHandler() {

  // controls the movment variables
	if (h_move_up && heart_y > ((WIN_HEIGHT / 2) + (boxSize / 5)))
		heart_y -= heart_velocity;
	if (h_move_down && heart_y < ((WIN_HEIGHT / 2) - (BOX_THICCNESS * 4)) + boxSize)
		heart_y += heart_velocity;
	if (h_move_left && heart_x > ((WIN_WIDTH / 2) - boxSize) + BOX_THICCNESS * 2)
		heart_x -= heart_velocity;
	if (h_move_right && heart_x < ((WIN_WIDTH / 2) + boxSize) - BOX_THICCNESS * 4)
		heart_x += heart_velocity;
		
}