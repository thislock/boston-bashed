#ifndef BUTTONS_H
#define BUTTONS_H

#pragma once

#include <SDL.h>
#include "../../rendering/rendering.h"
#include "../scout.h"
#include "../../superfile.h"

class BUTTONS {

public:

  // for printing out your items and such when you press a button (0 for none pressed)
  int button_pressed = 0;

  // for what button you are currently hovering over
  int button_selected = 1;

  // misc essential variables
  bool button_delay = false;
  bool scout_turn = true;
  bool scout_dodge = false;
  bool enterMenu = false;

  // all events related to pressing one of the buttons
  void button_pressed_events(
    SDL_Renderer * renderer,
    int box_x, int box_y
  );

  // pretty self explanitory
  void draw_buttons(SDL_Renderer * renderer);

};

#endif // BUTTONS_H