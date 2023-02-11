#ifndef FONT_H
#define FONT_H

#pragma once

#include "../rendering/rendering.h"
#include <SDL.h>

class FONT : public IMAGE {

public:

  void letter(
    SDL_Renderer * renderer,
    int x, int y,
    int letter
  );

private:

  int clips[4];

};


#endif // FONT_H