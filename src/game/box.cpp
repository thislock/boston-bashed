
#include "box.h"

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

unique_ptr<FONT> font2(new FONT());

static bool Textinit = true;
void BOX::drawBoxText(
	SDL_Renderer * renderer,
	bool scout_turn
) {

	if (Textinit) {
		font2->setTexture(
			renderer,
			FONTPATH
		);
		Textinit = false;
	}

	if (!scout_turn) {
		font2->letter_seq(
			renderer,
			box_x + 20, box_y + 20,
			WIN_WIDTH / 70, WIN_HEIGHT / 70,
			"*you feel your sins"
		);

		font2->letter_seq(
			renderer,
			box_x + 20, box_y + 40,
			WIN_WIDTH / 70, WIN_HEIGHT / 70,
			" crawling on your back"
		);

	}
}