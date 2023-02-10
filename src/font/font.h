#ifndef FONT_H
#define FONT_H

#pragma once

#include "../rendering/rendering.h"
#include <SDL.h>

class FONT : public IMAGE {

public:

  void render_letter(
    SDL_Renderer * renderer,
    char charecter
  );

private:

  SDL_Rect clips[4];

};


#endif // FONT_H