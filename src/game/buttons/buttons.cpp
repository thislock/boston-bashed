
#include "buttons.h"

const int fight_x = 0;
const int fight_y = 0;

const int act_x = 0;
const int act_y = 0;

const int item_x = 0;
const int item_y = 0;

const int mercy_x = 0;
const int mercy_y = 0;

// 1 for fight 2 for act, 3 for item, 4 for mercy
static int button_selected = 1;

void draw_buttons(
  SDL_Renderer * renderer,
  // fight button textures
  SDL_Texture * fight_unselected,
  SDL_Texture * fight_selected,
  // act button textures
  SDL_Texture * act_unselected,
  SDL_Texture * act_selected,
  // item button textures
  SDL_Texture * item_unselected,
  SDL_Texture * item_selected,
  // mercy button textures
  SDL_Texture * mercy_unselected,
  SDL_Texture * mercy_selected
) {

  if (button_selected == 1) {
    renderInputedTexture(
      renderer,
      fight_selected,
      fight_x, fight_y,
      100, 200
    );
  } else {
    renderInputedTexture(
      renderer,
      fight_selected,
      act_x, act_y,
      100, 200
    );
  }
  
}