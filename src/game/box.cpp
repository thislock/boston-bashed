
#include <SDL.h>
#include "../../include.h"

void BOX::drawBox(SDL_Renderer * renderer) {
  // renders the undertale box thing
	// sets the draw color to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	for (int i = 0; i < BOX_THICCNESS; i++) {
		// top horazontal line
		SDL_RenderDrawLine(renderer, (WIN_WIDTH / 2) - boxSize, (WIN_HEIGHT / 2 + (boxSize / 5)) - i, (WIN_WIDTH / 2) + boxSize, (WIN_HEIGHT / 2 + (boxSize / 5)) - i);
		// bottom horzontal line
		SDL_RenderDrawLine(renderer, (WIN_WIDTH / 2) - boxSize, ((WIN_HEIGHT / 2) - i) + boxSize, (WIN_WIDTH / 2) + boxSize, ((WIN_HEIGHT / 2) - i) + boxSize);
		
    // left vertical line
		SDL_RenderDrawLine(renderer, ((WIN_WIDTH / 2) - boxSize) + i, WIN_HEIGHT / 2 + (boxSize / 5), ((WIN_WIDTH / 2) - boxSize) + i, (WIN_HEIGHT / 2) + boxSize);
		// right vertical line`
		SDL_RenderDrawLine(renderer, ((WIN_WIDTH / 2) + boxSize) - i, WIN_HEIGHT / 2 + (boxSize / 5), ((WIN_WIDTH / 2) + boxSize) - i, (WIN_HEIGHT / 2) + boxSize);
	}
}