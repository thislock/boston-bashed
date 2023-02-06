#ifndef BUTTONS_H
#define BUTTONS_H

#include <SDL.h>

namespace buttons {
  static int fight_x;
  static int fight_y;

  static int act_x;
  static int act_y;
  
  static int act_y;
}

void render_fight(SDL_Renderer * renderer);

#endif // BUTTONS_H