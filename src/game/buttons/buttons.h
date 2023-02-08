#ifndef BUTTONS_H
#define BUTTONS_H

#pragma once

#include <SDL.h>

#include "../scout.h"

void draw_buttons(
  SDL_Renderer * renderer,
  // fight button textures
  SDL_Texture * fight_unselected,
  SDL_Texture * fight_selected,
  // item button textures
  SDL_Texture * item_unselected,
  SDL_Texture * item_selected,
  // act button textures
  SDL_Texture * act_unselected,
  SDL_Texture * act_selected,
  // mercy button textures
  SDL_Texture * mercy_unselected,
  SDL_Texture * mercy_selected
);

#endif // BUTTONS_H