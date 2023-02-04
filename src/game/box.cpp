
#include <SDL.h>
#include "../../include.h"

void BOX::drawBox(SDL_Renderer * renderer) {
  // renders the undertale box thing
	// sets the draw color to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int i = 0; i < BOX_THICCNESS; i++) {
		// top horazontal line
		SDL_RenderDrawLine(
			renderer, 
			box_x, box_y + i, 
			box_x + box_width, box_y + i
		);
		// bottom horazontal line
		SDL_RenderDrawLine(
			renderer, 
			box_x, (box_y + box_height) - i,
			box_x + box_width, (box_y + box_height) - i
		);

		// left vertical line
		SDL_RenderDrawLine(
			renderer, 
			box_x + i, box_y, 
			box_x + i, box_y + box_height
		);
		// right vertical line
		SDL_RenderDrawLine(
			renderer, 
			(box_x + box_width) - i, box_y, 
			(box_x + box_width) - i, box_y + box_height
		);
	}
}