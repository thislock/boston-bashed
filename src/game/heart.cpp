
#include <SDL.h>
#include <iostream>
#include "../../include.h"


void PLAYER::heartKeyHandler() {

  // controls the movment variables
	if (h_move_up)
		heart_y -= heart_velocity;
	if (h_move_down)
		heart_y += heart_velocity;
	if (h_move_left)
		heart_x -= heart_velocity;
	if (h_move_right)
		heart_x += heart_velocity;
		
}