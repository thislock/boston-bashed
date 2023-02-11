#ifndef FONT_H
#define FONT_H

#pragma once


#include "../rendering/rendering.h"
#include <SDL.h>

#include <string>

#define FONTPATH "../assets/font.bmp"

class FONT : public IMAGE {

public:

  void letter(
    SDL_Renderer * renderer,
    int x, int y,
    int width, int height,
    char letter
  );

  void letter_seq(
    SDL_Renderer * renderer,
    int x, int y,
    int width, int height,
    std::string sentance
  );

private:

  int clips[4];

};


#endif // FONT_H